
add_executable(exe1 main.cpp)
add_executable(exe2 fail.cpp)
add_unit_test( exe2_test SRC main.cpp )
add_unit_test( test_exe2b SRC fail.cpp PARAM faiil )
configure_file(hello.txt hello.txt COPYONLY)
add_unit_test( read SRC read.cpp PARAM hello.txt )
