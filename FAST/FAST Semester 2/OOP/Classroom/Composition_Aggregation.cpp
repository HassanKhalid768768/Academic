//////Topics:
//////how to declare an object when constructor is private
//////Association => relationship between classes
//////2Types => i: (Aggregation) ii: (Composition)
//////Association is weak relationship between classes.
//////Aggregation => specialized version of association. we can say that it is as weak association.
//////In aggregation, the relationship between classes is stronger than association but weaker than composition.
//////Aggregate class holds the reference to another class. This can be achieved by declaring a pointer in the dataMember of aggregate class.
//////In literature this relationship is represented by 'has a' or 'part/whole' relationship.
//////In UML diagram this relationship is represented by hollow diamond symbol.
//////UML(Unified modelling language) UML diagram is a way to visually represent the system(classes).
////
//////Composition => specialized case of aggregation.
//////We can say that compoition is a strong association or strong relationship of classes.
//////In literature this relationship is also represented by 'has a' or 'part-of' relationship.
//////In UML diagram this relationship is represented by a filled diamond symbol.
////
//////Example#1 (Association)
//////two independent classes(patient and doctor)
//#include<iostream>
//#include<string>
//using namespace std;
////class Patient
////{
////	string p_name;
////	int p_age;
////public:
////	Patient(int p_a = 0, string p_n = " ")
////	{
////		p_age = p_a;
////		p_name = p_n;
////	}
////	void show()
////	{
////		cout << "Patient's name and age " << p_name << " " << p_age << endl;
////	}
////};
////
////class Doctor
////{
////	string d_name;
////	string specialization;
////public:
////	Doctor(string d_n = " ", string s = " ")
////	{
////		d_name = d_n;
////		specialization = s;
////	}
////	void show(Patient p)//this function is receieving an object of patient class.
////	{
////		cout << "Doctor's name " << d_name << "\n";
////		cout << "Specialized Area "<< specialization << endl;
////		p.show();//calling the show function of patient class
////	}
////};
//////int main()
//////{
//////	Patient p1(70,"Nawaz");
//////	Patient p2(46, "Shoaib");
//////	Patient p2(32, "Haris");
//////
//////	Doctor d1("Firdous", "Cardiac");
//////	Doctor d2("Amir", "neurologist");
//////	
//////	p1.show(d1); //Association (p1 is the patient of d1)
//////	p1.show(d2); //Association (p1 is the patient of d2)
//////
//////
//////}
////
////Example#2:
////Composition. strong association between the classes.
////Create an object of one class in another class.
//
////class Author
////{
////	string name;
////public:
////	Author(string n = " ")
////	{
////		name = n;
////	}
////	void setName(string n)
////	{
////		name = n;
////	}
////	string getName()
////	{
////		return name;
////	}
////};
////class Book
////{
////	int price;
////	string title;
////	Author a_obj;
////    Author * b_obj;
////public:
////	Book(int p, string t, string n):a_obj(n)
////	{
////            b_obj = new Author(n); //you can also create an object on heap
////		price = p;
////		title = t;
////	}
////
////	void setPrice(int p)
////	{
////		price = p;
////	}
////
////	void setTitle(string t)
////	{
////		title = t;
////	}
////
////we can not directly access the member functions of Author with the object of Book in main function. Since we have object of Author in Book so we can access the ////Author's method in this class. That is why we need to define few extra methods inside the Book and through these methods we can access the methods of Author.
////
////	void setAuthName(string n)  
////	{
////		a_obj.setName(n);
////	}
////
////	void show()
////	{
////		cout << "price " << price << "\ntitle " << title << "\nAuthor " << a_obj.getName() << endl;
////	}
////};
////int main()
////{
////	Book b(1500, "PF", "Arham");
////	b.setAuthName("Shahid");
////	b.show();
////	system("pause");
////}
//
////Example#3:
////Aggregation. Weak association between the classes.
////We have created a pointer of one class in another class. This pointer is pointing to the object of that class.
////Objects of both the classes(Author & book) are declared in main function.
////Every book has an author so we have passed the object of author by reference in the constructor of book.
////Assign the address of (Author's object) to the pointer of Author inside the constructor of book.
////Since we have received Author's object by reference so any change through the pointer of Author result into the change in actual object.
//
////class Author
////{
////	string name;
////public:
////	Author(string n = " ")
////	{
////		name = n;
////	}
////	void setName(string n)
////	{
////		name = n;
////	}
////	string getName()
////	{
////		return name;
////	}
////};
////class Book
////{
////	int price;
////	string title;
////	Author * a_obj; 
////public:
////	Book(int p, string t, Author &obj) //receiving object by-reference. So any change through a_obj pointer result into a change in actual object in main function.
////	{
////		price = p;
////		title = t;
////		a_obj = &obj; //unlike composition(where we have created an object) here we are assigning the address of Author's object to the pointer. 
////	}
////
////	void setInfo(int p, string t, string n)
////	{
////		price = p;
////		title = t;
////		a_obj->setName(n);
////	}
////
////	void show()
////	{
////		cout << "price " << price << "\ntitle " << title << "\nAuthor " << a_obj->getName() << endl;
////	}
////};
////int main()
////{
//////We are going to create two objects namely 'a' for Author and 'b' for book.
////	Author a("Arif");
////	Book b(1500, "PF", a); //pass the object of author to initialize the pointer of Author in the book class.
////	cout << "Author " << a.getName() << endl; //Author name is Arif.
////	b.show();
////	b.setInfo(2500, "OOP", "Nasir"); //we are going to reset the Author's name.
////	b.show(); //display updated info on console.
//////since Author was passed by reference so the actual data of 'a' will also be updated.
////	cout << "Author " << a.getName() << endl; 
////	system("pause");
////}

//////Private constructor
//////We know that we can not access the private data members outside the class.
//////Whenever an object is created, the constructor will be called automatically.
//////if the constructor is private then you can not create an object inside main function.
//////We know that private data-members and private member functions are accessible in friend functions and inside the class.
//////so in case of private constructor you can create an object in friend function and return to the calling function.
//////similarly we can create an object inside the static member function and return to the calling function.
//////you can create a pointer of the class inside main function. We can access member functions of a class through pointer using -> operator.
//////so define a member function in the class that creates an object and return to calling function. call this function through pointer.
////class Person
////{
////	int p_id;
////	Person(int id) //constructor is private
////	{
////		p_id = id;
////	}
////public:
////	friend Person crObj(int); //Method#1: This friend function will be used to create an object
////	void show() const
////	{
////		cout << "id = " << this->p_id << endl;
////	}
////	static Person retObj(int id) //Method#2: This static member function will be used to create an object.
////	{
////		Person p_obj(id);
////		return p_obj;
////	}
//////Method#3: call the following function through pointer, create an object and return to the calling function.
////	Person* f(int id)
////	{
////		Person * obj = new Person(id);
////		return obj;
////	}
////};
////Person crObj(int id)
////{
////	Person obj(id);
////	obj.show();
////	return obj;
////}
////int main()
////{
////	//Person p1 = crObj(5); //method#1(friend function)
////	//Person p2 = Person::retObj(4);//method#2(static member function)
////	//Person *p; //constructor will not be called for pointer of the class.
////	//p = p->f(7); //method#3(call member function through pointer)
////	system("pause");
////}
////