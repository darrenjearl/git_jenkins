#simply the cmake version I have installed, may be reduced
cmake_minimum_required(VERSION 3.10)

project(github_test)
enable_testing()


# target is the name of the executable to be produced for the unit test, it is built from files defined after SRC, linked with libraries after LIB
# and executed with PARAM command line inputs.
function(add_unit_test target)
		set(prefix TEST)
		set(options "")
		set(singleArg "")
		set(multiValues SRC LIB PARAM)
		cmake_parse_arguments(${prefix} "${options}" "${singleArg}" "${multiValues}" ${ARGN} )
		#message( "--------------------------" )
		#message( "target: ${project-target}")
		#message( "src: ${TEST_SRC}" )
		#message( "lib: ${TEST_LIB}" )
		#message( "param: ${TEST_PARAM}" )
		#message( "unparsed: ${TEST_UNPARSED_ARGUMENTS}" )
		#message( "argn: ${ARGN}")
		#message( "--------------------------" )
		
		set(project-target "${PROJECT_NAME}-${target}")


		# next 3 lines are standard for building ctest
		add_executable(${project-target} ${TEST_SRC} )
		target_link_libraries(${project-target} ${TEST_LIB})
		add_test(${project-target} ${project-target} ${TEST_PARAM})
		
		#now the magic required to rerun the test iff rebuilt
		# this runs the command, and after success creates an output file 'project-target.passed' which indicates to the system the unit test was successful
		add_custom_command( OUTPUT ${project-target}.passed
						    COMMAND ${project-target} ${TEST_PARAM}
							COMMAND ${CMAKE_COMMAND} -E touch ${project-target}.passed
							COMMENT "running unit test '${project-target} ${TEST_PARAM}'")
		set(run_test UBTECH_UNIT_TEST_${project-target}) 		# make our actual name longer and more descriptive to prevent accidental clashes
		add_custom_target( ${run_test}					# make a target based on the above file (for add dependencies)
						   DEPENDS ${project-target}.passed )
		add_custom_command( TARGET ${project-target}			# on building the executable, remove the stale status file
						    PRE_BUILD
							COMMAND ${CMAKE_COMMAND} -E remove -f ${project-target}.passed 
							COMMENT "resetting test status of ${project-target}")
		
		add_dependencies( UBTECH_UNIT_TESTS ${run_test}) # adds the test to the top level target which always gets 'built'
		
endfunction()

add_custom_target(UBTECH_UNIT_TESTS ALL)


add_subdirectory( exe1 )
add_subdirectory( exe2 )
