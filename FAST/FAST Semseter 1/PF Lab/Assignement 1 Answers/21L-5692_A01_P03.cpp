using namespace std;
#include <iostream>
int main(){
    int Number;
    cout<<"Enter any Number between 1-10"<<endl;
    cin >> Number;
    do {
        cout<<"You have entered number out of range please enter again"<<endl;
        cout<<"Enter any Number between 1-10"<<endl;
            cin >> Number;
    }
    while ((Number<1 )||( Number>10));
    if (Number == 1){
        cout<<"Factorial of 1 is 1"<<endl;
    }
        if (Number == 2){
        cout<<"Factorial of 2 is 2"<<endl;
    }
        if (Number == 3){
        cout<<"Factorial of 3 is 6"<<endl;
    }
        if (Number == 4){
        cout<<"Factorial of 4 is 24"<<endl;
    }
        if (Number == 5){
        cout<<"Factorial of 5 is 120"<<endl;
    }
        if (Number == 6){
        cout<<"Factorial of 6 is 720"<<endl;
    }
        if (Number == 7){
        cout<<"Factorial of 7 is 5040"<<endl;
    }
        if (Number == 8){
        cout<<"Factorial of 8 is 40320"<<endl;
    }
        if (Number == 9){
        cout<<"Factorial of 9 is 362880"<<endl;
    }
      else{
        if (Number == 10){
        cout<<"Factorial of 10 is 3628800"<<endl;
    }
    }
return 0;
}