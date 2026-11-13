target_sources(${PROJECT_NAME}
	PRIVATE
		full_box.cpp
		fly_enemy.cpp
		enemy.cpp
		jump_enemy.cpp
		mario.cpp
		moving_platform.cpp
		money.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
