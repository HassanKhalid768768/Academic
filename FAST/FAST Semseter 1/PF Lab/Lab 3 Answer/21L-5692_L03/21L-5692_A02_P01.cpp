#include <iostream>
using namespace std;

int main()
{
    int Largest=0,n,Counter=0;
     cout<<"Please Enter The Number of Entries ";
        cin>>n;
    double Average,Number,Sum;
    while (Counter<n){
        cout<<"Please Enter a Number ";
        cin>>Number;
        if (Number>Largest){
            Largest=Number;
        }
        Sum+=Number;
        Counter++;
    }
    (Average=Sum/n);
cout<<endl<<"Sum of the 10 numbers is "<<Sum<<endl;
cout<<endl<<"Average of the 10 numbers is "<<Average<<endl;
cout<<endl<<"Largest Number is  "<<Largest<<endl<<"The End";
    return 0;
}
