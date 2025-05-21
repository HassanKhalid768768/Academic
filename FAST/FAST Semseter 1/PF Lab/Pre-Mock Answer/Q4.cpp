#include <iostream>
using namespace std;

int main()
{
   int i, j, temp;

   cout << "Enter number : ";
   cin >> temp;

   for(i = temp; i >= 1; i--)
   {
          if(i==temp){
              for(j = 1; j <= i; j++){
                  cout << "* ";
          }
          cout<<endl;
          }
         if(i<temp){
              for(j = 1; j <= i; j++){
                  if(j==1){
                  cout << "* ";
                  }
                  else if(j==i){
                      cout <<"* ";
                  }
                  else{
                      cout <<"  ";
                  }
              }
          
         
      cout <<endl;
          }
   }

   return 0;
}