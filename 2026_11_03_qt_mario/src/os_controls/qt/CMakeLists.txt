target_sources(${PROJECT_NAME}
	PRIVATE
		qt_control_settings.cpp
		qt_keyboard.cpp
		qt_control_settings.hpp
		qt_keyboard.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)
