# CMake generated Testfile for 
# Source directory: /home/arch/Projects/MLProject
# Build directory: /home/arch/Projects/MLProject/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[MLTest]=] "/home/arch/Projects/MLProject/cmake-build-debug/MLTest")
set_tests_properties([=[MLTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/arch/Projects/MLProject/CMakeLists.txt;23;add_test;/home/arch/Projects/MLProject/CMakeLists.txt;0;")
subdirs("googletest")
