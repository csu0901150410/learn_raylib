# raylib 单独成模块

add_library(raylib SHARED IMPORTED GLOBAL)

set_target_properties(raylib PROPERTIES
    # 编译期用的导入库
    IMPORTED_IMPLIB
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/raylibdll.lib

    # 运行时dll
	IMPORTED_LOCATION
		${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib.dll

    # 头文件
    INTERFACE_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
