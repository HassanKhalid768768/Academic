#include<iostream>
#include<cstring>
using namespace std;
class Tyre
{
private:
int* width;
int* aspect_ratio;
int* diameter;

public:
//Constructors, Getters and Destructor

// Constructors
Tyre()
{
    width = new int;


}

Tyre(int a , int b , int c)
{
    width = new int;
    *width = a;
    aspect_ratio = new int;
    *aspect_ratio = b;
    diameter = new int;
    *diameter = c;
}

// Getter Functions
int *GetWidth()
{
    return this->width;
}

int *GetAspect_Ratio()
{
    return this->aspect_ratio;
}

int *GetDiameter()
{
    return this->diameter;
}
void  PrintTyre()
{
    cout<<"Width: "<<*this->width;
    cout<<endl;
    cout<<"Aspect Ratio: "<<*this->aspect_ratio<<endl;
    cout<<"Diameter: "<<*this->diameter<<endl;
}

~Tyre() //Destructor
{
    delete width;
    delete aspect_ratio;
    delete diameter;
}
};
class Car
{
private:
int *model;
string* company;
Tyre* t1;

public:
//Constructors, Destructor

Car(int p , const string q , Tyre r)
{
    model = new int;
    *model = p;
    company = new string;
    *company = q;
    t1 = new Tyre;
    *t1 = r;
}

void  PrintCar()
{
    cout<<endl;
    cout<<endl;
    cout<<"Model: "<<*this->model<<endl;
    cout<<"Company: "<<*this->company<<endl;
    t1->PrintTyre();
}

~Car()
{
    delete model;
    delete company;
    delete t1;
}


};

int main()
{
     Tyre tNew(12,  10,  13);
     Car  cNew(2016,"Honda",tNew);
     tNew.PrintTyre();
     cNew.PrintCar();

}