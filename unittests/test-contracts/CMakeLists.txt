if( EOSIO_COMPILE_TEST_CONTRACTS )
   set(EOSIO_WASM_OLD_BEHAVIOR "Off")
   find_package( DA-DAPPSio.cdt REQUIRED )
endif()

if ("${CMAKE_GENERATOR}" STREQUAL "Ninja")
   add_compile_options(-fcolor-diagnostics)
endif()

add_subdirectory( asserter )
add_subdirectory( deferred_test )
add_subdirectory( integration_test )
add_subdirectory( noop )
add_subdirectory( payloadless )
add_subdirectory( proxy )
add_subdirectory( snapshot_test )
add_subdirectory( test_api )
add_subdirectory( test_api_db )
add_subdirectory( test_api_multi_index )
add_subdirectory( test_ram_limit )
