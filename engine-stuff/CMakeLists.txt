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

add_executable(main.cpp ${SOURCE_FILES} display.h shape.cpp shape.h structs.h circle.cpp circle.h graphics_imports.h quadrangle.cpp quadrangle.h entity.cpp entity.h ../star_boi.cpp ../star_boi.h ../hyperspace.cpp ../hyperspace.h rand_num.cpp rand_num.h particle_system.cpp particle_system.h particle.cpp particle.h physics_aspect.cpp physics_aspect.h collider.cpp collider.h)

if (WIN32)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()