cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
project(space-game)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib")
endif (WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-deprecated -Wreturn-type -Werror")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES} display.h Shape.cpp Shape.h structs.h Circle.cpp Circle.h graphicsImports.h Quadrangle.cpp Quadrangle.h Entity.cpp Entity.h ../engine-extras/MyQuad.cpp ../engine-extras/MyQuad.h ../StarBoi.cpp ../StarBoi.h ../Hyperspace.cpp ../Hyperspace.h RandNum.cpp RandNum.h ParticleSystem.cpp ParticleSystem.h Particle.cpp Particle.h ../engine-extras/Fire.cpp ../engine-extras/Fire.h PhysicsAspect.cpp PhysicsAspect.h ../engine-extras/PhysicsCircle.cpp ../engine-extras/PhysicsCircle.h Collider.cpp Collider.h)

if (WIN32)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()