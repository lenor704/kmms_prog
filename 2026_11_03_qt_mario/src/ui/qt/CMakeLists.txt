target_sources(${PROJECT_NAME}
	PRIVATE
		game_view.cpp
		game_window.cpp
		qt_game_map.cpp
		qt_ui_factory.cpp
		qt_ui_obj_rect_adapter.cpp
		game_view.hpp
		game_window.hpp
		qt_game_map.hpp
		qt_ui_factory.hpp
		qt_ui_obj.hpp
		qt_ui_obj_rect_adapter.hpp
		scene_frame.hpp
		resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(ui_objects)
