# space-game

Ideas/todo

goals:
* gravity
* shoot stuff like asteroids
* get blown up by asteroids if they hit you
* other ships
  * steal their stuff
* star system map
* moving with player's perspective


game play loop:
* start somewhere with items like fuel/ammo (unlimited/energy weapons?)
  * fuel meter
  * refueling needs to be implemented


what components do we need:
* space ship
* star system
* object in space (static): i.e. planets and stuff that doesnt move
* moving objects in space (asteroids, other ships)
* projectiles
* space ship related items
* movement by arrow keys
* thrust to move forward, rotate to change directions

prioritization of components:
* space ship
* star system
* movement
* everything else listed above




## Screen Stuff
Screens we need:
* Start Menu
* Game
* Map
* Hyperspace
* End Screen

it'll look like
```objectivec
enum GameScreen {START, GAME, MAP, HYPER, END};
```
And in the display method, we'll have something like
```objectivec
enum GameScreen {START, GAME, MAP, HYPER, END};
GameScreen screen;
switch (screen) {
    case START:
        drawStart();
        break;
    case GAME:
        drawGame();
        break;
}
```
etc. etc.

In start menu there should be buttons
* Start Game
    * Switches the current screen to the game screen
* Exit
    * Exits the program with a status code of 0