set(DEMO_SOURCES main.cpp)
add_executable(demo WIN32 ${DEMO_SOURCES})
target_link_libraries(demo ${IRRLICHT_LIBS})

