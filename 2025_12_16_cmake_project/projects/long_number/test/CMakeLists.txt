set(SOURCES
	test_long_number.cpp
)

add_executable(test_long_number ${SOURCES})
target_link_libraries(test_long_number
	gtest_main
	
	${LIBRARY}
)

add_test(test_long_number test_long_number)