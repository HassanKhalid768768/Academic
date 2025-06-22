#include <iostream>
using namespace std;

class LocalPhone
{
private:
string phone;
public:
void input()
{
cin >> phone;
}
void display()
{
cout << phone;
}
};


class NatPhone : public LocalPhone
{
private:
string cityCode;
public:
void input()
{
cin >> cityCode;
}
void display()
{
cout << cityCode;
}
};


class IntPhone : public NatPhone
{
private:
string countryCode;
public:
void input()
{
cin >> countryCode;
}
void display()
{
cout << countryCode;
}
};




int main()
{
	LocalPhone l;
	NatPhone n;
	IntPhone i;
	
	cout << "Enter Your Country Code: ";
    i.input();
    cout << "Enter Your City Code : ";
    n.input();
    cout << "Enter Your Phone Number : ";
    l.input();
    cout<<endl;
    cout<<"Your Phone Number : ";
    i.display();
    cout<<" (";
    n.display();
    cout<<") ";
    l.display();
    


    return 0;
}