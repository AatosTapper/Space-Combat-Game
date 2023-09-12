add_executable(main main.cpp)

add_subdirectory(App)
target_link_libraries(main PRIVATE App)

add_subdirectory(Base)
target_link_libraries(main PRIVATE Base)

add_subdirectory(Renderer)
target_link_libraries(main PRIVATE Renderer)

add_subdirectory(Gameloop)
target_link_libraries(main PRIVATE Gameloop)

add_subdirectory(Entity)
target_link_libraries(main PRIVATE Entity)
target_link_libraries(main PRIVATE AiEntity)
target_link_libraries(main PRIVATE PlayerEntity)

add_subdirectory(Scene)
target_link_libraries(main PRIVATE Scene)

add_subdirectory(LogicManager)
target_link_libraries(main PRIVATE LogicManager)

add_subdirectory(Physics)
target_link_libraries(main PRIVATE PhysicsEngine)
target_link_libraries(main PRIVATE PhysicsObj)
target_link_libraries(main PRIVATE RK4)


target_link_libraries(main PRIVATE ${GLFW_LIBRARY})
target_link_libraries(main PRIVATE "-framework Cocoa")
target_link_libraries(main PRIVATE "-framework OpenGL")
target_link_libraries(main PRIVATE "-framework IOKit")