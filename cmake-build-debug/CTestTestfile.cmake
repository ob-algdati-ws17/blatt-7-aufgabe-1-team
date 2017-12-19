# CMake generated Testfile for 
# Source directory: C:/Users/Laptop/CLionProjects/blatt-7-aufgabe-1-team
# Build directory: C:/Users/Laptop/CLionProjects/blatt-7-aufgabe-1-team/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testAVLTree "test/testAVLTree" "--gtest_output=xml:report.xml")
subdirs("googletest-build")
subdirs("test")
