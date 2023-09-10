add_library(Entity Entity.cpp Entity.h)
target_include_directories(Entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AiEntity AiEntity.cpp AiEntity.h)
target_include_directories(AiEntity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(PlayerEntity PlayerEntity.cpp PlayerEntity.h)
target_include_directories(PlayerEntity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})