//
// Created by Ethan Nerney on 11/7/18.
//

#include "graphical_display.h"
#include "rocket.h"
#include "hyperspace.h"
#include "button.h"
#include "asteroid.h"
#include <experimental/optional>

using namespace position2D;
using namespace colorGraphics;
using namespace std;
using namespace experimental;


GLdouble width, height;
int wd;

enum Screen {START, GAME, HYPERSPACE, END, RULES};


Quad startRect({0, 1, 0}, {600, 200}, 200, 100);
Quad howRect({0, 1, 0}, {600, 400}, 200, 100);
Quad rules({0, 1, 0}, {600, 250}, 400, 100);
Quad back({0, 1, 0}, {600, 450}, 80, 30);
Button goBack(back, "Go back");
Button rulesB(rules, "The only rule is that there are no rules.");
Button button(startRect, "Click here to Start");
Button howPlay(howRect, "Click here for rules");

Quad deadRect({0,1,0}, {600,100}, 150, 75);
Button youDied(deadRect, "You Died");

Quad againRect({0,1,0}, {600, 500}, 150, 100);
Button again(againRect, "Play Again");

Quad warpRect({0,1,0}, {600,300}, 250,75);
Button warp(warpRect, "Warping through Hyperspace");

vector<Entity*> allEnts;
vector<PhysicsAspect*> physAspects;
vector<optional<int>> stuff; // vector keeps track of asteroid info. needed for destroying them with projectiles

Rocket rocket(position2D::ZERO);
PhysicsAspect phys(&rocket, 5);
HyperSpace hyperspace(500, 5, 1200,600, Vector2D(600,300));

ParticleSystem explosion(500, 1, 50, 360, 10, 8, colorGraphics::FIRE, Vector2D(600, 300));

int hyperspaceTimer = 200;

const int ASTEROID_MAX_WIDTH = 35;
const int ASTEROID_MIN_WIDTH = 20;


bool leftArrow = false;
bool rightArrow = false;
bool accelerating = false;

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

void reset() {
    rocket.setPosition(Vector2D(width/2,height/2));
    spawnAsteroid(10);
    startScreen();
}

void doNothing() {}


void init(int w, int h) {
    width = w;
    height = h;

    srand(time(nullptr));

    rocket = Rocket(Vector2D(w/2,h/2));
   //allEnts.push_back(&hyperspace);
    allEnts.push_back(&rocket);
    allEnts.push_back(&phys);

    spawnAsteroid(17);

}

void spawnAsteroid(int numA) {
    auto darkGrayscale = colorGraphics::RGBGradient(RGBColor(.5, .5, .5), RGBColor(.07, .07, .07));
    for (int i = 0; i < numA; ++i) {
        int radius = rand() % ASTEROID_MAX_WIDTH + ASTEROID_MIN_WIDTH;
        Asteroid* a = new Asteroid(radius, Vector2D(rand() % (int)width, rand() % (int)height), darkGrayscale.getColor());
//        PhysicsAspect* pa = new PhysicsAspect(a, 5, Circle(a->getRadius(), a->getCenter(), colorGraphics::GREEN));
//        pa->addForce(Vector2D(rand() % 2 - 1, rand() % 2 - 1));

        allEnts.emplace_back(a);
//        allEnts.emplace_back(pa);
//        physAspects.emplace_back(pa);

        stuff.push_back(radius); // add asteroid radius to vector, order matters here.
    }

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
            youDied.draw();
            again.draw();
            explosion.draw();
            break;

        case RULES:
            rulesB.draw();
            goBack.draw(4, 3);
            break;

        case HYPERSPACE:
            hyperspace.draw();
            warp.draw();
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
    double theta = 0;
    switch (key) {
        case 27:
            glutDestroyWindow(wd);
            exit(0);
        case 32:

            p = rocket.shoot();
            allEnts.emplace_back(new PhysicsAspect(p, 1, Circle(p->getRadius(),p->getCenter(), colorGraphics::GREEN)));
            theta = rocket.getCenter().rotationAngle * M_PI / 180;
            phys.addForce(-Vector2D(cosf(theta),sinf(theta)));
            allEnts.insert(allEnts.begin(), p);

            break;
        case 'h':
            screen = RULES;
            break;
        case 13:
            screen = GAME;
            break;
        case 'q':
            screen = END;
            break;
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
            accelerating = true;
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
            accelerating = false;
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

    if (again.isOverlapping(x,y)) {
        again.hover();
    } else {
        again.release();
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

    /* Play again button */
    if (state == GLUT_DOWN &&
        b == GLUT_LEFT_BUTTON &&
        again.isOverlapping(x, y)) {
        again.pressDown();
    } else {
        again.release();
    }

    if (state == GLUT_UP &&
        b == GLUT_LEFT_BUTTON &&
        again.isOverlapping(x, y)) {
        again.click(reset);
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

        case GAME: {


            for (Entity* &e: allEnts) {
                e->update();
            }

            if (leftArrow) {
                phys.addForce(ROTATE_LEFT);
            } else if (rightArrow) {
                phys.addForce(ROTATE_RIGHT);
            }

            if (accelerating) {
                rocket.accelerateForward();
                double theta = rocket.getCenter().rotationAngle * M_PI / 180;
                double x = cosf(theta);
                double y = sinf(theta);

                phys.addForce(Vector2D(x, y));
            } else {
                rocket.stopAccelerating();
            }

            /* crazy loops for projectiles hitting asteroids */
            for (int i = 0; i < allEnts.size(); ++i) {
                // see if this entity is a projectile
                std::string eString = allEnts[i]->toString();
                int index = 0; // index for accessing things from asteroid info vector
                if (eString == "projectile") {
                    Projectile temp(allEnts[i]->getCenter(), {0, 0}); // temp projectile at position of actual projectile
                    for (int j = i; j < allEnts.size(); ++j) {
                        std::string eString2 = allEnts[j]->toString(); // see if there are other asteroids
                        if (eString2 == "asteroid") {
                            if(!stuff.at(index)){ // if asteroid has already been destoryed, incremet index
                                ++index;
                            }
                            Asteroid tem(*stuff.at(index), allEnts[j]->getCenter(), {0, 0, 0}); // temp asteroid at position of actual asteroid

                            if (temp.doesIntersect(tem)) { // if projectal intersects asteroid
//                                cout << *stuff.at(index) << endl;
                                stuff[index] = nullopt; // remove aseteroid info
                                allEnts.erase(allEnts.begin() + j); // remove asteroid from game
                                allEnts.erase(allEnts.begin() + i); // remove projectile from game
                            }
                            ++index; // check at the next index
                        }
                    }
                }
            }

            /* another crazy loop for rocket collision detection */
            for (int i = 0; i < allEnts.size(); ++i) {
                std::string rString = allEnts[i]->toString();
                int index = 0; // index for accessing things from asteroid info vector
                if (rString == "rocket"){
                    Circle temp(5, allEnts[i]->getCenter(), {0,0,0});
                    for (int j = i; j < allEnts.size(); ++j) {
                        std::string aString = allEnts[j]->toString(); // see if there are other asteroids
                        if (aString == "asteroid") {
                            if(!stuff.at(index)){ // if asteroid has already been destoryed, incremet index
                                ++index;
                            }
                            Asteroid tem(*stuff.at(index), allEnts[j]->getCenter(), {0, 0, 0}); // temp asteroid at position of actual asteroid

                            if (temp.doesIntersect(tem)) { // if rocket intersects asteroid
                                screen = END;
                            }
                            ++index; // check at the next index
                        }
                    }
                }
            }
        }


        if (rocket.getCenter().x < 0 || rocket.getCenter().x > width) {
            screen = HYPERSPACE;
        } else if (rocket.getCenter().y < 0 || rocket.getCenter().y > height) {
            screen = HYPERSPACE;
        }

            break;

        case END:
            //do end screen drawing
            explosion.update();
            break;

        case HYPERSPACE:
            hyperspaceTimer--;
            hyperspace.update();
            if (hyperspaceTimer < 0) {
                hyperspaceTimer = 200;
                spawnAsteroid(10);
                rocket.setPosition(Vector2D(width/2,height/2));
                phys.setVelocity(ZERO);
                screen = GAME;
            }
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
    glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("StarBoys: An Adventure Across Time" /* title */ );

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