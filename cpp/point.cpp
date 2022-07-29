#include <iostream>
using namespace std;

class Point{
public:
double x, y, z;

Point(double X = 0, double Y = 0, double Z = 0){
    x = X;
    y = Y;
    z = Z;
}

void print(){
    cout << "(" << x;
    cout << ", " << y;
    cout << ", " << z << ")";
    cout << endl;
}

};
