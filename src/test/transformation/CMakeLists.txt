set(TRANSFORMATION_SRC
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/translation_test
    )

AddCE3DTest(TransformationTest ${TRANSFORMATION_SRC})
