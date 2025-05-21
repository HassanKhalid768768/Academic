using namespace std;
#include <iostream>
int main(){
    int Code;
    cout<<"Enter any ASCII Code: "<<endl;
    cin>> Code;
    if (Code > 64 & Code <91 ){
        cout <<"Represents an upper case English alphabet"<<endl;
    }
    else{
        if (Code>96 & Code<123){
            cout<<"Represents a lower case english alphabet"<<endl;
        }
    else{
        if (Code>47 &Code<58){
            cout<< "Represents a digit"<<endl;
        }
    else{
        if (Code<128){
            cout<<"Represents a special character"<<endl;
        }
        else{
            cout<<"DOES NOT REPRESENT AN ASCII CHARACTER"<<endl;
        }
    }
    }
    }
 cout<<"THE END";
 return 0;
}