#include <cmath>
class Quaternion{
public:
double a, b, c, d;

Quaternion(double V[3], double angle = 0){
    a = cos(angle/2);
    b = V[0] * sin(angle/2);
    c = V[1] * sin(angle/2);
    d = V[2] * sin(angle/2);
}

Quaternion conjugate(Quaternion q){
    q.b *= -1;
    q.c *= -1;
    q.d *= -1;
    return q;
}

};
