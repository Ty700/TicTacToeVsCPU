set(
    GAMENETWORKINGSOCKETS_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/isteamnetworkingmessages.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/isteamnetworkingsockets.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/isteamnetworkingutils.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steam_api_common.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamclientpublic.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamnetworkingcustomsignaling.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamnetworkingsockets_flat.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamnetworkingsockets.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamnetworkingtypes.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamtypes.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/steam/steamuniverse.h"
)

target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${EXE_NAME} PRIVATE ${NETWORKING_HEADERS} ${GAMENETWORKINGSOCKETS_HEADERS})