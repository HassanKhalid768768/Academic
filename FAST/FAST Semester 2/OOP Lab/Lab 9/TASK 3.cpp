#include <iostream>
#include <conio.h>
using namespace std;



class employee 
{
protected:
 string name;
 unsigned long number;
public: 
 void getdata()
 {
  cout << "\nEnter Name : "; 
  cin >> name;
  cout << "Enter Number :"; 
  cin >> number;
 }
 void putdata() const
 {
  cout << endl << name << endl;
  cout << number << endl;
 }
};

class employee2 :public employee
{
private:
 double compensation;
 string time;
public:
 void getdata()
 {
  employee::getdata();
  cout << "Enter Compensation: ";
  cin >> compensation;
  cout << "Enter payment period Hourly Monthly or Weekly: ";
  cin >> time;

 }
 void putdata() const
 {
  employee::putdata();
  cout << compensation << endl;
cout<<time<<endl;
 }
};

class manager : public employee2 
{
private:
 int id; 
public:
 void getdata()
 {
  employee2::getdata();
  cout << "Enter Manager ID : "; 
  cin >> id;
 }
 void putdata() const
 {
  employee2::putdata();
  cout << id << endl;
  
 }
};

class scientist : public employee2 
{
private:
 int experiments; 
public:
 void getdata()
 {
  employee2::getdata();
  cout << "Enter Number of Experiments : "; 
  cin >> experiments;
 }
 void putdata() const
 {
  employee2::putdata();
  cout << experiments << endl;
 }
};

class laborer : public employee2
{
private:
 int wage; 
public:
 void getdata()
 {
  employee2::getdata();
  cout << "Enter Wage : "; 
  cin >> wage;
 }
 void putdata() const
 {
  employee2::putdata();
  cout << wage << endl;
 }
};


int main()
{
 manager m;
 scientist s;
 laborer l;
 
 cout << "Manager ";
 m.getdata();
 cout << "\nScientist ";
 s.getdata();
 cout << "\nLaborer ";
 l.getdata();

 m.putdata();
 s.putdata();
 l.putdata();
 cout<<endl;
}