#include <SFML/Graphics.hpp>
#include "gas.h"
#include <SFML/Window.hpp>

const float dt = 0.05;





int main()
{
 
    sf::RenderWindow window(sf::VideoMode(800, 600), "gas");
    Ball *Balls = new Ball[100];
    for (int i = 0; i <10; i++)
    {
        for (int j = 0; j < 10; j ++)
        {
            Balls[i * 10 + j] = Ball(Vector2f((i+1)*72, (j+1)*54), Vector2f((i+1)*2 ,(j+1)*3), 10, 200, 50, 200);
        }        
    }


    while (window.isOpen())
    {
       
        window.clear();

        for (;;)
        {
            for (int k = 0; k < 100; k++ )
            {
                Balls[k].draw(&window);
                Balls[k].move(dt);
                for (int m = 0; m < 100; m++)
                {
                    collideBalls(&Balls[m], &Balls[k]);
                }
            }
        
        window.display();
    }
    }
    delete [] Balls;
    return 0;

}
