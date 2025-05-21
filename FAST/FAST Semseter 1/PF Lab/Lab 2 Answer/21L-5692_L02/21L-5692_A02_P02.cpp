using namespace std;
#include <iostream>
int main(){
    int X,Y,XLT,YLT,XRB,YRB;
    cin>> X>>Y>>XLT>>YLT>>XRB>>YRB;
    if (X>XLT && X<XRB && Y>YLT && Y<YRB){
        cout<< "P lies inside the region"<<endl;
    }
    else{
       cout<< "P lies outside the region"<<endl;
    }
 cout<<"THE END";
   return 0;
}