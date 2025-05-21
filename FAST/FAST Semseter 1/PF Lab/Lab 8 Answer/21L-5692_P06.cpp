#include<iostream>
using namespace std;

void swap(int alpha,int beta){
    int temp;
    
    temp=alpha;
    alpha=beta;
    beta=temp;
    
    cout<<alpha<<"  "<<beta;
}



int main() 
{
int a,b;
cout<<"Enter alpha and beta ";
cin>>a>>b;
cout<<endl<<endl;

swap(a,b);

}