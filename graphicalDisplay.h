//
// Created by Ethan Nerney on 11/7/18.
//

#ifndef SPACE_GAME_GRAPHICALDISPLAY_H
#define SPACE_GAME_GRAPHICALDISPLAY_H

#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "engine-stuff/structs.h"


// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(int w, int h);

// Initialize OpenGL Graphics
void InitGL();

// Callback functions for GLUT

// Draw the window - this is where all the GL actions are
void display();

// Trap and process alphanumeric keyboard events
void keyboard(unsigned char key, int x, int y);

// Trap and process special keyboard events
void keyboardSpecial(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int dummy);

// Handle mouse button pressed and released events
void mouseClicked(int button, int state, int x, int y);

int start(int argc, char** argv);

#endif //SPACE_GAME_GRAPHICALDISPLAY_H
