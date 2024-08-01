cmake_minimum_required(VERSION 3.22)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        include
)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.c
        src/sequencial_list.c
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/..)