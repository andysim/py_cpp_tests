project(boost_python_tests)
cmake_minimum_required(VERSION 2.6)

############################# Detect Prerequisites ##################################
# Get Boost
find_package(Boost COMPONENTS python REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# Get Python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})
#####################################################################################

############################### Hello World #########################################
set( HW_PROJECT_NAME "helloworld" )
add_library( ${HW_PROJECT_NAME} SHARED main.cc helloworld.cc )
set_target_properties( ${HW_PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX .so )
target_link_libraries( ${HW_PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )
# Generate a test input file
configure_file(helloworld_test.py.in helloworld_test.py)
#####################################################################################

################################## Vector ###########################################
add_library( vector SHARED main.cc helloworld.cc vector.cc )
set_target_properties( vector PROPERTIES PREFIX "" SUFFIX .so )
target_link_libraries( vector ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )
enable_testing()
add_test (vector python ${PROJECT_BINARY_DIR}/tests/vector_test.py)
# Generate test input files
configure_file(tests/vector_test.py.in tests/vector_test.py)
#####################################################################################


