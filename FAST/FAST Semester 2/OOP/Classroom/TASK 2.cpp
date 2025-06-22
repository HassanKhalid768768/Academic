#include<iostream>
using namespace std;

class Fraction
{

    int numerator;
    int denominator;

    int Making_denominators_same(int x,int y)
    {
        if(y==0)
            return x;
        else
            return(x,Making_denominators_same(y,x%y));
    }


       public:
static int fractionsCount;
       Fraction()
       {      numerator=1;
              denominator=1;
              fractionsCount++;
       }


       Fraction(int x,int y)
       {
              numerator=x/Making_denominators_same(x,y);
              denominator=y/Making_denominators_same(x,y);
              fractionsCount++;
       }

       void display()
       {
              cout<<numerator<<"/"<<denominator;
       }

       void add(Fraction f1,Fraction f2)
       {
           fractionsCount++;
              if(f1.denominator==f2.denominator)
              {      numerator=f1.numerator+f2.numerator;
                     denominator=f1.denominator;

              }
              else
              {
                     numerator=(f1.numerator*f2.denominator)+(f1.denominator*f2.numerator);
                     denominator=f1.denominator*f2.denominator;
              }

       }

       void mul(Fraction f1,Fraction f2)
       {
           fractionsCount++;
              numerator=f1.numerator*f2.numerator;
              denominator=f1.denominator*f2.denominator;
       }

       bool isProper(Fraction f1,Fraction f2)
       {
           fractionsCount++;
           if(f1.numerator>f1.denominator){
            cout<<endl<<"This is a proper function";
           }
           else
           {
               cout<<endl<<"This is not a proper function";
           }
           if(f2.numerator>f2.denominator){
            cout<<endl<<"This is a proper function";
           }
           else
           {
               cout<<endl<<"This is not a proper function";
           }
       }

       bool operator > (Fraction & f){
           fractionsCount++;
       if((numerator/denominator)>(f.numerator/f.denominator))
       {
           cout<<endl<<endl<<"Fraction is greater than parameter f ";
       }
       else{
            cout<<endl<<endl<<"Fraction is not greater than parameter f ";
       }
       }
};


int Fraction::fractionsCount = 0;
int main()
{
       int num1,denom1,num2,denom2;
       cout<<"Enter Numerator of First Number : ";
       cin>>num1;
       cout<<"Enter Denominator of First Number : ";
       cin>>denom1;

       cout<<"Enter Numerator of Second Number : ";
       cin>>num2;
       cout<<"Enter Denominator of Second Number : ";
       cin>>denom2;

       Fraction Fraction1(num1,denom1),Fraction2(num2,denom2),Fraction3,Fraction4;

       cout<<"\nFraction 1 : ";
       Fraction1.display();
       cout<<"\nFraction 2 : ";
       Fraction2.display();
       cout<<"\nFraction 1 + Fraction 2 : ";
       Fraction3.add(Fraction1,Fraction2);
       Fraction3.display();
       cout<<"\nFraction 1 * Fraction 2 : ";
       Fraction3.mul(Fraction1,Fraction2);
       Fraction3.display();
       cout<<endl;
       Fraction1.isProper(Fraction1,Fraction2);
       Fraction1>Fraction4;
       cout<<endl<<endl<<"Total Number of fractions : "<<Fraction::fractionsCount;

}
