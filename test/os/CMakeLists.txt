# Now simply link against gtest or gtest_main as needed. Eg
file(GLOB TEST_SRC_FILES *.cpp)

set(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/ )

include_directories( ${INCLUDE_DIRS} )

add_executable(ostst ${TEST_SRC_FILES})
target_link_libraries(ostst os gmock_main)
add_test(NAME os_test COMMAND ostst)
