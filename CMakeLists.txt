cmake_minimum_required(VERSION 2.8)
project(Tutorial)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

configure_file(
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
	)

include_directories("${PROJECT_BINARY_DIR}")

option (USE_MYMATH
	"Use tutorial provided math implementation" ON)

if (USE_MYMATH)
	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
	add_subdirectory(MathFunctions)
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

MESSAGE(STATUS "EXTRA_LIBS: " ${EXTRA_LIBS})

add_executable(Tutorial ${PROJECT_SOURCE_DIR}/tutorial.cxx)

target_link_libraries(Tutorial ${EXTRA_LIBS})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


enable_testing()

add_test (TutorialRuns Tutorial 25)

add_test (TutorialRuns25 Tutorial 25)
set_tests_properties(TutorialRuns25
	PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5"
	)

add_test (TutorialNegative Tutorial -25)
set_tests_properties(TutorialNegative
	PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")

add_test (TutorialUsage Tutorial WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(TutorialUsage
	PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
	)

