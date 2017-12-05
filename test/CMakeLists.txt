file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(testAVLTree ${SRCS} ../AVLTree/AVLTree.h ../AVLTree/AVLTree.cpp ../AVLTree/AVLTree.h testAVLTree.cpp testAVLTree.h)

target_link_libraries(testAVLTree
        gtest
        gmock
        )

include_directories("..")

install(TARGETS testAVLTree DESTINATION bin)
