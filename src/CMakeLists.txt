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
target_link_libraries(main PRIVATE PhysicsObj)
target_link_libraries(main PRIVATE AiController)
target_link_libraries(main PRIVATE PlayerController)

add_subdirectory(Scene)
target_link_libraries(main PRIVATE Scene)

add_subdirectory(LogicManager)
target_link_libraries(main PRIVATE LogicManager)

add_subdirectory(PhysicsSolver)
target_link_libraries(main PRIVATE PhysicsSolver)


target_link_libraries(main PRIVATE ${GLFW_LIBRARY})
target_link_libraries(main PRIVATE "-framework Cocoa")
target_link_libraries(main PRIVATE "-framework OpenGL")
target_link_libraries(main PRIVATE "-framework IOKit")