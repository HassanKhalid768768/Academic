#include<iostream>
using namespace std;
class ComplexNumber
{
private:
    int real;
    int imaginary;
    static int count;

public:

    ComplexNumber(int a=0, int b=0)
    {
        real =a;
        imaginary =b;
    }

    ~ComplexNumber(){}

    void Input(int i , int j)
    {
        real = i;
        imaginary = j;
    }
    void Output();
    static int countDisplay;
    bool IsEqual(ComplexNumber);
    ComplexNumber Conjugate()
    {

            if(imaginary<0)
            {
        cout<<"the number : "<<real<<imaginary<<"i"<<endl;
        cout<<"the conjugate : " <<real<<"+"<<imaginary*(-1)<<endl;
            }
            else
            {
                cout<<"the number :" <<real<<"+"<<imaginary<<"i"<<endl;
                cout<<"the conjugate : "<<real<<"-"<<imaginary<<"i"<<endl;
            }
            return 0;
    }

    ComplexNumber  operator+ (const ComplexNumber & num)
    {

    cout<<"Addition : ";
    cout<<this->real+num.real<<"+"<<this->imaginary+num.imaginary<<"i";
return 0;
    }

    ComplexNumber  operator- (const ComplexNumber & num)
    {
     cout<<"Subtraction : "<<this -> real - num.real<<" "<<this->imaginary - num.imaginary<<"i";
     return 0;
    }

    ComplexNumber  operator* (const ComplexNumber & num)
    {
        cout << "Multiplication : "<<this -> real * num.real<<"+"<<this -> imaginary * num.imaginary<<"i";
        return 0;
    }

   ComplexNumber   operator ++(int)
    {
        cout<<"Pre-Increment: "<<++this -> real<<"+"<<++this -> imaginary<<"i";
        return 0;
    }
    ComplexNumber   operator --(int)
    {
        cout<<"Pre-Decrement: "<<--this -> real<<"+"<<--this -> imaginary<<"i";
        return 0;
    }

    ComplexNumber operator ++()
    {
        cout<<"Post-Increment: "<<this -> real++<<"+"<<this -> imaginary++<<"i";
        return 0;
    }
    ComplexNumber  operator --()
    {
        cout<<"Post-Decrement: "<<this -> real--<<"+"<<this -> imaginary--<<"i";
        return 0;
    }
    bool operator>(const ComplexNumber& num)
    {
        if(((this->real) > (num.real)) && ((this->imaginary) > (num.imaginary)))
        {
            return true;
        }
        else
        {
                return false;
        }
    }
    bool operator<(const ComplexNumber& num)
    {
        if(((this->real) < (num.real)) && ((this->imaginary) < (num.imaginary)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(const ComplexNumber& num)
    {
        if(((this->real) != (num.real)) && ((this->imaginary) != (num.imaginary)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    ComplexNumber c1,c2;
    int real,imag,real1,imag1;
    cout<<"Enter first number:- "<<endl;
    cout<<"Real = ";
    cin>>real;
    cout<<"Imaginary = ";
    cin>>imag;
    cout<<endl;
    cout<<"Enter second number:- "<<endl;
    cout<<"Real = ";
    cin>>real1;
    cout<<"Imaginary = ";
    cin>>imag1;
    cout<<endl;
    c1.Input(real,imag);
    c2.Input(real1, imag1);
    cout<<endl;
    c1.Conjugate();
    cout<<endl;
    c2.Conjugate();
    cout<<endl;
   c1+c2;
    cout<<endl;
    c1-c2;
    cout<<endl;
    c1*c2;
    cout<<endl;
    c1++;
    cout<<endl;
    c2++;
    cout<<endl;
    ++c1;
    cout<<endl;
    ++c2;
    cout<<endl;
    --c1;
    cout<<endl;
    --c2;
    cout<<endl;
    c1--;
    cout<<endl;
    c2--;
    cout<<endl;
    if(c1.operator!=(c2)==1)
    {
        cout<<"Not Equal";
    }
    else
        cout<<"Equal";
    if(c1.operator> (c2) ==1)
    {
        cout<<endl<<"first number greater than second number";
    }
    if(c1.operator<(c2)==1)
    {
        cout<<endl<<"first number lesser than second number";
    }

    return 0;
}