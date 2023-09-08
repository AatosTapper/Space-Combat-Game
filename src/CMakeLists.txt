add_executable(main main.cpp)

add_subdirectory(Runtime)
target_link_libraries(main PRIVATE Runtime)

add_subdirectory(Base)
target_link_libraries(main PRIVATE Base)


target_link_libraries(main PRIVATE ${GLFW_LIBRARY})
target_link_libraries(main PRIVATE "-framework Cocoa")
target_link_libraries(main PRIVATE "-framework OpenGL")
target_link_libraries(main PRIVATE "-framework IOKit")