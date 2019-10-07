#include "TXLib.h"
#include <cmath>

struct structBall

{
float x;
float y;
float r;
float vx;
float vy;
float R;
float G;
float B;
float dt = 0.1;

};

struct structPlatform
{
float x = 0;
float y = 0;
float l = 0;
float w = 0;
float v = 0;
float R = 0;
float G = 0;
float B = 0;
float dt = 0.1;
};

void drawBall(structBall Ball)
{
    for (int i=Ball.r; Ball.r>0; Ball.r--)

    {
        int rgb = RGB(Ball.R-Ball.R*Ball.r/i, Ball.G-Ball.G*Ball.r/i, Ball.B-Ball.B*Ball.r/i);
        txSetColor(rgb);
        txSetFillColor(rgb);
        txCircle(Ball.x-Ball.r/3*2, Ball.y+Ball.r/2, Ball.r);
        txSetFillColor(RGB(0,0,0));
    }
}

void moveBall(structBall* Ball)
{
if ((*Ball).y < (*Ball).r)
(*Ball).vy = -(*Ball).vy;
if ((*Ball).x > 800-(*Ball).r or (*Ball).x < (*Ball).r)
(*Ball).vx = -(*Ball).vx;
(*Ball).x += (*Ball).vx * (*Ball).dt;
(*Ball).y += (*Ball).vy * (*Ball).dt;
if ((*Ball).y > 600 - (*Ball).r)
{
(*Ball).x = 400;
(*Ball).y = 400;
}
}

/*void controlBall(float* vx, float* vy)
{
if (GetAsyncKeyState(VK_DOWN))
(*vy) -= 0.5;
if (GetAsyncKeyState(VK_UP))
(*vy) += 0.5;
if (GetAsyncKeyState(VK_RIGHT))
(*vx) += 0.5;
if (GetAsyncKeyState(VK_LEFT))
(*vx) -= 0.5;

}*/

void collideBallPlatform(structBall* Ball, structPlatform* Platform /*,
float x0_blocks, float y0_blocks, float x_plat, float y_plat, int lx, int ly, int kx, int ky, int arr*/)
{
if (((*Platform).x <= (*Ball).x - (*Ball).r) and ((*Ball).x + (*Ball).r<= (*Platform).x + (*Platform).l) and ((*Ball).y + (*Ball).r == (*Platform).y))
{
(*Ball).vy = -(*Ball).vy;
}
/*
if (((*x1 - r > x0_blocks) and (*x1 + r < x_plat)) and ((*y1 + r > y0_plat) and (*y1 - r < y_plat)))
{
int tmp_x = *x1/(lx+kx), tmp_y = *y1/(ly+ky);
if (arr[tmp_x][tmp_y] == 1){
arr[tmp_x][tmp_y] = 0;
rgb = RGB(0, 0, 0);
txSetColor(rgb);
txSetFillColor(rgb);
txRectangle(tmp_x*(lx+kx), tmp_y*(ly+ky), tmp_x*(lx+kx) + lx, tmp_y*(ly+ky) + ly);
}
}
*/
}

void collideBalls(structBall* Ball1, structBall* Ball2)
{   
    if (sqrt(((*Ball1).x-(*Ball2).x)^2+((*Ball1).y-(*Ball2).y)^2) <= (*Ball1).r + (*Ball2).r)
        {
                (*Ball1).vx = -(*Ball1).vx;
                (*Ball2).vx = -(*Ball2).vx;
                (*Ball1).vy = -(*Ball1).vy;
                (*Ball2).vy = -(*Ball2).vy;
                
       }
}



void drawPlatform(structPlatform Platform)
{

    int rgb = RGB(Platform.R, Platform.G, Platform.B);
    txSetColor(rgb);
    txSetFillColor(rgb);
    txRectangle(Platform.x, Platform.y, Platform.x + Platform.l, Platform.y + Platform.w);
    rgb = RGB(Platform.R - 30, Platform.G - 30, Platform.B - 30);
    txSetColor(rgb);
    txSetFillColor(rgb);
    txRectangle(Platform.x+5, Platform.y+5, Platform.x + Platform.l - 5, Platform.y + Platform.w - 5);
    rgb = RGB(Platform.R - 60, Platform.G - 60, Platform.B - 60);
    txSetColor(rgb);
    txSetFillColor(rgb);
    POINT part[6] = {{Platform.x, Platform.y}, {Platform.x + 5, Platform.y + 5}, {Platform.x + 5, Platform.y + Platform.w - 5},
    {Platform.x + Platform.l - 5, Platform.y + Platform.w - 5}, {Platform.x + Platform.l, Platform.y + Platform.w}, {Platform.x, Platform.y + Platform.w}};
    txPolygon(part, 6);
    txSetFillColor(RGB(0,0,0));
}

void movePlatformDown(structPlatform* Platform)
{
    if ((*Platform).x > 800-(*Platform).l or (*Platform).x < 0)
      (*Platform).v = -(*Platform).v;

     if ((*Platform).v < 0)
    {
        if (GetAsyncKeyState(VK_RIGHT))
        ((*Platform).v) = -((*Platform).v);
        (*Platform).x += (*Platform).v * (*Platform).dt;
     }
if ((*Platform).v > 0)
{
if (GetAsyncKeyState(VK_LEFT))
((*Platform).v) = -((*Platform).v);
(*Platform).x += (*Platform).v * (*Platform).dt;
}

}

void movePlatformUp(structPlatform* Platform)
{
if ((*Platform).x > 800-(*Platform).l or (*Platform).x < 0)
(*Platform).v = -(*Platform).v;

if ((*Platform).v < 0)
{
if (GetAsyncKeyState('D'))
((*Platform).v) = -((*Platform).v);
(*Platform).x += (*Platform).v * (*Platform).dt;
}
if ((*Platform).v > 0)
{
if (GetAsyncKeyState('A'))
((*Platform).v) = -((*Platform).v);
(*Platform).x += (*Platform).v * (*Platform).dt;
}

}
