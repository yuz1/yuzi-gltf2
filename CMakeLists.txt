cmake_minimum_required(VERSION 3.14)

project(
    yuzi_gltf2
    VERSION 0.1.0
    LANGUAGES CXX
)

string(TOLOWER ${PROJECT_NAME} LOWER_PROJECT_NAME)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
        "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
    )
endif()


option(YUZI_GLTF2_USE_EXTERNAL_JSON "Use an external JSON library" OFF)
add_subdirectory(3rdparty)
# ---- IDE ----
file(GLOB ${PROJECT_NAME}_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/${LOWER_PROJECT_NAME}/*.h")
file(GLOB ${PROJECT_NAME}_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# ---- Create library ----
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_HEADERS} ${${PROJECT_NAME}_SOURCES})
add_library(YUZI::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_include_directories(
    ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

# ---- Add Target ----

target_link_libraries(${PROJECT_NAME} PUBLIC general nlohmann_json::nlohmann_json)

source_group(${PROJECT_NAME} "Header Files"                             FILES ${${PROJECT_NAME}_HEADERS})

add_subdirectory(standalone)