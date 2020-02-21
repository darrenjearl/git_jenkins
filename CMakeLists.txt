cmake_minimum_required(VERSION 3.10)

project(github_test)
enable_testing()

function(add_unit_test target)
		set(prefix TEST)
		set(options "")
		set(singleArg "")
		set(multiValues SRC LIB PARAM)
		cmake_parse_arguments(${prefix} "${options}" "${singleArg}" "${multiValues}" ${ARGN} )
		message( "--------------------------" )
		message( "target: ${target}")
		message( "src: ${TEST_SRC}" )
		message( "lib: ${TEST_LIB}" )
		message( "param: ${TEST_PARAM}" )
		message( "unparsed: ${TEST_UNPARSED_ARGUMENTS}" )
		message( "argn: ${ARGN}")
		message( "--------------------------" )



		add_executable(${target} ${TEST_SRC} )
		target_link_libraries(${target} ${TEST_LIB})
		add_test(${target} ${target} ${TEST_PARAM})
		add_custom_command(TARGET ${target}
						   POST_BUILD
						   COMMAND ${target} ${TEST_PARAM}
						   COMMENT "Running ${target} ${TEST_PARAM}" VERBATIM)
endfunction()


add_subdirectory( exe1 )
