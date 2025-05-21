using namespace std;
#include <iostream>
int main(){
    int Year;
    cin>> Year;
    if (Year % 400 ==0){
        cout<< Year<<"IS A LEAP YEAR"<<endl;
    }
    else{
        if (Year % 100 ==0){
            cout<< Year<<"IS NOT A LEAP YEAR"<<endl;
        }
    else{
        if(Year % 4==0){ 
             cout<< Year<<"IS A LEAP YEAR"<<endl;
        }
        else{
            cout<< Year<<"IS NOT A LEAP YEAR"<<endl;
        }
}
}
 cout<<"THE END";
   return 0;
}