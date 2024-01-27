# components组件编译时会被自动构建(依据idf_component_register包含的头文件)
# 这是个模板方便copy的,当你需要别的库时,请参照oled库的CMakeList

file(GLOB_RECURSE SOURCES src/*.*)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "inc"
                       REQUIRES "driver"
                       REQUIRES "freertos") 
