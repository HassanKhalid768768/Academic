#include <bits/stdc++.h>
using namespace std;

class Roman{

public:

    int setNumber(string temp){
    int num;
    num=romanToDecimal(temp);
    return num;
    }

int romanToDecimal(string& roman)
{
    int result = 0;

    for (int i = 0; i < roman.length(); i++) {
        int s1 = value(roman[i]);

        if (i + 1 < roman.length()) {
            int s2 = value(roman[i + 1]);
            if (s1 >= s2) {
                result = result + s1;
            }
            else {
                result = result + s2 - s1;
                i++;
            }
        }
        else {
            result = result + s1;
        }
    }
    return result;
}

int value(char rom)
{
    if (rom == 'I')
        return 1;
    if (rom == 'V')
        return 5;
    if (rom == 'X')
        return 10;
    if (rom == 'L')
        return 50;
    if (rom == 'C')
        return 100;
    if (rom == 'D')
        return 500;
    if (rom == 'M')
        return 1000;

    return -1;
}
};





int integertoroman(int number)
{
int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
int i=12;
while(number>0)
{
int div = number/num[i];
number = number%num[i];
while(div--){cout<<symbol[i];}
i--;
}
}

string upper(string& s){
    for(int i=0 ; i<s.length() ; i++){
            if((int)s[i]>=97 && (int)s[i]<=122){
        s[i]=(char)((int)s[i]-32);
        }
    }
    return s;
}

int main(){
   Roman roman1,roman2;
   string temp1,temp2;
   int num1, num2, result, result2, result3, result4, op;
   cout<<"Enter Roman Number 1 : ";
   getline(cin,temp1);
   upper(temp1);
   num1=roman1.setNumber(temp1);
   cout<<"Enter Roman Number 2 : ";
   getline(cin,temp2);
   upper(temp2);
   num2=roman2.setNumber(temp2);
   cout<<"Enter the operator \n 1 + \n 2 - \n 3 * \n 4 / \n 5 == or != \n 6 < or > \n 7 ++ post first number \n 8 ++ pre first number \n 9 ++ post second number \n 10 ++ pre second number \n 11 -- post first number \n 12 -- pre first number \n 13 -- post second number \n 14 -- pre second number \n";
   cin>>op;
   cout<<endl;
   switch(op)
   {
       case 1:
           result = num1+num2;
           cout<<"Result after addition is : ";
       break;

   case 2:
       result = num1-num2;
       cout<<"Result after subtraction is : ";
   break;

   case 3:
           result = num1*num2;
           cout<<"Result after multiplication is : ";
   break;

   case 4:
           result = num1/num2;
           cout<<"Result after division is : ";
   break;

       case 5:
          if ( num1 == num2 ){
            cout<<temp1<<" is equal to "<<temp2<<endl;
           }
           else{
            cout<<temp1<<" is not equal to "<<temp2<<endl;
           }
           break;

       case 6:
           if ( num1 < num2 ) {
            cout<<temp1<<" is smaller than "<<temp2<<endl;
           }
           else{
            cout<<temp1<<" is greater than "<<temp2<<endl;
           }
           break;

       case 7:
           result = num1++;
           cout<<"Result after post-incrementation for first number is : ";
           break;

       case 8:
            result = ++num1;
           cout<<"Result after pre-incrementation for first number is : ";
           break;

       case 9:
           result = num2++;
           cout<<"Result after post-incrementation for second number is : ";
           break;

       case 10:

          result = ++num2;
           cout<<"Result after pre-incrementation for second number is : ";
           break;

        case 11:

          result = num1--;
           cout<<"Result after post-decrementation for first number is : ";
           break;

           case 12:

          result = --num1;
           cout<<"Result after pre-decrementation for first number is : ";
           break;

           case 13:

          result = num2--;
           cout<<"Result after post-decrementation for second number is : ";
           break;

           case 14:

          result = --num2;
           cout<<"Result after pre-decrementation for second number is : ";
           break;

   default:
   cout << "Error! operator is not correct";
   break;
   }
   integertoroman(result);

   cout<<endl;

   return 0;
}
