list(APPEND SRC
    ${CMAKE_CURRENT_LIST_DIR}/camera
    ${CMAKE_CURRENT_LIST_DIR}/linear_camera
    ${CMAKE_CURRENT_LIST_DIR}/linear_camera_code
    ${CMAKE_CURRENT_LIST_DIR}/manual_camera
    ${CMAKE_CURRENT_LIST_DIR}/manual_camera_code
    ${CMAKE_CURRENT_LIST_DIR}/orthographic_camera
    ${CMAKE_CURRENT_LIST_DIR}/orthographic_camera_code
    )
set(SRC "${SRC}" PARENT_SCOPE)
