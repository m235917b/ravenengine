include_directories(${ravenengine_SOURCE_DIR}/include /home/marvin/lib/stb)

add_executable(game Animation.cpp AnimTest.cpp ComposedObject.cpp Controler.cpp CubeTest.cpp loadObject.cpp loadShader.cpp main.cpp Mesh.cpp Model.cpp NPCSimple.cpp Player.cpp rpy.cpp Solid.cpp View.cpp WorldObject.cpp)
target_link_libraries(game -lSDL2main -lSDL2 -lGL -lGLU -lGLEW)
