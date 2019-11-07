#include <SFML/Graphics.hpp>
#include "gas.h"

const float dt = 0.1;





int main()
{


    //Ball Ball1(400, 300, 50, 5, 5, 200, 50, 200);
    //Ball Ball2(100, 100, 50, 3, 2, 200, 200, 50);



    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    Ball *Balls = new Ball[100];
    for (int i = 0; i <10; i++)
    {
        for (int j = 1; j < 10; j ++)
        {

            Balls[i * 10 + j - 1].x = (i+1)*72;
            Balls[i * 10 + j - 1].y = (j+1)*54;
            Balls[i * 10 + j - 1].r = 10;
            Balls[i * 10 + j - 1].vy = i;
            Balls[i * 10 + j - 1].vx = j;
            Balls[i * 10 + j - 1].R = 200;
            Balls[i * 10 + j - 1].G = 50;
            Balls[i * 10 + j - 1].B = 200;
        }



    }


    while (window.isOpen())
    {
        window.clear();
        for (;;)
        {
            for (int k = 0; k < 100; k++ )
            {
                drawBall(Balls[k], &window);
                moveBall(&Balls[k]);
                for (int m = 0; m < 100; m++)
                {
                    collideBalls(&Balls[m], &Balls[k]);
                }
            }
        
        window.display();
    }
    }

    return 0;
}
