#include "TXLib.h"

 void drawPlanet(int x, int y, int r, int red, int green, int blue)
 {
    int r0;
    r0=r;
    for (r; r>0; r=r-1)
        {
                txSetColor(RGB(red-red*r/r0, green-green*r/r0, blue-blue*r/r0));
                txSetFillColor(RGB(red-red*r/r0, green-green*r/r0, blue-blue*r/r0));
                txCircle(x-100-r/3*2, y+100+r/2, r);

        }
 }


int main()
{
    txCreateWindow(1240,720);

    drawPlanet(1650,10,400,255,190,0);
    drawPlanet(900,300,7,255,255,10);
    drawPlanet(820,250,12,255,0,120);
    drawPlanet(710,410,14,255,120,0);
    drawPlanet(750,300,19,0,255,255);
    drawPlanet(580,130,40,200,120,0);
    drawPlanet(450,330,40,200,200,6);

    txSetColor(RGB(255,255,200));

    for (int k=0; k<5; k=k+1)
    {
        txArc(260-3*k,430-3*k,395+3*k,460+3*k,160-7*k,225+14*k);

    }
    drawPlanet(350,200,37,100,100,255);

    txSetColor(RGB(200,200,255));
    txArc(140,300,320,330,155,235);

    drawPlanet(140,500,10,240,250,200);
    drawPlanet(230,20,40,50,50,255);




    return 0;
}
