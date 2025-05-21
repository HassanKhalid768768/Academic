#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int presentMenu(){
    int Choice = 0;
    do{
        cout<<"1. Encrypt data"<<endl<<endl
            <<"2. Decrypt data"<<endl<<endl
            <<"Enter Your Choice (1 or 2) ";
        cin >> Choice;
    }while(Choice < 1 || Choice > 2);

    return Choice;
}

int main()
{
    int Selection = 0;
  char a[100];
        Selection = presentMenu();

        if(Selection==1){
      ifstream inFile;
        inFile.open("input.txt");
        for(int count=0;count<100;count++){
inFile>>a[count];
}

for(int count=0;count<100;count++){
a[count]=((int)a[count]+1);
}
cout<<endl;

for(int count=0;count<100;count++){
cout<<(a[count]);
}

ofstream outFile;
outFile.open("encrypt.txt");
for(int count=0;count<100;count++){
outFile<<(a[count]);
}
        }

       else if(Selection==2){

            ifstream inFile;
        inFile.open("encrypt.txt");
        for(int count=0;count<100;count++){
inFile>>a[count];
}

for(int count=0;count<100;count++){
a[count]=((int)a[count]-1);
}
cout<<endl;

for(int count=0;count<100;count++){
cout<<(a[count]);
}
ofstream outFile;
outFile.open("decrypt.txt");
for(int count=0;count<100;count++){
outFile<<(a[count]);
}


       }
    return 0;
}
