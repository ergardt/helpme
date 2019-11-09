#include <SFML/Graphics.hpp>
#include <cmath>
#include "vector2f.h"

class Ball

{
public:
	vector2f pos;
	vector2f vel;
	float r;
	float R;
	float G;
	float B;
	float dt = 0.1;
	Ball()
	{

	}
	void drawBall(Ball Ball, sf::RenderWindow* window)
    {   
        sf::CircleShape shape(100);
        for (int i=Ball.r; i>0; i--)
        {
                shape.setRadius(i); 
                shape.setFillColor(sf::Color(Ball.R - (Ball.R*i/Ball.r), Ball.G-(Ball.G*i/Ball.r), Ball.B-(Ball.B*i/Ball.r)));
                shape.setPosition(Ball.pos.x - i, Ball.pos.y - i);
                window->draw(shape);
        }
	}

	/*void moveBall(Ball* Ball)
	{
	    (*Ball).x += (*Ball).vx * (*Ball).dt;
	    (*Ball).y += (*Ball).vy * (*Ball).dt;
	    if (((*Ball).y < (*Ball).r) or ((*Ball).y > 600 - (*Ball).r))
	        (*Ball).vy = -(*Ball).vy;
	    if ((*Ball).x > 800-(*Ball).r or (*Ball).x < (*Ball).r)
	        (*Ball).vx = -(*Ball).vx;

	}*/

	void moveBall(Ball* Ball)
	{
	    (*Ball).pos.x += (*Ball).vel.x * (*Ball).dt;
	    (*Ball).pos.y += (*Ball).vel.y * (*Ball).dt;
	    if (((*Ball).pos.y < (*Ball).r) or ((*Ball).pos.y > 600 - (*Ball).r))
	        (*Ball).vel.y = -(*Ball).vel.y;
	    if ((*Ball).pos.x > 800-(*Ball).r or (*Ball).pos.x < (*Ball).r)
	        (*Ball).vel.x = -(*Ball).vel.x;

	}

	
    Ball(vector2f tpos, vector2f tvel, float tr,  float tR, float tG, float tB)
    {
        pos = tpos;
        vel = tvel;
        r = tr;
        R = tR;
        G = tG;
        B = tB;

    }
    

};

void collideBalls(Ball* Ball1, Ball* Ball2)
	{   
	    if ((((*Ball1).pos.x-(*Ball2).pos.x) * ((*Ball1).pos.x-(*Ball2).pos.x) + ((*Ball1).pos.y-(*Ball2).pos.y) * ((*Ball1).pos.y-(*Ball2).pos.y)) <= ((*Ball1).r + (*Ball2).r) * ((*Ball1).r + (*Ball2).r) )
	        {		

	                (*Ball1).vel.x = -(*Ball1).vel.x;
	                (*Ball2).vel.y = -(*Ball2).vel.y;
	                (*Ball2).vel.x = -(*Ball2).vel.x;
	                (*Ball1).vel.y = -(*Ball1).vel.y;         
	       }
	}

