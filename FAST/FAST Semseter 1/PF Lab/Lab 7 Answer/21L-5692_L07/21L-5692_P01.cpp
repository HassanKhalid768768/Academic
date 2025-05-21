#include <iostream>
using namespace std;

void checkpalindrome(int number){
   int digit=0, rev=0;


     for(int num=number;num!=0;)
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     }
     
      if (number == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";
}

int main()
{
     int n;

     cout << "Enter a positive number: ";
     cin >> n;

checkpalindrome(n);


}