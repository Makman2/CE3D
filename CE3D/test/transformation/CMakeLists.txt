AddCE3DTest(TranslationTest
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/translation_test
    )

AddCE3DTest(OrthogonalProjectionTest
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/orthogonal_projection_test
    )

AddCE3DTest(CustomTest
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/custom_test
    )

AddCE3DTest(IdentityTest
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/identity_test
    )

AddCE3DTest(TransformationChainTest
    ${CMAKE_CURRENT_LIST_DIR}/transformation_test
    ${CMAKE_CURRENT_LIST_DIR}/transformation_chain_test
    )
