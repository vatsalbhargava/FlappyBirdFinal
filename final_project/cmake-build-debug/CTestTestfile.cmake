# CMake generated Testfile for 
# Source directory: /Users/vatsalbhargava/Documents/CS 211/final_project
# Build directory: /Users/vatsalbhargava/Documents/CS 211/final_project/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_model_test "model_test")
set_tests_properties(Test_model_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/vatsalbhargava/Documents/CS 211/final_project/.cs211/cmake/211commands.cmake;90;add_test;/Users/vatsalbhargava/Documents/CS 211/final_project/CMakeLists.txt;22;add_test_program;/Users/vatsalbhargava/Documents/CS 211/final_project/CMakeLists.txt;0;")
add_test(Test_bird_test "bird_test")
set_tests_properties(Test_bird_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/vatsalbhargava/Documents/CS 211/final_project/.cs211/cmake/211commands.cmake;90;add_test;/Users/vatsalbhargava/Documents/CS 211/final_project/CMakeLists.txt;27;add_test_program;/Users/vatsalbhargava/Documents/CS 211/final_project/CMakeLists.txt;0;")
subdirs(".cs211/lib/catch")
subdirs(".cs211/lib/ge211")
