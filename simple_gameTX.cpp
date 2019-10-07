#include "TXLib.h"

#include "ergardt.h"

const float dt = 0.1;

int main()

{
txCreateWindow(800, 600);

structBall Ball1;
Ball1.x = 400;
Ball1.y = 400;
Ball1.vx = 10;
Ball1.vy = 10;
Ball1.r = 10;
Ball1.R = 255;
Ball1.G = 255;
Ball1.B = 255;

structPlatform PlatformDown;
PlatformDown.x = 260;
PlatformDown.y = 580;
PlatformDown.l = 200;
PlatformDown.w = 20;
PlatformDown.v = 10;
PlatformDown.R = 100;
PlatformDown.G = 200;
PlatformDown.B = 90;
PlatformDown.dt = 0.1;


structPlatform PlatformUp;
PlatformUp.x = 260;
PlatformUp.y = 0;
PlatformUp.v = 10;
PlatformUp.l = 200;
PlatformUp.w = 20;
PlatformUp.R = 100;
PlatformUp.G = 200;
PlatformUp.B = 90;


for (;;)
{
    txClear();
    drawPlatform(PlatformDown);
    movePlatformDown(&PlatformDown);
    drawPlatform(PlatformUp);
    movePlatformUp(&PlatformUp);
    drawBall(Ball1);
    moveBall(&Ball1);
    collideBallPlatform(&Ball1, &PlatformDown);
    collideBallPlatform(&Ball1, &PlatformUp);
    txSleep(dt);
}

return 0;
}
