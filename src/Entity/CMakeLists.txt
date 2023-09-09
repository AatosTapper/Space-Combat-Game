add_library(Entity Entity.cpp Entity.h)
target_include_directories(Entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(PhysicsObj PhysicsObj.cpp PhysicsObj.h)
target_include_directories(PhysicsObj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(AiController AiController.cpp AiController.h)
target_include_directories(AiController PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(PlayerController PlayerController.cpp PlayerController.h)
target_include_directories(PlayerController PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})