#include <iostream>
using namespace std;

int Euclid_GCD(int n1,int n2);

  int main() 
  {
  int m, n;
  cout << "Enter two numbers: ";
  cin >> m >> n;
  
  if ( m < 0 ) {
      m = m * -1;
  }
if ( n < 0 ) {
      n = n * -1;
  }

  if ( n > m) {   
    int temp = n;
    n = m;
    m = temp;
  }
    
 cout << "GCD = " << Euclid_GCD(m,n);
  return 0;
}

int Euclid_GCD(int n1,int n2){
    int Remainder,GCD;
Remainder = n1 % n2;
 while ( Remainder > 0 ) {
     n1 = n2;
     n2 = Remainder;
     Remainder = n1 % n2;
 }
GCD=n2;
return GCD;
 }