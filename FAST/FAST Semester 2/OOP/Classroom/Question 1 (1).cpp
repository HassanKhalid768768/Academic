#include <iostream>
#include <cmath>
using namespace std;

class VectorType
{

        private:
                double *x;
                double *y;
                double *z;

    friend bool operator == (const VectorType & , const VectorType &);
    friend bool operator != (const VectorType & , const VectorType &);
    friend istream& operator>>(istream& ,  VectorType &);
    friend ostream& operator<<(ostream& ,   VectorType &);

        public:

                VectorType()
                {
                        x = new double [0];
                        y = new double [0];
                        z = new double [0];
                }


                VectorType(double x1,double y1,double z1)
                {
                        x = new double {x1};
                        y = new double {y1};
                        z = new double {z1};
                }


                VectorType(const VectorType &v)
                {
                        x = new double {*v.x};
                        y = new double {*v.y};
                        z = new double {*v.z};
                }


                ~VectorType()
                {
                        delete[] x;
                        delete[] y;
                        delete[] z;
                }


                VectorType operator = (VectorType const &obj)
                {
                 VectorType temp;
                 temp.x = obj.x;
                 temp.y = obj.y;
                 temp.z = obj.z;
                 return temp;

        }


        double operator * (VectorType const &v)
        {
                        return (*x)*(*v.x)+(*y)*(*v.y)+(*z)*(*v.z);
                }


                double operator + (VectorType  &obj)
        {
            double d1=*x + *obj.x;
            double d2=*y + *obj.y;
            double d3=*z + *obj.z;
               cout<<"The Vector After Addition is : "<<d1<<" "<<d2<<" ";

               return d3;

                }


                double operator - (VectorType const &obj)
        {

                       double d1= *obj.x-*x;
            double d2= *obj.y - *y;
            double d3= *obj.z - *z;
               cout<<"The Vector After Subtraction is : "<<d1<<" "<<d2<<" ";

               return d3;
                }


                double length()
                {
                        return sqrt((*x)*(*x) + (*y)*(*y) + (*z)*(*z));
                }


                double angle(VectorType v)
                {
                        double dot = operator *(v);
                        double distance = length() * v.length();
                        return acos(dot/distance)*180/3.1415;
                }

double operator++(int)
   {
       cout<<++(*x)<<" "<<++(*y)<<" ";

       return ++(*z);
   }

   double operator--(int)
   {
       cout<<--(*x)<<" "<<--(*y)<<" ";

       return --(*z);
   }

   double operator++()
   {
       cout<<(*x)++<<" "<<(*y)++<<" ";

       return (*z)++;
   }

   double operator--()
   {
       cout<<(*x)--<<" "<<(*y)--<<" ";

       return (*z)--;
   }

bool operator ==(VectorType &V )
   {
       if((*x == *V.x) && (*y == *V.y) && (*z == *V.z))
       {
           return true;
       }
       else
        {
            return false;
       }
   }

    bool operator !=(VectorType &V)
   {
       if((*x != *V.x) || (*y != *V.y) || (*z != *V.z))
       {
           return true;
       }
        else
        {
            return false;
       }
   }
};

 istream &operator>>(istream& Output , VectorType& U)
   {
      Output >> *U.x;
      Output >> *U.y;
      Output >> *U.z;
   }

   ostream &operator <<(ostream&Input , VectorType &V)
   {
       Input << *V.x;
       Input << *V.y;
       Input << *V.z;
   }




int main(){



    double x1,x2,x3;

cout<<"Enter Value 1 : ";
cin>>x1;
cout<<"Enter Value 2 : ";
cin>>x2;
cout<<"Enter Value 3 : ";
cin>>x3;

VectorType U(x1,x2,x3);

cout<<endl<<"Enter Value 1 : ";
cin>>x1;
cout<<"Enter Value 2 : ";
cin>>x2;
cout<<"Enter Value 3 : ";
cin>>x3;

VectorType V(x1,x2,x3);

cout<<endl<<"Length of 1 st Vector : "<<U.length();
cout<<endl<<"Length of 2 nd Vector : "<<V.length();

cout<<endl<<endl<<"Dot Product of the Vectors : "<<U*V;

cout<<endl<<endl<<"Angle Between Vectors : "<<U.angle(V)<<" degrees ";

cout<<endl<<endl<<U+V;
cout<<endl<<U-V;

cout<<endl<<endl<<"Pre Increment "<<U++;
cout<<endl<<"Pre Increment "<<V++;
cout<<endl<<"Post Increment "<<++U;
cout<<endl<<"Post Increment "<<++V;
cout<<endl<<"Post Decrement "<<--U;
cout<<endl<<"Post Decrement "<<--V;
cout<<endl<<"Pre Decrement "<<U--;
cout<<endl<<"Pre Decrement "<<V--;

 if(U.operator==(V) == 1)
    {
        cout<<endl<<endl<<"Both The Vectors Are Equal"<<endl;
    }
     if(U.operator!=(V) == 1)
    {
        cout<<endl<<endl<<"Both The Vectors Are Not Equal"<<endl;
    }
}


