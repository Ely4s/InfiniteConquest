cmake_minimum_required(VERSION 3.2)
project(InfiniteConquest)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH "../bin/")

include(SourceFilesName.cmake)

set(ROOT ./src)

include_directories(${ROOT})

foreach(SOURCE_FILE_NAME ${SOURCE_FILES_NAME})

    list(APPEND SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/${SOURCE_FILE_NAME}")

endforeach()


add_executable(InfiniteConquest ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)

    include_directories(${SFML_INCLUDE_DIR})

    target_link_libraries(InfiniteConquest ${SFML_LIBRARIES})

endif()