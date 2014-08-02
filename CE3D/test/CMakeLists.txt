# Adds a new test target
function(AddCE3DTest target)
    add_executable(${target}
        ${ARGN}
        )

    target_link_libraries(${target}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        TestEnvironment
        CE3D
        )

    add_test(${target} ${target})

    add_custom_command(TARGET ${target}
        POST_BUILD
        COMMAND ${target}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running ${target}..." VERBATIM
        )
endfunction()

add_library(TestEnvironment SHARED TestEnvironment)
target_link_libraries(TestEnvironment
    CE3D
    )

add_subdirectory("transformation")
add_subdirectory("camera")
add_subdirectory("console")
add_subdirectory("util")
add_subdirectory("model")
add_subdirectory("renderer")
add_subdirectory("world")
