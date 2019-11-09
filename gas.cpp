#include <SFML/Graphics.hpp>
#include "gas.h"

const float dt = 0.1;





int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Ball *Balls = new Ball[100];
    for (int i = 0; i <10; i++)
    {
        for (int j = 0; j < 10; j ++)
        {
            Balls[i * 10 + j - 1] = Ball(vector2f((i+1)*72, (j+1)*54), vector2f(i ,j), 10, 200, 50, 200);
        }        
    }


    while (window.isOpen())
    {
        window.clear();
        for (;;)
        {
            for (int k = 0; k < 100; k++ )
            {
                Balls[k].drawBall(Balls[k], &window);
                Balls[k].moveBall(&Balls[k]);
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
