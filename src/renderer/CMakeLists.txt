list(APPEND SRC
    ${CMAKE_CURRENT_LIST_DIR}/renderer
    ${CMAKE_CURRENT_LIST_DIR}/renderer_code
    )

add_subdirectory("console")

set(SRC "${SRC}" PARENT_SCOPE)
