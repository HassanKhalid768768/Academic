#include <iostream>

using namespace std;

template <typename  T>

 isEqualTo(T a, T b){
 if(a==b){
    cout<<"Numbers are Equal"<<endl;
 }
 else{
    cout<<"Numbers are Not Equal"<<endl;
 }
 }

int main()
{
    int n1,n2;
    cout << "Enter Number 1 :";
    cin>>n1;
    cout << "Enter Number 2 :";
    cin>>n2;
    isEqualTo(n1,n2);
    return 0;
}
