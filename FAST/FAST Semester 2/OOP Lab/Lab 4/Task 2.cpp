#include<iostream>
using namespace std;

class Phone {
private:
        
        int areacode,exchange,number;
        
public:
	
	    void Get_Phone(){
	    	cout<<"Enter your area code : ";
			cin>>areacode;
			cout<<"Enter your exchange : ";
			cin>>exchange;
			cout<<"Enter your number : ";
			cin>>number;
			Get_Phone2();
			Take_Phone(areacode,exchange,number);
		}
		
		void Get_Phone2(){
			Take_Phone2(212,767,8900);
		}
		
		void Take_Phone(int areacode,int exchange,int number){
				cout<<"Your number is ("<<areacode<<") "<<exchange<<"-"<<number;
		}
		void Take_Phone2(int areacode,int exchange,int number){
				cout<<endl<<"My number is ("<<areacode<<") "<<exchange<<"-"<<number<<endl<<endl;
		}
		
		
		
	
};

int main(){
	Phone s1,s2;
	s2.Get_Phone();

	
}
