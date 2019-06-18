file(GLOB HEADERS "include/DA-DAPPSio/state_history_plugin/*.hpp")
add_library( state_history_plugin
             state_history_plugin.cpp
             state_history_plugin_abi.cpp
             ${HEADERS} )

target_link_libraries( state_history_plugin chain_plugin DA-DAPPSio_chain appbase )
target_include_directories( state_history_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
