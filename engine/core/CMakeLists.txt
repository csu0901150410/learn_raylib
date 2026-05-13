
add_library(engine_core STATIC
	Application.h
	Application.cpp
)

target_include_directories(engine_core PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(engine_core PRIVATE raylib)
