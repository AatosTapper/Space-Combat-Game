add_library(PhysicsEngine PhysicsEngine.cpp PhysicsEngine.h)
target_include_directories(PhysicsEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(PhysicsObj PhysicsObj.cpp PhysicsObj.h)
target_include_directories(PhysicsObj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(RK4 RK4.cpp RK4.h)
target_include_directories(RK4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
