#include <SFML/Graphics.hpp>
#include <cmath>
#include "vector2f.h"

class Ball

{
public:
	float x;
	float y;
	float r;
	float vx;
	float vy;
	float R;
	float G;
	float B;
	float dt = 0.1;
    /*Ball(float tx, float ty, float tr, float tvx, float tvy, float tR, float tG, float tB)
    {
        x = tx;
        y = ty;
        r = tr;
        vx = tvx;
        vy = tvy;
        R = tR;
        G = tG;
        B = tB;

    }*/
    void drawBall(Ball Ball, sf::RenderWindow* window)
    {   
        sf::CircleShape shape(100);
        for (int i=Ball.r; i>0; i--)
        {
                shape.setRadius(i); 
                shape.setFillColor(sf::Color(Ball.R - (Ball.R*i/Ball.r), Ball.G-(Ball.G*i/Ball.r), Ball.B-(Ball.B*i/Ball.r)));
                shape.setPosition(Ball.x - i, Ball.y - i);
                window->draw(shape);
	}
    }


	void moveBall(Ball* Ball)
	{
	    (*Ball).x += (*Ball).vx * (*Ball).dt;
	    (*Ball).y += (*Ball).vy * (*Ball).dt;
	    if (((*Ball).y < (*Ball).r) or ((*Ball).y > 600 - (*Ball).r))
		(*Ball).vy = -(*Ball).vy;
	    if ((*Ball).x > 800-(*Ball).r or (*Ball).x < (*Ball).r)
		(*Ball).vx = -(*Ball).vx;

	}

};





void collideBalls(Ball* Ball1, Ball* Ball2)
{   
    if ((((*Ball1).x-(*Ball2).x) * ((*Ball1).x-(*Ball2).x) + ((*Ball1).y-(*Ball2).y) * ((*Ball1).y-(*Ball2).y)) <= ((*Ball1).r + (*Ball2).r) * ((*Ball1).r + (*Ball2).r) )
        {		
        		
                (*Ball1).vx = -(*Ball1).vx;
                (*Ball2).vx = -(*Ball2).vx;
                (*Ball1).vy = -(*Ball1).vy;
                (*Ball2).vy = -(*Ball2).vy;
                
       }
}

