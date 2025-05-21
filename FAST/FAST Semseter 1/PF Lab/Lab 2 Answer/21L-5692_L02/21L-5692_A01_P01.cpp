using namespace std;
#include <iostream>
int main(){
    int A,B,C;
    cin>> A>>B>>C;
    if (A<=0 ||B<=0||C<=0){
        cout<< "All angles must be positive"<<endl;
    }
    else{
        if (A+B+C==180){
            cout<<"A Triangle can be formed using these angles"<<endl;
    }
    else{
        cout<<"A Triangle cannot be formed using these angles"<<endl;
        }
}
 cout<<"THE END";
   return 0;
}