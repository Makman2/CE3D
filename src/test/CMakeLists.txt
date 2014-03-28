# Adds a new test target
function(AddCE3DTest target)
    add_executable(${target}
        ${ARGN}
        )
    target_link_libraries(${target}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        ${CURSES_LIBRARY}
        TestEnvironment
        CE3D
        )
    add_test(${target} ${target})
endfunction()

add_library(TestEnvironment SHARED TestEnvironment)
target_link_libraries(TestEnvironment
    ${CURSES_LIBRARY}
    CE3D
    )

add_subdirectory("transformation")
