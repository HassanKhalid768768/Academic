#include<iostream>
using namespace std;

class Date {
private:
        
        int Day;
		int Month;
		int Year;
		
public:
        
    Date(){
    	Day=01;
    	Month=01;
    	Year=1926;
	}
	
	void Print(){
	   	cout<<Day<<"/"<<Month<<"/"<<Year<<endl;
	}
		
	void Input(){
	   	cout<<"Enter Day : ";
	   	cin>>Day;
	   	cout<<endl<<"Enter Month : ";
	   	cin>>Month;
	   	cout<<endl<<"Enter Year : ";
	   	cin>>Year;
	}
	
	void SetDay(int DAY){
		Day=DAY;
	}
	
	void SetMonth(int MONTH){
		Month=MONTH;
	}
	
	void SetYear(int YEAR){
		Year=YEAR;
	}
	
	void GetDay(){
		cout<<Day<<"/";
	}
	
	void GetMonth(){
		cout<<Month<<"/";
	}
	
	void GetYear(){
		cout<<Year;
	}
	
	
};

int main(){
	
	Date date1,xmasDay;
	date1.Input();
	date1.Print();
	xmasDay.SetDay(25);
	xmasDay.SetMonth(12);
	xmasDay.SetYear(2020);
	cout<<endl<<"Date using Getter Functions : "<<endl;
	xmasDay.GetDay();
	xmasDay.GetMonth();
	xmasDay.GetYear();
	}
