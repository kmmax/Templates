cmake_minimum_required(VERSION 3.2)

# prints variable's context
# prints vars context
function(print)
	message(STATUS ================)
	message(STATUS "Dumping ${ARGC} variables:")
	foreach(VAR_NAME ${ARGN})
		message(STATUS " ${VAR_NAME} == \"${${VAR_NAME}}\"")
	endforeach()
	message(STATUS ================)
endfunction()


set(CMAKE_CXX_STADARD 14)

option(PO "Builds boost::program_options template" ON)

project(Templates LANGUAGES CXX)

if (PO)
	add_subdirectory(ProgramOptions)
endif()

