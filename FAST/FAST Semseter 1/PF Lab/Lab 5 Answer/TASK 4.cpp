#include<iostream>
using namespace std;

int main()
{
	int amt,R100,R50,R10,R1;
	cout<<"Enter amount : ";
	cin>>amt;
	R100=amt/100;
	amt=amt%100;
	R50=amt/50;
	amt=amt%50;
	R10=amt/10;
	amt=amt%10;
	R1=amt;
	cout<<"Rs.100 : "<<R100<<endl<<"Rs. 50 : "<<R50<<endl<<"Rs. 10 : "<<R10<<endl<<"Rs. 1 : "<<R1<<endl;

	
	return 0;
}
