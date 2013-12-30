#include <stdio.h>
#include <stdlib.h>
#include "gumbo.h"

void search_for_links(GumboNode* node);

void search_for_links(GumboNode* node)
{
	if (node->type != GUMBO_NODE_ELEMENT) { return; }
	GumboAttribute* href;
	GumboAttribute* name;
	char *hrefstr = NULL;
	char *hrefname = NULL;
	if (node->v.element.tag == GUMBO_TAG_A && (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) 
	{
		hrefstr=href->value;
	}
	
	if (node->v.element.tag == GUMBO_TAG_A && (name = gumbo_get_attribute(&node->v.element.attributes, "ref"))) 
	{
		hrefname=name->value;
	}
	if(hrefname != NULL && hrefstr != NULL)
	{
		printf("[%s] %s \n",hrefname,hrefstr);
	}else if(hrefstr != NULL)
	{
		printf("%s\n",hrefstr);
	}

	GumboVector* children = &node->v.element.children;
	for (unsigned int i = 0; i < children->length; ++i) {
		search_for_links((GumboNode*)(children->data[i]));
	}
}


int main(int argc,char * argv[])
{
	if (argc != 2) {
		printf("Usage: find_links <html filename>.\n");
		exit(EXIT_FAILURE);
	}
	const char* filename = argv[1];

	FILE *fp = fopen(filename,"rb");
        size_t sz;
        char *buff;
        fseek(fp, 0, SEEK_END);  
        sz = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        buff = (char *)malloc(sizeof(char)*sz);
        fread(buff,sz,1,fp); // read all data
	
	GumboOutput* output = gumbo_parse(buff);
        search_for_links(output->root);
        gumbo_destroy_output(&kGumboDefaultOptions, output);
        
        free(buff);
        fclose(fp);

	return 0;
}


