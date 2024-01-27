# components组件编译时会被自动构建(依据idf_component_register包含的头文件)
file(GLOB_RECURSE SOURCES src/*.*)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "inc"
                       REQUIRES "driver"
                       REQUIRES "freertos") 
