add_executable(cacheforge_tests
    database_tests.cpp
    error_tests.cpp
    main_tests.cpp
    resp_tests.cpp
    server_tests.cpp
    socket_tests.cpp
    ${catch2_SOURCE_DIR}/extras/catch_amalgamated.cpp
)

target_include_directories(cacheforge_tests PRIVATE ${catch2_SOURCE_DIR}/extras)
target_link_libraries(cacheforge_tests PRIVATE cacheforge_core)
target_compile_definitions(cacheforge_tests PRIVATE CACHEFORGE_EXECUTABLE="$<TARGET_FILE:cacheforge>")

add_test(NAME cacheforge_tests COMMAND cacheforge_tests)

add_test(NAME rejects_zero_port COMMAND $<TARGET_FILE:cacheforge> 0)
add_test(NAME rejects_out_of_range_port COMMAND $<TARGET_FILE:cacheforge> 65536)
add_test(NAME rejects_missing_flag_value COMMAND $<TARGET_FILE:cacheforge> --load-dump)
add_test(NAME rejects_zero_max_keys COMMAND $<TARGET_FILE:cacheforge> --max-keys 0)
add_test(NAME rejects_invalid_dump_interval COMMAND $<TARGET_FILE:cacheforge> --dump-interval bad)
add_test(NAME rejects_missing_dump_path COMMAND $<TARGET_FILE:cacheforge> --dump-path)
add_test(NAME rejects_invalid_max_keys COMMAND $<TARGET_FILE:cacheforge> --max-keys bad)
add_test(NAME rejects_zero_dump_interval COMMAND $<TARGET_FILE:cacheforge> --dump-interval 0)

set_tests_properties(rejects_zero_port rejects_out_of_range_port rejects_missing_flag_value
                     rejects_zero_max_keys rejects_invalid_dump_interval rejects_missing_dump_path
                     rejects_invalid_max_keys rejects_zero_dump_interval PROPERTIES WILL_FAIL TRUE)
