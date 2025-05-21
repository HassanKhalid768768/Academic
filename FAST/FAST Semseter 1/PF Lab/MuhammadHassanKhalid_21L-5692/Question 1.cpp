#include <iostream>
using namespace std;

int main()
{
    int Sum=0,number;
  cout<<"How many items to add? "; 
cin>>number;
int i=1;
for(int j=1;j<=number;j++){

Sum=Sum+(i*i*i);
i=i+2;
}
cout<<"Sum is "<<Sum;
    return 0;
}