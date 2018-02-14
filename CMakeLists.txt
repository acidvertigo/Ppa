#-------------------------------------------------------------------------------
#	CMAKE SETTINGS
#-------------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED( VERSION 3.9 )
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#needed to set project version
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

#-------------------------------------------------------------------------------
#	PROJECT SETTINGS
#-------------------------------------------------------------------------------
SET( PROJ_NAME      "app" )
SET( PROJ_PATH      ${CMAKE_SOURCE_DIR} )
SET( PROJ_OUT_PATH  ${CMAKE_BINARY_DIR} )
SET( PROJ_LIBRARIES 
  audio
  os
)
SET( PROJ_INCLUDES 
  include
  ${CMAKE_BINARY_DIR}/exports
)
ADD_DEFINITIONS(-Dos_EXPORTS)
ADD_DEFINITIONS(-Daudio_EXPORTS)
PROJECT( ${PROJ_NAME} VERSION 0.0.1 )
ENABLE_TESTING()

#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------
FILE( GLOB_RECURSE PROJ_SOURCES src/*.cpp )
FILE( GLOB_RECURSE PROJ_HEADERS inc/*.h )

ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/src/audio/ )
ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/src/os/ )
ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/test/ )

#-------------------------------------------------------------------------------
#	ADDITIONAL LIBRARIES
#-------------------------------------------------------------------------------
# LIST(APPEND LIBRARIES
#
# )
# 
# # Remove duplicate library dependencies. 
#  LIST(REMOVE_DUPLICATES LIBRARIES) 

#-------------------------------------------------------------------------------
#	COMPILE FLAGS
#-------------------------------------------------------------------------------
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_STANDARD 17)

if(MSVC)
	ADD_COMPILE_OPTIONS(/MP)
	ADD_COMPILE_OPTIONS(/std:c++17)
elseif(CMAKE_COMPILER_IS_GNUCXX)
	ADD_COMPILE_OPTIONS(-std=c++17)
endif(MSVC)

#-------------------------------------------------------------------------------
#	SOURCE GROUPS
#-------------------------------------------------------------------------------
source_group(generated REGULAR_EXPRESSION ".*_automoc.cpp")
source_group(resources REGULAR_EXPRESSION ".*[.][q]?rc")
source_group(source REGULAR_EXPRESSION ".*[.]cpp")
source_group(headers REGULAR_EXPRESSION ".*[.]h")
source_group(continuous-integration REGULAR_EXPRESSION ".*[.]yml")

#-------------------------------------------------------------------------------
#	GENERATE EXECUTABLES
#-------------------------------------------------------------------------------
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES( ${PROJ_INCLUDES} )
ADD_EXECUTABLE( ${PROJ_NAME} ${PROJ_SOURCES} ${PROJ_SOURC})
TARGET_LINK_LIBRARIES( ${PROJ_NAME} ${PROJ_LIBRARIES} )

# Add debug postfix to executable name
SET_TARGET_PROPERTIES(app PROPERTIES DEBUG_POSTFIX "-debug")

# Use the automatically determined RPATH values
set_target_properties(${PROJ_NAME} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

#-------------------------------------------------------------------------------
#	DEFINE INSTALL FOLDERS
#-------------------------------------------------------------------------------
IF(CMAKE_BUILD_TYPE MATCHES "Release")
    INSTALL(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Release/
	ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/Release/
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Release/
        CONFIGURATIONS Release)
ELSE(CMAKE_BUILD_TYPE MATCHES "Release")
    INSTALL(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Debug/
	ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/Debug/
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Debug/
        CONFIGURATIONS Debug)
ENDIF(CMAKE_BUILD_TYPE MATCHES "Release")

INCLUDE(InstallRequiredSystemLibraries)
