set(SOURCES
	main.cpp
	menu_functions.cpp
	menu_items.cpp
)

set(HEADERS
	menu.hpp
	menu_functions.hpp
	menu_items.hpp
)

add_executable(menu ${SOURCES} ${HEADERS})