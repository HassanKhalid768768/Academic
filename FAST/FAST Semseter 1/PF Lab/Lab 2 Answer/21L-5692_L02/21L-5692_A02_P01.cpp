#include <iostream>
using namespace std;
int main()
{
    int n,r,sum=0,p=1;
    cin>>n;
    if(n<100000)
    {
        cout<<"NOT A SIX DIGIT NUMBER:TOO SMALL";
    }
    else if(n>= 100000 && n <= 999999)
    {
        while(n>0)
        {
            r=n%10;
            n=n/10;
            sum=sum+r;
            p=p*r;
            
            
        }
    }
    else
    {
       cout<<"NOT A SIX DIGIT NUMBER:TOO SMALL";
    }
   cout<<"Sum: "<<sum<<" "<<"Product: "<<p;
    return 0;
}