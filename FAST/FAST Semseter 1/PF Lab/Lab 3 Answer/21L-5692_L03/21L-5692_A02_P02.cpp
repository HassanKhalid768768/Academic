#include <iostream>

using namespace std;

int main()
{
    int Smallest,Counter=0;
    double Average,Number,Sum=0;
   
    cout<<"Please Enter Your Numbers and a non-positive number to terminate ";
    cin>>Number;
    Smallest=Number;
   
    while(Number>0){
        Sum+=Number;
        cout<<"Please Enter a Number ";
        cin>>Number;
        Counter+=1;
        if (Number<Smallest && Number>=0){
            Smallest=Number;
        }
    }
    (Average=Sum/Counter);
cout<<endl<<"Sum of the numbers you entered is "<<Sum<<endl;
cout<<endl<<"Average of the 10 numbers is "<<Average<<endl;
cout<<endl<<"Smallest number is "<<Smallest<<endl<<"The End";
    return 0;
}
