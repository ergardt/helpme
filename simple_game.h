#include <SFML/Graphics.hpp>
#include <cmath>



class classBall

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

};

class classPlatform
{
public:
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

void drawBall(classBall Ball, sf::RenderWindow* window)
{   
     sf::CircleShape shape( 100);
    for (int i=Ball.r; Ball.r>0; Ball.r--)
    {
            shape.setRadius(i); 
            shape.setFillColor(sf::Color(Ball.R - (Ball.R*Ball.r/i), Ball.G-(Ball.G*Ball.r/i), Ball.B-(Ball.B*Ball.r/i)));
            shape.setPosition(Ball.x - i, Ball.y - i);
            window->draw(shape);
            sf::Color::Black;
    }
}


void moveBall(classBall* Ball)
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

void collideBallPlatform(classBall* Ball, classPlatform* Platform)
{
  if (((*Platform).x <= (*Ball).x - (*Ball).r) and ((*Ball).x + (*Ball).r<= (*Platform).x + (*Platform).l) and ((*Ball).y + (*Ball).r == (*Platform).y))
  {
    (*Ball).vy = -(*Ball).vy;
  }
}

void collideBalls(classBall* Ball1, classBall* Ball2)
{   
    if ((((*Ball1).x-(*Ball2).x) * ((*Ball1).x-(*Ball2).x) + ((*Ball1).y-(*Ball2).y) * ((*Ball1).y-(*Ball2).y)) <= ((*Ball1).r + (*Ball2).r) * ((*Ball1).r + (*Ball2).r) )
        {
                (*Ball1).vx = -(*Ball1).vx;
                (*Ball2).vx = -(*Ball2).vx;
                (*Ball1).vy = -(*Ball1).vy;
                (*Ball2).vy = -(*Ball2).vy;
                
       }
}



void drawPlatform(classPlatform Platform, sf::RenderWindow* window)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(Platform.l, Platform.w));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setPosition(Platform.x, Platform.y);
    window->draw(rectangle);
}


void movePlatformDown(classPlatform* Platform)
{
    if ((*Platform).x > 800-(*Platform).l or (*Platform).x < 0)
      (*Platform).v = -(*Platform).v;

     if ((*Platform).v < 0)
    {
        if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            ((*Platform).v) = -((*Platform).v);
        (*Platform).x += (*Platform).v * (*Platform).dt;

        
     }
    if ((*Platform).v > 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            ((*Platform).v) = -((*Platform).v);
        (*Platform).x += (*Platform).v * (*Platform).dt;
        
    }

}

void movePlatformUp(classPlatform* Platform)
{
if ((*Platform).x > 800-(*Platform).l or (*Platform).x < 0)
(*Platform).v = -(*Platform).v;

if ((*Platform).v < 0)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))

    {
        ((*Platform).v) = -((*Platform).v);
        (*Platform).x += (*Platform).v * (*Platform).dt;
    }
}
if ((*Platform).v > 0)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))

    {
        ((*Platform).v) = -((*Platform).v);
        (*Platform).x += (*Platform).v * (*Platform).dt;
    }
}

}
