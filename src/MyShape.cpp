#include "MyShape.h"

void MyShape::drawTriangle(ofPoint _center, float _radius){
    
    ofPolyline triangle;
    float x, y, radian;
    
    for(int i = 0; i < 3; i++) {
        radian = HALF_PI + i * (PI/3);
        x = _center.x + _radius * cos(radian);
        y = _center.y + _radius * sin(radian);
        triangle.addVertex(x, y);
    }
    
    triangle.draw();
    
}
