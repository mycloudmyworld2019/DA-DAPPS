file(GLOB HEADERS "include/DA-DAPPSio/http_client_plugin/*.hpp")
add_library( http_client_plugin
             http_client_plugin.cpp
             ${HEADERS} )

target_link_libraries( http_client_plugin appbase DA-DAPPSio_chain fc )
target_include_directories( http_client_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
