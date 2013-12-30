# src/

# include settings
#INCLUDE_DIRECTORIES(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/lib)
#INCLUDE_DIRECTORIES(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/lib/include)
INCLUDE_DIRECTORIES(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include)

# lib settings
LINK_DIRECTORIES(${${CMAKE_PROJECT_NAME}_BINARY_DIR}/lib)


# all related files
AUX_SOURCE_DIRECTORY(. DIR_TARGET)
ADD_LIBRARY (relfiles ${DIR_TARGET})


# get clean text

ADD_EXECUTABLE(clean_text clean_text.cc)

#  executable dependencies
ADD_DEPENDENCIES(clean_text gumbo)
#ADD_DEPENDENCIES(clean_text cjson)

#  executable target links
TARGET_LINK_LIBRARIES(clean_text relfiles)
#TARGET_LINK_LIBRARIES(clean_text cjson)
TARGET_LINK_LIBRARIES(clean_text gumbo)

#  executable properties
SET_TARGET_PROPERTIES(clean_text PROPERTIES OUTPUT_NAME "clean_text")

# get all links

ADD_EXECUTABLE(find_links find_links.cc)

#  executable dependencies
ADD_DEPENDENCIES(find_links gumbo)
#ADD_DEPENDENCIES(find_links cjson)

#  executable target links
TARGET_LINK_LIBRARIES(find_links relfiles)
#TARGET_LINK_LIBRARIES(find_links cjson)
TARGET_LINK_LIBRARIES(find_links gumbo)

#  executable properties
SET_TARGET_PROPERTIES(find_links PROPERTIES OUTPUT_NAME "find_links")


# get positions of class

ADD_EXECUTABLE(positions_of_class positions_of_class.cc)

#  executable dependencies
ADD_DEPENDENCIES(positions_of_class gumbo)
#ADD_DEPENDENCIES(positions_of_class cjson)

#  executable target links
TARGET_LINK_LIBRARIES(positions_of_class relfiles)
#TARGET_LINK_LIBRARIES(positions_of_class cjson)
TARGET_LINK_LIBRARIES(positions_of_class gumbo)

#  executable properties
SET_TARGET_PROPERTIES(positions_of_class PROPERTIES OUTPUT_NAME "positions_of_class")




# my test

ADD_EXECUTABLE(main main.c)

#  executable dependencies
ADD_DEPENDENCIES(main gumbo)
#ADD_DEPENDENCIES(positions_of_class cjson)

#  executable target links
TARGET_LINK_LIBRARIES(main relfiles)
#TARGET_LINK_LIBRARIES(positions_of_class cjson)
TARGET_LINK_LIBRARIES(main gumbo)

#  executable properties
SET_TARGET_PROPERTIES(main PROPERTIES OUTPUT_NAME "main")






















