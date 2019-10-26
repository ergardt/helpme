#include <SFML/Graphics.hpp>
#include "simple_game.h"

const float dt = 0.1;

int main()

{
srand(time(NULL));
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
sf::CircleShape shape(100);

classBall Ball1;
Ball1.x = 400;
Ball1.y = 400;
Ball1.vx = 2;
Ball1.vy = 2;
Ball1.r = 10;
Ball1.R = 255;
Ball1.G = 255;
Ball1.B = 255;

classPlatform PlatformDown;
PlatformDown.x = 260;
PlatformDown.y = 580;
PlatformDown.l = 200;
PlatformDown.w = 20;
PlatformDown.v = 3;
PlatformDown.R = 100;
PlatformDown.G = 200;
PlatformDown.B = 90;
PlatformDown.dt = 0.1;


classPlatform PlatformUp;
PlatformUp.x = 260;
PlatformUp.y = 0;
PlatformUp.v = 10;
PlatformUp.l = 200;
PlatformUp.w = 20;
PlatformUp.R = 100;
PlatformUp.G = 200;
PlatformUp.B = 90;



 while (window.isOpen())
    {
        window.clear();
        for (;;)
        {
            
            drawPlatform(PlatformDown, &window);
            movePlatformDown(&PlatformDown);
            drawPlatform(PlatformUp, &window);
            movePlatformUp(&PlatformUp);
            drawBall(Ball1, &window);
            moveBall(&Ball1);
            collideBallPlatform(&Ball1, &PlatformDown);
            collideBallPlatform(&Ball1, &PlatformUp);
           
        }
         window.display();
    }
return 0;
}
