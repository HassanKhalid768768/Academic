using namespace std;
#include <iostream>
int main(){
    int Length,Height,Breadth,TotalArea;
    cout<<"Enter Length"<<endl;
    cin >> Length;
    cout<<"Enter Breadth"<<endl;
    cin >> Breadth;
    cout<<"Enter Height"<<endl;
    cin >> Height;
    TotalArea=((Length*Breadth)+(Length*Height)+(Breadth*Height)+(Length*Height)+(Breadth*Height));
    cout<<"Total Area :"<<TotalArea<<endl;
return 0;
}