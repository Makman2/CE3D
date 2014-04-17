list(APPEND SRC
    ${CMAKE_CURRENT_LIST_DIR}/renderer
    )

add_subdirectory("console")

set(SRC "${SRC}" PARENT_SCOPE)
