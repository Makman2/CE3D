list(APPEND SRC
    ${CMAKE_CURRENT_LIST_DIR}/renderer
    )
set(SRC "${SRC}" PARENT_SCOPE)

add_subdirectory("console")
