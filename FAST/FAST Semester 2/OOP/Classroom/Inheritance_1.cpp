////Inheritance#1
////Usama Hassan Alvi
////
////Topic: (Inheritance)
////terms used in literature(attributes/features/characteristics) and behaviors.
////data members are called attributes and member functions are called behaviors.
////four main pillars of OOP. 1: Abstraction 2: Encapsulation 3: Inheritance 4: Polymorphism
////creating new class (child class/derived class) from existing class(base class/parent class) is called inheritance.
////derived/child class inherits all the characteristics of parent class additionally it can have its own features and behaviors.
////inheritance provides reusabilty of code.
////In simple words we can say that with inheritance a child/derived class can share/access the attributes and behaviors of parent/base class.
////Child class extends parent class.
//
//#include<iostream>
//#include<string>
//using namespace std;
////class A 
////{
////	int x;
////public:
////	A():x(10)//another way of initialization in default constructors 
////	{}
////	void show()
////	{
////		cout << "x = " << x;
////	}
////};
////int main()
////{
////	A obj1;
////	obj1.show();
////}
//
//class employee {
////common attributes of each employee
//	int emp_id;
//	string name;
//	string cnic;
//	string contactNumber;
//	string address;
//public:
//	//employee(int id = 0, string n = "NULL", 
//		//string c="NULL", string cn = "NULL", string ad = "NULL")
//	employee(int id, string n,
//			string c , string cn , string ad)
//	{
//		cout << "employee\n";
//		emp_id = id;
//		name = n;
//		cnic = c;
//		contactNumber = cn;
//		address = ad;
//	}
//
//	void dispPersonalInfo()
//	{
//		cout << "emp id = " << emp_id << endl;
//		cout << "name = " << name << endl;
//		cout << "cnic = " << cnic << endl;
//		cout << "contact Number = " << contactNumber << endl;
//		cout << "address = " << address << endl;
//	}
//};
//
////here teacher is the (derived/child) class and employee is the (base/parent class).
////we can say that teacher extends employee
//class teacher: public employee 
//{
//	string subject;
//	int experience;
//public:
////since there is a parameterized constructor of base class and we know that parameterized constructor will not be called automatically.
////so we have to call the constructor of base class explicitly.
////you can call the constructor of base class in the following way.
//
//	//teacher(string sb, int exp):employee(1,"Ali","0423","32909-123","Lahore")
//	//constructor of derived class colon(:) parentClassName(comma separated arguments)
//	teacher(string sbj = "NULL", int exp = 0, int id = 0, string n="NULL",string c="NULL", string cn="NULL", string ad="NULL"):employee(id,n,c,cn,ad)
//	{
////Remember the sequence! 
////it will call the constructor of base class first, then will execute the body of derived class constructor.
//		cout << "teacher\n";
//		subject = sbj;
//		experience = exp;
//	}
//	void dispTeachProfInfo()
//	{
//		cout << "subject = " << subject << endl;
//		cout << "experience = " << experience << endl;
//	}
//};
////class developer : public employee
////{
////	string domain;
////	string techStack;
////	int projectsCompleted;
////public:
////	developer(string dm = "NULL", string ts = "NULL", int pr = 0)
////	{
////		domain = dm;
////		techStack = ts;
////		projectsCompleted = pr;
////	}
////	void dispDevProfInfo()
////	{
////		cout << "domain = " << domain << endl;
////		cout << "projects Completed = " << projectsCompleted << endl;
////	}
////};
////class doctor : public employee
////{
////	string speciality;
////	float consCharges;
////public:
////	doctor(string sp = "NULL", float cnsCh = 0)
////	{
////		speciality = sp;
////		consCharges = cnsCh;
////	}
////	void dispDoctProfInfo()
////	{
////
////	}
////
////};
//void main()
//{
//	teacher t1("PF",2,7001,"Arif","34201-123456789-5","0310-41234567","Lahore");
//	t1.dispPersonalInfo(); //child/derived class object is accessing the member function of base class just because of inheritance.
//	t1.dispTeachProfInfo(); 
//
////if there exist default parameterized constructor of parent/base class than you can create the object of derived class as follow
//	//developer dv1;  // constructors will be called automatically and dataMembers will be initialized with 0 or NULL.
//	//doctor dct1;
//}
//
//
//Ex#2:
////class employee 
////{
////	string name;
////	int emp_id;
////public:
////	employee(string n = "NULL", int id = 0)
////	{
////		name = n;
////		emp_id = id;
////	}
////	void show()
////	{
////		cout << name << " " << emp_id << endl;
////	}
////protected:
////	void setName(string n)
////	{
////		name = n;
////	}
////};
////class teacher: protected employee
////{
////	string dept;
////	int publications;
////	string institution;
////public:
////	teacher(string d = "NULL", int p = 0, string inst = "NULL",int id = 0, string n = "NULL"):employee(n,id)
////	{
////		dept = d;
////		publications = p;
////		institution = inst;
////	}
////	void display()
////	{
////		setName("Ali");
////		show();
////		cout << "dept " << dept << endl;
////		cout << "publications " << publications << endl;
////		cout << "inst " << institution << endl;
////	}
////};
////class C :public teacher 
////{
////	int x;
////public:
////	void output()
////	{
////		show();
////	}
////};
////int main()
////{
////	teacher t1;
////	C obj1;
////	obj1.output();
////}