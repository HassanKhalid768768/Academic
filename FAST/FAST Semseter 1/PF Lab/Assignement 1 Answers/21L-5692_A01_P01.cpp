using namespace std;
#include <iostream>
int main(){
    int Side1,Side2,Side3;
    cout<<"Enter Side 1"<<endl;
    cin >> Side1;
     cout<<"Enter Side 2"<<endl;
    cin >> Side2;
     cout<<"Enter Side 3"<<endl;
    cin >> Side3;
    if ((Side1*Side1) == (Side2*Side2)+(Side3*Side3)){
        cout<<"Pythagorean"<<endl;
    }
    else{
        cout<<"Not Pythagorean"<<endl;
    }
return 0;
}