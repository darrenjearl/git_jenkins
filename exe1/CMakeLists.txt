
add_executable(exe1 main.cpp)
add_executable(exe2 fail.cpp)
add_unit_test( exe2_test SRC main.cpp )
add_unit_test( test_exe2b SRC fail.cpp PARAM nofail )
add_unit_test( read SRC read.cpp PARAM ${CMAKE_CURRENT_SOURCE_DIR}/hello.txt )
