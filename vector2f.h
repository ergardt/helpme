#include <iostream>
#include <cstdlib>
#include <cmath>

class Vector2f
{
   public:
    float x;
    float y;
    Vector2f(float tx, float ty)
    {
        x = tx;
        y = ty;
    }
            

        Vector2f mul (float a)
        {
            Vector2f result;
            result.x = x * a;
            result.y = y * a;
            return result;
        }

        Vector2f div(float a)
        {
            Vector2f result;
            result.x =  x / a; 
            result.y = y / a;
             
            return result;   
        }

        float len()
        {
            float a;
            a = sqrt( pow(x,2) - pow(y,2));
            return a;
        }

        Vector2f normalize()
        {
            float len = sqrt( pow(x,2) - pow(y,2));
            float v1 = x / len;
            float v2 = y / len;
            Vector2f v3;
            v3.x = v1;
            v3.y = v2;
            return v3;
}
    Vector2f()
    {
    }
};


        Vector2f add(Vector2f& v1, Vector2f& v2)
        {
            Vector2f result;
            result.x = v1.x + v2.x;
            result.y = v1.y + v2.y;
            return result;
        }

        Vector2f sub(Vector2f& v1, Vector2f& v2)
        {
            Vector2f result;
            result.x =  v1.x - v2.x; 
            result.y = v1.y - v2.y;
            return result;
        }
         float scalar(Vector2f& v1, Vector2f& v2)
        {
            float result;
            result = pow(v1.x,2) + pow(v2.x,2);
            return result;
        }
