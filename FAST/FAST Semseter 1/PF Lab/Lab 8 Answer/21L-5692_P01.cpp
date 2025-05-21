#include<iostream>
using namespace std;

string isOdd(int number) {
if (number<0){
    number*=-1;
}
if (number%2==0){
    return "FALSE";
}
    else{
        return "TRUE";
}
}

int main() {
int n;
cin >> n;
cout << isOdd(n)<< endl;
return 0;
}