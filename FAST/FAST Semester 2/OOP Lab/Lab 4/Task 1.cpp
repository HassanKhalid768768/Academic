#include<iostream>
using namespace std;

class student {
private:
        string name;
        float Eng,Math,Science;
        float total;
        
public:
	void Take_Data(){
		cout<<"Enter Name : ";
		cin>>name;
		cout<<endl<<"Enter English Marks : ";
		cin>> Eng;
		cout<<endl<<"Enter Math Marks : ";
		cin>> Math;
		cout<<endl<<"Enter Science Marks : ";
		cin>> Science;
		ctotal(Eng,Math,Science);
		
	}
	

	void ctotal(float Eng,float Math,float Science){
		float total;
		total=Eng+Math+Science;
		Show_Data(name,Eng,Math,Science,total);
	}
	
	void Show_Data(string name,float Eng,float Math,float Science,float total){
		cout<<endl<<"Name : "<<name<<endl;
		cout<<"English Marks : "<<Eng<<endl;
		cout<<"Math Marks : "<<Math<<endl;
		cout<<"Science Marks : "<<Science<<endl;
		cout<<"Total Marks : "<<total<<endl<<endl;
	}
};

int main(){
	student s1,s2;
	s1.Take_Data();
	s2.Take_Data();
}
