#include <iostream>
using namespace std;

int main()
{
    double totalcost,cost;
  int stop=0;
  while (stop!=1){
  int duration,day;
  double starttime;
  
  cout<<"Enter Day: "<<endl;
  cout<<"1: For Monday"<<endl;
  cout<<"2: For Tuesday"<<endl;
  cout<<"3: For Wednesday"<<endl;
  cout<<"4: For Thursday"<<endl;
  cout<<"5: For Friday"<<endl;
  cout<<"6: For Saturday"<<endl;
  cout<<"7: For Sunday"<<endl;
  cin>>day;
  
  cout<<"Enter Start Time"<<endl<<"Start Time should be in 24-hour notation"<<endl<<"Like For 8 am enter 8"<<endl<<"Like for 8 30 am enter 8.30"<<endl<<"like for 8 pm enter 20"<<endl;
  cin>>starttime;
  
  cout<<"Enter duration:"<<endl;
  cin>>duration;
  
  if(day>=1 && day<=5){
      if(starttime>=8 && starttime<=18){
          cost=duration*0.4;
          cout<<"Cost of Call : $"<<cost;
      }
      if(starttime<8 || starttime>18){
          cost=duration*0.25;
          cout<<"Cost of Call : $"<<cost;
      }
  }
   if(day==6 || day==7){
       cost=duration*0.15;
  cout<<"Cost of Call : $"<<cost;
   }
   cout<<endl<<endl;
   cout<<"If you want to stop enter 1 else enter 0";
   cout<<endl;
   cin>>stop;
   totalcost=totalcost+cost;
  }
    cout<<"Total Cost : $"<<totalcost;
    return 0;
}