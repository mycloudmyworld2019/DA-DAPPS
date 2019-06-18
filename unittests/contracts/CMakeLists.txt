# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/DA-DAPPSio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/DA-DAPPSio.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/DA-DAPPSio.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/DA-DAPPSio.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/DA-DAPPSio.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/DA-DAPPSio.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/DA-DAPPSio.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/DA-DAPPSio.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/DA-DAPPSio.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/DA-DAPPSio.wrap/)
