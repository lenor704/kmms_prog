add_subdirectory(os_api)

if(GAME_TYPE STREQUAL "Qt")
	add_subdirectory(qt)
elseif(GAME_TYPE STREQUAL "WindowsConsole")
	add_subdirectory(windows)
elseif(GAME_TYPE STREQUAL "LinuxConsole")
	add_subdirectory(linux)
endif()
