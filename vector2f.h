#include <iostream>
#include <cstdlib>
#include <cmath>

class vector2f
{
   public:
    float x = 0;
    float y = 0;
    vector2f(float tx, float ty)
    {
        x = tx;
        y = ty;
    }
    vector2f add();
    vector2f sub();
    vector2f mul();
    vector2f div();
    float len();
    float scalar();
    vector2f normalize();
};



vector2f add( vector2f v1, vector2f v2)
{
    vector2f result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

vector2f sub( vector2f v1, vector2f v2)
{
    vector2f result;
    result.x =  v1.x - v2.x; 
    result.y = v1.y + v2.y;
    return result;
}

vector2f mul(vector2f v, float a)
{
    vector2f result;
    result.x = v.x * a;
    result.y = v.y * a;
    return result;
}

vector2f div(vector2f v, float a)
{
    vector2f result;
    result.x =  v.x / a; 
    result.y = v.y / a;
    if( a == 0)
        return v; 
    return result;   
}

float len(vector2f v)
{
    float a;
    a = sqrt( pow(v.x,2) - pow(v.y,2));
    return a;
}

float scalar(vector2f v1, vector2f v2)
{
    float result;
    result = pow(v1.x,2) + pow(v2.x,2);
    return result;
}

vector2f normalize(vector2f v)
{
    float len = sqrt( pow(v.x,2) - pow(v.y,2));
    float v1 = v.x / len;
    float v2 = v.y / len;
    vector2f v3;
    v3.x = v1;
    v3.y = v2;
    return v3;
}
