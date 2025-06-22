////Inheritance#2
////
////Usama Hassan Alvi
////Topics:
////multilevel inheritance, public, private and protected inheritance
//#include<iostream>
//#include<string>
//using namespace std;
//
//// multi-level inheritance
//class Institution
//{
//	string universityName;
//public:
//	Institution(string un = "NULL")
//	{
//		cout << "A\n";
//		universityName = un;
//	}
//	void setUniName(string un)
//	{
//		universityName = un;
//	}
//	string getUniName()
//	{
//		return universityName;
//	}
//};
//class department : public Institution
//{
//	string departmentName;
//public:
//	department(string un = "NULL", string dn = "NULL") : Institution(un)
//	{
//		cout << "B\n";
//		departmentName = dn;
//	}
//	void setDepartmentName(string dn)
//	{
//		departmentName = dn;
//	}
//	string getDepartmentName()
//	{
//		return departmentName;
//	}
//};
//class society : public department
//{
//	string societyName;
//public:
//	society(string un = "NULL", string dn = "NULL", string sn = "NULL") :department(un, dn)
//	{
//		cout << "C\n";
//		societyName = sn;
//	}
//	void setSocietyName(string sn)
//	{
//		societyName = sn;
//	}
//	string getSocietyName()
//	{
//		return societyName;
//	}
//};
//
//int main()
//{
//	society s2;
//	s2.setUniName("UET");
//	s2.setDepartmentName("CE");
//	s2.setSocietyName("CBS");
//	//cout << "University Name " << s2.getUniName() << endl;
//	//cout << "Department Name " << s2.getDepartmentName() << endl;
//	//cout << "Society Name " << s2.getSocietyName() << endl;
//	//society s1("UOL", "CS", "Sports");
//	//cout << "University Name " << s1.getUniName() << endl;
//	//cout << "Department Name " << s1.getDepartmentName() << endl;
//	//cout << "Society Name " << s1.getSocietyName() << endl;
//}
//// Discussion of public, protected and private. 
////class employee
////{
////private:
////	int emp_id;
////protected:
////	string name;
////public:
////	employee(int id = 0,string n = "NULL")
////	{
////		emp_id = id;
////		name = n;
////	}
////	void setId(int id)
////	{
////		emp_id = id;
////	}
////	int getId()
////	{
////		return emp_id;
////	}
////};
////class developer :private employee
////{
////	string domain;
////public:
////	developer(int id = 0, string n = "NULL", string dm = "NULL") : employee(id,n)
////	{
////		domain = dm;
////	}
////	void setDomain(string dm)
////	{
////		domain = dm;
////	}
////	string getDomain()
////	{
////		return domain;
////	}
////	void showDevInfo()
////	{
////		cout << "protected data member " << name << endl;
////		cout << "domain " << domain << endl;
////		cout << "emp id " << getId() << endl;
////	}
////	void setBasicInfo(int id, string n)
////	{
////		setId(id);
////	}
////};
////
////int main()
////{
////	developer dv1(7009,"Ahsan","AI");
////	cout << dv1.name;
////	//cout << "emp id inside main" << dv1.name << endl;
////	dv1.showDevInfo();
////}
//
////Accessibilty of parent class members inside derived class and main function
////public Inheritance: 
////				        private		 |  public	   |   protected
////inside main:			inaccessible |	accessible |   inaccessible		
////inside derived class: 	inaccessible |  accessible |   accessible
////it means that the object of child class can access all the public methods of base class inside main and can access the protected
////methods inside the derived class in addition to public methods.
//
////private Inheritance: 
////				        private		 |  public	     |  protected
////inside main:			inaccessible |	inaccessible |  inaccessible		
////inside derived class: 	inaccessible |  accessible   |  accessible
////it means that the object of child class can not access even the public 
////methods of base class inside main. you can only access the methods of base
////class inside the derived class.
//
////protected Inheritance: 
////						private		|  public	    |  protected
///inside main:				inaccessible|  inaccessible |  inaccessible		
//inside derived class: 	inaccessible|  accessible   |  accessible
//
////private and protected looks similar for single level inheritance but the difference appears in multi-level. 
////incase of multi-level inheritance where (A <- B <- C) i.e., [C extends B and B extends A]
////A is the grand-parent, and B is the parent class of C.
////Assume that B extends A privately (private inheritance) and C extends B publically (public inheritance)
////In this case the methods of 'A' can only be accessible inside the immediate child class i.e., 'B' and can not be accessible in further classes derived from 'B'.
////Whereas if B extends 'A' in protected mode (protected inheritance) and C extends B publically then the methods of A can be accessible in all the derived classes.