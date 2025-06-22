//25-March-2022
//Usama Hassan Alvi
#include <iostream>
#include <string>
using namespace std;

//Example#1:
//implementation of methods outside the class
//Use of this(->) pointer. this-> pointer is used to access the data of calling object.
//default parameterized cosntructor.
//const getter function.
//receiving an object of class as a parameter in member functions.

//class employee
//{
//	int empId;
//	string name;
//	string dept;
//public:
////default parameterized constructor. It is mandatory to mention the dataType of parameters and default values.
//	employee(int = 0, string = " ", string = " "); 
//	void setId(int);
//	void setName(string);
//	void setDept(string);
////constant member functions. It is a good practice to keep such member functions constant so 
////that these functions remain read only functions. Compiler report the error in case of any
////attempt to update the data members of class inside these functions.
//	int getId() const;  
//	string getDept() const;
//	string getName() const;
//	void show(employee) const; //receive an object of the class as parameter
//	void show() const; //overloading show function
//};
//
////syntax to define the methods of class outside the class
////returnType className:: functionName(parameters list...)
//
////since there is no return type for the constructor of the class
//employee::employee(int id, string n, string d)
//{
//	empId = id;
//	name = n;
//	dept = d;
//}
//
//void employee::setId(int id)
//{
//	this->empId = id;
//}
//void employee::setName(string n)
//{
//	this->name = n;
//}
//void employee::setDept(string d)
//{
//	this->dept = d;
//}
//
//int employee::getId() const
//{
//	return this->empId;
//}
//
//string employee::getName() const
//{
//	return this->name;
//}
//
//string employee::getDept() const
//{
//	return this->dept;
//}
//
//void employee::show(employee e) const
//{
//	cout << this->empId << " " << this->dept << " " << this->name << endl;
//	cout << e.empId << " " << e.dept << " " << e.name << endl;
//}
//
//int main()
//{
//	employee e1, e2;
//	e1.setId(7001);
//	e1.setName("Usama");
//	e1.setDept("CS");
//	e2.setId(8001);
//	e2.setName("Arif");
//	e2.setDept("DS");
//	e1.show(e2);
//	system("pause");
//	return 0;
//}


//
//Example#2:
//copy constructor (deep copy)
//resizing the array
//destructor to delete the dynamicallay allocated memory
//class student
//{
//	int * s_arr;
//	int size;
//public:
//	student(int = 0);
//	void setId(int, int); // value to be inserted and the corresponding index
//	student(const student &) ; //copy constructor
//	void show(student) const;
//	void reSize(int);
//	~student();
//};
//
//student::student(int s)
//{
//	size = s;
//	s_arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		s_arr[i] = 0;
//	}
//}
//
//void student::setId(int val, int index)
//{
//	if (index >= 0 && index < size)
//		s_arr[index] = val;
//	else
//		cout << "invalid index\n";
//}
////copy constructor: used to initialize newly created object with the data of existing object.
////receiving object by reference to avoid memory wastage.
////we know that whenever recieve a parameter by reference then any change in this 
////parameter can change the data of (actual parameter or argument) so keep the 
////parameter constant.
////Why we need to overload the copy constructor when compiler is providing you default copy constructor?
////default copy constructor provided by the compilet performs shallow copy.
////shallow copy? discussed in class.
//student::student(const student & s)
//{
//	size = s.size; // assign the size to the data member of calling object.
//	s_arr = new int[this->size]; 
//	for (int i = 0; i < this->size; i++)
//	{
//		s_arr[i] = s.s_arr[i]; //copy the data in the array of calling object.
//	}
//}
//
//void student::show(student s) const
//{
//	cout << "Data of calling object s1\n";
//	for(int i=0; i<this->size; i++)
//	{
//		cout << this->s_arr[i] << endl;
//	}
//	cout << "Data of parameter s2\n";
//	for (int i = 0; i<s.size; i++)
//	{
//		cout << s.s_arr[i] << endl;
//	}
//}
//
//void student::reSize(int n_size)
//{
//	int * arr = new int[n_size];
//	if (n_size < this->size)
//	{
//		for (int i = 0; i < n_size; i++)
//		{
//			arr[i] = this->s_arr[i];
//		}
//	}
//	else
//	{
//		int i;
//		for (i = 0; i < size; i++)
//		{
//			arr[i] = this->s_arr[i];
//		}
//		while (i < n_size)
//		{
//			arr[i++] = 0;
//		}
//	}
//	delete[] this->s_arr;
//	this->s_arr = arr;
//	this->size = n_size;
//}
//
//student::~student()
//{
//	delete[] this->s_arr;
//}
//
//int main()
//{
//	student s1(4);
//	int id;
//	cout << "Enter the data for s1\n";
//	for (int i = 0; i < 4; i++)
//	{
//		cout << "Enter the id: ";
//		cin >> id;
//		s1.setId(id, i);
//	}
//
//	student s2(s1);
//	s1.show(s2);
//
//	cout << "Enter the data for s2\n";
//	for (int i = 0; i < 4; i++)
//	{
//		cout << "Enter the id: ";
//		cin >> id;
//		s2.setId(id, i);
//	}
//	s1.show(s2);
//
//	s1.reSize(6);
//	s1.show(s2);
//	system("pause");
//}

//Example 3:
//Array of objects
//constructor will not be called if you are declaring array of objects
class student
{
	int age, sId;
	float cgpa;
public:
	student()
	{
		cout << "inside the default constructor\n";
	}

	void setAge(int a)
	{
		age = a;
	}

	void setId(int id)
	{
		sId = id;
	}

	void setCGPA(float c)
	{
		cgpa = c;
	}

	int getId()
	{
		return sId;
	}
	int getAge()
	{
		return age;
	}
	float getCGPA()
	{
		return cgpa;
	}
};

int main()
{
	student s[5]; //Array of objects.
//Remember! The constructor will not be invoked when we declare an array of objects.
	int a, id;
	float c;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter age: ";
		cin >> a;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter cgpa: ";
		cin >> c;
		s[i].setAge(a); //set the data members against each index of array of objects
		s[i].setCGPA(c);
		s[i].setId(id);
	}
}

//Example#4
//destructor: A method that is automatically called when object is destroyed.
//deAllocate the dynamically allocated memory inside the destructor.
//Sequence in which constructor and destructors will be called.
//Execute the code and check the output. 
class process
{
	int pId;
public:
	process(int = 0);
	~process();//destructor. It will be automatically invoked when object is destroyed
	int getId() const;
};

process::process(int id)
{
	pId = id;
	cout << "object created with PId = " << pId << endl;
}

process::~process()
{
	cout << "object destroyed with PId = " << pId << endl;
}

int process::getId() const
{
	return pId;
}
int main()
{
	process p1(7001), p2(8032);
	if (p1.getId() >= 7000)
	{
		process p3(6986);
	}
	process p4(9765);
}