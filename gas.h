#include <SFML/Graphics.hpp>
#include <cmath>
#include "vector2f.h"

class Ball

{
public:
	Vector2f pos;
	Vector2f vel;
	float r;
	float R;
	float G;
	float B;
	float dt = 0.05;
	Ball()
	{

	}
	void draw(sf::RenderWindow* window)
    {   
        sf::CircleShape shape(r);
        for (int i = r; i > 0; i--)
        {
                shape.setRadius(i); 
                shape.setFillColor(sf::Color(R - (R * i/ r), G - (G * i / r), B - (B * i / r)));
                shape.setPosition(pos.x - i, pos.y - i);
                window->draw(shape);
        }
	}
	void move(float dt)
	{
	    pos.x += vel.x * dt;
	    pos.y += vel.y * dt;
	    
	    if ((pos.y < r) or (pos.y > (600 - r)))
			vel.y = -(vel.y);
	    if ((pos.x > 800 - r) or (pos.x < r))
	        vel.x = -(vel.x);

	}
    Ball(Vector2f tpos, Vector2f tvel, float tr,  float tR, float tG, float tB)
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

                            Vector2f cVel = add((*Ball1).vel, (*Ball2).vel);
                            Vector2f cPos = add((*Ball1).pos, (*Ball2).pos);
                          	(*Ball1).vel = sub(cVel, (*Ball1).vel);
                          	(*Ball2).vel = sub(cVel, (*Ball2).vel);
                 
                   }
            }

