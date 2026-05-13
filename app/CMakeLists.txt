
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		engine_core
        WinMM
)

# 拷贝dll
if (WIN32)
    get_target_property(RAYLIB_DLL raylib IMPORTED_LOCATION)

    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${RAYLIB_DLL}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
