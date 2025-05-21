#include <iostream>
using namespace std;

int SquareRoot(int number);

int main()
{
    int n;
    cout << "Enter number: ";
  cin >> n;
  
  if (n>0){
      cout<<"Square Root is :"<<SquareRoot(n);
  }
  else{
      cout<<"Square Root of a Negative Number Does Not Exsist";
  }
  return 0;
}

int SquareRoot(int number);
int Left=0,Right=number+1;
while (Right-Left)>