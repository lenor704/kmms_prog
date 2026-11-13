if (QT_VERSION_MAJOR GREATER_EQUAL 6)
	qt_add_executable(${PROJECT_NAME}
		MANUAL_FINALIZATION
		main.cpp
	)
else()
	add_executable(${PROJECT_NAME} main.cpp)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(os_controls)
add_subdirectory(controller)
add_subdirectory(levels)
add_subdirectory(model)
add_subdirectory(objects)
add_subdirectory(ui)
add_subdirectory(util)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
		Qt${QT_VERSION_MAJOR}::Widgets
		Threads::Threads
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	WIN32_EXECUTABLE TRUE
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

if (QT_VERSION_MAJOR GREATER_EQUAL 6)
	qt_finalize_executable(${PROJECT_NAME})
endif()
