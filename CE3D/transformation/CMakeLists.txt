list(APPEND SRC
    ${CMAKE_CURRENT_LIST_DIR}/custom
    ${CMAKE_CURRENT_LIST_DIR}/itransformable
    ${CMAKE_CURRENT_LIST_DIR}/orthogonal_depth_projection
    ${CMAKE_CURRENT_LIST_DIR}/orthogonal_projection
    ${CMAKE_CURRENT_LIST_DIR}/perspective_projection
    ${CMAKE_CURRENT_LIST_DIR}/transformation_chain
    ${CMAKE_CURRENT_LIST_DIR}/rotation
    ${CMAKE_CURRENT_LIST_DIR}/scale
    ${CMAKE_CURRENT_LIST_DIR}/transformation
    ${CMAKE_CURRENT_LIST_DIR}/translation
    ${CMAKE_CURRENT_LIST_DIR}/identity
    )
set(SRC "${SRC}" PARENT_SCOPE)
