#include "quaternion.cpp"
#include "shape.cpp"
#include <iostream>
#include <cmath>
#define PI 3.141592653589793

using namespace std;

Point rotate(Quaternion q, Point p){
    Point r;
    r.x = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.b) + (q.a*p.x + q.c*p.z - q.d*p.y)*(q.a) + (q.a*p.y - q.b*p.z + q.d*p.x)*(-q.d) - (q.a*p.z + q.b*p.y - q.c*p.x)*(-q.c));
    r.y = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.c) - (q.a*p.x + q.c*p.z - q.d*p.y)*(-q.d) + (q.a*p.y - q.b*p.z + q.d*p.x)*(q.a) + (q.a*p.z + q.b*p.y - q.c*p.x)*(-q.b));
    r.z = ((-q.b*p.x - q.c*p.y - q.d*p.z)*(-q.d) + (q.a*p.x + q.c*p.z - q.d*p.y)*(-q.c) - (q.a*p.y - q.b*p.z + q.d*p.x)*(-q.b) + (q.a*p.z + q.b*p.y - q.c*p.x)*(q.a));
    return r;
}

int main(){
    Shape rectangle;
    rectangle.vertices.push_back(Point(1,-0.5,-0.5));
    rectangle.vertices.push_back(Point(-1,0.5,-0.5));
    rectangle.vertices.push_back(Point(1,0.5,-0.5));
    rectangle.vertices.push_back(Point(-1,-0.5,0.5));
    rectangle.vertices.push_back(Point(1,-0.5,0.5));
    rectangle.vertices.push_back(Point(-1,0.5,0.5));
    rectangle.vertices.push_back(Point(1,0.5,0.5));
    rectangle.vertices.push_back(Point(-1,-0.5,-0.5));

    Shape rotatedShape;

    //x^2 + y^2 + z^2 must = 1
    double vector [3] = {0, 1, 0};
   
    if(pow(vector[0],2) + pow(vector[1],2) + pow(vector[2],2) != 1){
        
    }

    double angle;
    cout << "Insert angle: ";
    cin >> angle;
    angle *= (PI/180);

    //create a quaternion using the formula
    Quaternion q1(vector, angle);
    
    for(int i = 0; i < rectangle.vertices.size(); i++){
        //store each rotated point in a new shape's vertices
        rotatedShape.vertices.push_back(rotate(q1, rectangle.vertices[i]));
    }


    cout << "Rotated Shape:\n";
    for(int i = 0; i < rotatedShape.vertices.size(); i++){
        
        //rounding
        if(abs(rotatedShape.vertices[i].x) < 0.001){
            rotatedShape.vertices[i].x = 0;
        }
        if(abs(rotatedShape.vertices[i].y) < 0.001){
            rotatedShape.vertices[i].y = 0;
        }
        if(abs(rotatedShape.vertices[i].z) < 0.001){
            rotatedShape.vertices[i].z = 0;
        }

        //print the point into console
        rotatedShape.vertices[i].print();
    }

}
