cmake_minimum_required(VERSION 3.0)
project(code)

#配置编译选项
#意思是将CMAKE_CXX_FLAGS加上-g
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

#指定搜索的子目录,这里是搜索testmuduo里的cmake
#add_subdirectory(testmuduo)

#配置最终的可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#配置头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/server)
include_directories(${PROJECT_SOURCE_DIR}/include/server/db)
include_directories(${PROJECT_SOURCE_DIR}/include/server/model)
include_directories(${PROJECT_SOURCE_DIR}/include/server/redis)
include_directories(${PROJECT_SOURCE_DIR}/thirdparty)


#加载子目录，src放的是源码
add_subdirectory(src)

