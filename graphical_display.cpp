//
// Created by Ethan Nerney on 11/7/18.
//

#include "graphical_display.h"
#include "rocket.h"
#include "hyperspace.h"
#include "button.h"
#include "asteroid.h"

using namespace position2D;
using namespace colorGraphics;
using namespace std;


GLdouble width, height;
int wd;

enum Screen {START, GAME, HYPERSPACE, END, RULES};

Quad startRect({0, 1, 0}, {250, 150}, 200, 100);
Quad howRect({0, 1, 0}, {250, 350}, 200, 100);
Quad rules({0, 1, 0}, {250, 250}, 400, 100);
Quad back({0, 1, 0}, {250, 450}, 80, 30);
Button goBack(back, "Go back");
Button rulesB(rules, "The only rules are there are no rules");
Button button(startRect, "Click here to Start");
Button howPlay(howRect, "Click here for rules");

vector<Entity*> allEnts;

Rocket rocket(position2D::ZERO);
PhysicsAspect p(&rocket, 5);
HyperSpace hyperspace(500, 5, 1200,600, Vector2D(600,300));

bool leftArrow = false;
bool rightArrow = false;
bool accellerating = false;

Screen screen = START;

void playGame() {
    screen = GAME;
}
void getRules() {
    screen = RULES;
}
void startScreen() {
    screen = START;
}
void doNothing() {}


void init(int w, int h) {
    width = w;
    height = h;

    rocket = Rocket(Vector2D(w/2,h/2));
   //allEnts.push_back(&hyperspace);
    allEnts.push_back(&rocket);
    allEnts.push_back(&p);

    auto darkGreyscale = colorGraphics::RGBGradient(RGBColor(.5, .5, .5), RGBColor(1, 1, 1));
    for (int i = 0; i < 10; ++i) {
        allEnts.emplace_back(new Asteroid(rand() % 35 + 7, Vector2D(rand() % (int)width, rand() % (int)height), darkGreyscale.getColor()));
    }

//    Asteroid rock(25, Vector2D(89, 73), colorGraphics::RGBColor(.7, .7, .7));

//    allEnts.push_back(&rock);
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    switch (screen) {
        case START:
            //do start screen drawing
            hyperspace.draw();
            button.draw();
            howPlay.draw();
            break;

        case GAME:
            for (Entity* &e: allEnts) {
                e->draw();
            }
            break;

        case END:
            //do end screen drawing
            break;

        case RULES:
            rulesB.draw();
            goBack.draw(4, 3);
            break;

        default:
            break;
    }
    /*
     * Draw here
     */




    // Render now
    glFlush();
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void keyboard(unsigned char key, int x, int y)
{
    Projectile* p = nullptr;
    switch (key) {
        case 27:
            glutDestroyWindow(wd);
            exit(0);
        case 32:
            p = rocket.shoot();
            allEnts.push_back(p);
            break;
        case 'h':
            screen = RULES;
            break;
        case 13:
            screen = GAME;
        default:
            break;
    }

    glutPostRedisplay();
}

void keyboardSpecial(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            leftArrow = true;
            rocket.turnLeft();
            //rocket.turn(ROTATE_LEFT);
            break;
        case GLUT_KEY_RIGHT:
            rightArrow = true;
            rocket.turnRight();
            //rocket.turn(ROTATE_RIGHT);
            break;
        case GLUT_KEY_UP:
            accellerating = true;
            //rocket.translate(UP * 5);
            break;
    }

    glutPostRedisplay();
}

void keyboardSpecialDown(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            leftArrow = false;
            rocket.stopLeft();
            //rocket.turn(ROTATE_LEFT);
            break;
        case GLUT_KEY_RIGHT:
            rightArrow = false;
            rocket.stopRight();
            //rocket.turn(ROTATE_RIGHT);
            break;
        case GLUT_KEY_UP:
            accellerating = false;
            break;
    }

    glutPostRedisplay();
}


void cursor(int x, int y) {
    /* play button */
    if (button.isOverlapping(x, y)) {
        button.hover();
    } else {
        button.release();
    }

    /* rules button */
    if (howPlay.isOverlapping(x, y)) {
        howPlay.hover();
    } else {
        howPlay.release();
    }

    /* go back button in rules page */
    if (goBack.isOverlapping(x, y)) {
        goBack.hover();
    } else {
        goBack.release();
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouseClicked(int b, int state, int x, int y) {
    /* start game button. pressing enter still works too */
    if (state == GLUT_DOWN &&
        b == GLUT_LEFT_BUTTON &&
        button.isOverlapping(x, y)) {
        button.pressDown();
    } else {
        button.release();
    }

    if (state == GLUT_UP &&
        b == GLUT_LEFT_BUTTON &&
        button.isOverlapping(x, y)) {
        button.click(playGame);
    }

    /* rules button. pressing h still works */
    if (state == GLUT_DOWN &&
        b == GLUT_LEFT_BUTTON &&
        howPlay.isOverlapping(x, y)) {
        howPlay.pressDown();
    } else {
        howPlay.release();
    }

    if (state == GLUT_UP &&
        b == GLUT_LEFT_BUTTON &&
            howPlay.isOverlapping(x, y)) {
        howPlay.click(getRules);
    }

    /* go back button */
    if (state == GLUT_DOWN &&
        b == GLUT_LEFT_BUTTON &&
        goBack.isOverlapping(x, y)) {
        goBack.pressDown();
    } else {
        howPlay.release();
    }

    if (state == GLUT_UP &&
        b == GLUT_LEFT_BUTTON &&
        goBack.isOverlapping(x, y)) {
        goBack.click(startScreen);
    }

    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);



    switch (screen) {
        case START:
            //do start screen drawing
            hyperspace.update();
            break;

        case GAME:


            for (Entity* &e: allEnts) {
                e->update();
            }

            if (leftArrow) {
                p.addForce(ROTATE_LEFT);
            } else if (rightArrow) {
                p.addForce(ROTATE_RIGHT);
            }

            if (accellerating) {
                rocket.accelerateForward();
            } else {
                rocket.stopAccelerating();
            }


            break;

        case END:
            //do end screen drawing
            break;

        default:
            break;
    }


}

/* Main function: GLUT runs as a console application starting at main()  */
int start(int argc, char** argv) {

    init(1200,600);

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 300); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Test Graphics" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(keyboard);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(keyboardSpecial);
    glutSpecialUpFunc(keyboardSpecialDown);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouseClicked);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

int main(int argc, char** argv) {
    start(argc, argv);

    return 0;
}