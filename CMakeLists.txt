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
        engine-stuff/*.cpp
        engine-stuff/*.h
        )

add_executable(game ${SOURCE_FILES} game.h game.cpp graphical_display.cpp graphical_display.h rocket.cpp rocket.h projectile.cpp projectile.h null_projectile.cpp null_projectile.h hyperspace.cpp asteroid.cpp asteroid.h button.cpp)

if (WIN32)
    target_link_libraries (game ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (game ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()