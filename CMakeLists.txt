cmake_minimum_required(VERSION 3.3)

#指定项目名
project(Shao)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(problems)
#add_subdirectory(book)