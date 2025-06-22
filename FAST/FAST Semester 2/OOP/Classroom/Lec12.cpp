//Lecture: April 1, 2022
//Usama Hassan Alvi
#include<iostream>
using namespace std;
//Example#1: 
//static and dynamic array of objects
//static array of pointers of objects

//class student
//{
//	int id;
//	float cgpa;
//public:
//	student(int = 0, float = 0.0);
//	void setId(int = 0);
//	void setCGPA(float = 0.0);
//	float getCGPA() const;
//	int getId() const;
//	void show() const;
//};
//student::student(int sId, float c)
//{
//	id = sId;
//	cgpa = c;
//}
//void student::setId(int sId)
//{
//	this->id = sId;
//}
//void student::setCGPA(float c)
//{
//	this->cgpa = c;
//}
//int student::getId() const
//{
//	return this->id;
//}
//float student::getCGPA() const
//{
//	return this->cgpa;
//}
//void student::show() const
//{
//	cout << "id = " << this->id << " " << "cgpa " << this->cgpa << endl;
//}
//
//int main()
//{
//	student * ptr = new student(7001, 3.5); //create an object of class on heap.
//	//cout << ptr->getId(); //Arrow operator (->) is used to access the data members of class through pointer
//	
//	student s_arr[2]; // static array of objects 
//	int size = 3;
//	student *d_arr = new student[size]; // dynamic array of objects
//	int id;
//	float c;
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "Enter id and cgpa: ";
//		cin >> id >> c;
//		s_arr[i].setId(id);
//		s_arr[i].setCGPA(c);
//	}
//
//	student * p_arr[3]; //static array of pointers of object
//	student s1(7008, 3.8); // object of class
//	p_arr[1] = &s1; //since it is an array of pointers so store the address of object.
//
//	//Another way to assign objects to each index of array of pointers.
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Enter id and cgpa: ";
//		cin >> id >> c;
//		p_arr[i] = new student(id, c);//create an object on each index location
//		cout << p_arr[i]->getCGPA();
//	}
//	system("pause");
//}


//Example#2:
//static data members and static member functions
//we use static data members when we need shared object.
//static data member is not dependent on the object of class.You can access its value without declaring the object of class
//preferably static data members are initialized outside the class.
//since static data members are not dependent class it means you can access them without declaring object of class.
//one way is to keep the static data member public and access the value using className
//like,  process::count , here process is the className and count is the static data member
//but data members should be private. so we can not directly access the private data members.
//How can we access the static data members now?
//through getter functions? but we know that we can not access the member functions of class without object.
//so we need a method that can be called without object of class.
//here we introduce static Member functions. They can be called by using className like, process::getCount()
//you can only access static data members inside static member functions.

class process
{
	int id;
	static int count; //static data member to keep the count of total number of processes(objects)
public:
	process(int = 0);
	void setId(int);
	int getId();
	static int getCount(); //static member function
	~process(); //decrease the value of count when object is going to destroy
};
int process::count = 0; //initialization of static data member

process::process(int pId)
{
	id = pId;
	count++; 
//We know that constructor will be called automatically when the object is created. 
//so increment the value of count to keep track of total number of processes.
}
void process::setId(int pId)
{
	this->id = pId;
}
int process::getId()
{
	return this->id;
}
int process::getCount()
{
//static member functions can be called without object and we know that non-static data members
//are dependent on object. so you can not access non-static data members inside static member functions
	//cout << id << endl; //compile time error
	return count;
}

process::~process()
{
	count--;
}
int main()
{
	//cout << process::count << endl; //we can not directly access private data members 
	cout << process::getCount() << endl; //calling static member function without object
	process p1(765), p2(896);
	int n = 4;
	if (n == 4)
	{
		process p3(540);
		cout << p2.getCount()
	}
	cout << p1.getCount() << endl;
	system("pause");
}

//Example#3:
//operator overloading:
//Functionality of the operators (arithmetic,relational, assignment, stream insertion and extraction) defined for
//built-in data types. e.g, we can add two variables of int data type (x+y) but we can not add two objects like (s1 + s2 here s1 and s2
//are the objects of class) without overloading the operator.

class complex
{
	int real;
	int imaginary;
public:
	complex(int = 0, int = 0);
	void setR(int);
	void setI(int);
	int getR() const;
	int getI() const;
//overloading + operator
//This method will recieve an object as parameter and return an object to calling function.
	complex operator+(complex); 
	void show();
};

complex::complex(int r, int i)
{
	real = r;
	imaginary = i;
}
void complex::setR(int r)
{
	this->real = r;
}
void complex::setI(int i)
{
	this->imaginary = i;
}
int complex::getR() const
{
	return this->real;
}
int complex::getI() const
{
	return this->imaginary;
}
complex complex::operator+(complex c)
{
	complex c_obj;
	c_obj.real = this->real + c.real;
	c_obj.imaginary = this->imaginary + c.imaginary;
	return c_obj;
}
void complex::show()
{
	cout << "Real = " << this->real << "\n";
	cout << "Imaginary = " << this->imaginary << "\n";
}
int main()
{
	complex c1(3, 6), c2(4, 9);
//you can not add the objects of user defined dataTypes without overloading + operator
	complex c3 = c1 + c2; //here c1 is the calling object and c2 will be received as parameter
	c3.show();
}