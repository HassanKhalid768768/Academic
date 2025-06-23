#include <iostream>
using namespace std;

class Person{
	string name;
	int id;
	int age;
	
	public:
		
		Person(int ID,string NAME,int AGE){
				cout<<"In constructor of class Person"<<endl;
				id=ID;
			name=NAME;
				age=AGE;
		}
		
		int getName(){
			cout<<name;
		}
		
		int getage(){
			cout<<age;
		} 
		void Print(){
			cout<<"Name : "<<name;
			
			cout<<endl;
		}
		
		
		~Person(){
			cout<<"In Destructor of class Person"<<endl;
		}
		
};

class Student:public Person{
	float cgpa;
	string rollnumber;
    
    public:
    	
	Student(float gpa,string roll_number){
		cout<<"In constructor of class Student"<<endl;
		cgpa=gpa;
		rollnumber=roll_number;
	}
	
	void input(){
		cin>>ID;
		cin>>name;
		cin>>cgpa;
		cin>>rollNumber;
		cin>>age;
	}
	
	void Print(){
		cout<<getName()<<" is "<<getage()<" years old, his cgpa is "<<cgpa;
	}
	
	int getcgpa(){
		cout<<cgpa;
	}
	
	~Student(){
	cout<<"In Destructor of class Student"<<endl;
	}
};

class Undergraduate:public Student{
	string fyp_name;
	
	public:
		
	Undergraduate(string FYP_NAME){
		cout<<"In constructor of class Undergraduate"<<endl;
		fyp_name=FYP_NAME;
	}
	
		void input(){
			cout<<"Enter final year project name";
		cin>>fyp_name;
	}
	
	
	void Print(){
		cout<<getName()<<" is a undergraduate student, his cgpa is "<<getcgpa()<<"and his final year project is titled as "<<fyp_name<<endl;
		}
	
	
	~Undergraduate(){
		cout<<"In Destructor of class Undergraduate"<<endl;
	}
};

class Graduate:Public Student{
	string thesis;
	string SupervisorName;
	
	public:
		
		Graduate(string THESIS,string SUPERVISORNAME){
			cout<<"In constructor of class Graduate"<<endl;
			thesis=THESIS;
			SupervisorName=SUPERVISORNAME;
		}
		
		void input(){
			cout<<"Enter thesis";
		cin>>thesis;
		cout<<"Enter Supervisor Name";
		cin>>SupervisorName;
	}
	
		void Print(){
			cout<<getName()<<" is a graduate student, his cgpa is "<<getcgpa()<<"and his thesis topic is "<<thesis<<" under supervision of "<<SupervisorName<<endl;
		}
		
		
		~Graduate(){
		cout<<"In Destructor of class Graduate"<<endl;
	}
};


int main(){
	
	Person p1;
	Student s1;
	Graduate g1;
	Undergraduate ug1;
	
	
	
	
	
	
	return 0;
}
