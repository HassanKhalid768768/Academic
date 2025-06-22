#include <bits/stdc++.h>

using namespace std;

class Point {
private:
   int *x, *y;
public:

   Point(int x, int y) {
       this->x = new int(x);
       this->y = new int(y);
   }

   void setX(int x) {
       this->x = new int(x);
   }
   void setY(int y) {
       this->y = new int(y);
   }

   int getX() {
       return *(this->x);
   }
   int getY() {
       return *(this->y);
   }

   ~Point() {
       delete x;
       delete y;
   }
};

class Circle {
private:
   float *radius;
   Point *coordinate;
public:

   Circle(float radius, int x, int y) {
       this->radius = new float(radius);
       this->coordinate = new Point(x, y);
   }

   void setRadius(float radius) {
       this->radius = new float(radius);
   }
   void setCoordinate(int x, int y) {
       this->coordinate = new Point(x, y);
   }

   float getRadius() {
       return *(this->radius);
   }
   Point *getCoordinate() {
       return this->coordinate;
   }
   bool CheckOnCircle(Point& p1) {
       float temp = sqrt((coordinate->getX()-p1.getX())^2 + (coordinate->getY()-p1.getY())^2);
       if ( (temp <= *radius) == 1 ) {
         cout<<"Point lies in Circle"<<endl;
       }
       else {
        cout<<"Point does not lie in Circle"<<endl;
       }
       return 0;
       }


   ~Circle() {
       delete radius;
       delete coordinate;
   }
};

class Cylinder {
private:
   int height;
   Circle *top, *bottom;
public:

   Cylinder(int height, float topRadius, int topX, int topY, float bottomRadius, int bottomX, int bottomY) {
       this->height = height;
       this->top = new Circle(topRadius, topX, topY);
       this->bottom = new Circle(bottomRadius, bottomX, bottomY);
   }
   bool CheckOnCylinder(Point& p1) {
       if( ( (top->CheckOnCircle(p1) || bottom->CheckOnCircle(p1)) ) == 1 ) {
        cout<<"Point lies in Cylinder"<<endl;
       }
       else {
        cout<<"Point does not lie in Cylinder"<<endl;
       }
       return 0;
   }

   ~Cylinder() {
       delete top;
       delete bottom;
   }
};

int main(void) {
   Point p1(2, 4);
   Circle c1(5.3, 2, 3);
   Cylinder cl1(7, 5.3, 2, 9, 5.3, 2, 3);
   cl1.CheckOnCylinder(p1);
   return 0;
}
