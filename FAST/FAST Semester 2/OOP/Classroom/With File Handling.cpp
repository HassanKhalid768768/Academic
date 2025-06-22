#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

    int size=0,n;

std::ofstream outfile ("Salaries.txt");

class teacher{

string Name;
string Address;
string ContactInfo;
string EmailAddress;
string Institution;
string Department;
char Type;
string Designation;
string AllocatedCourses;
string CreditHours;
int CreditHoursPerWeek;
int MonthlySalary;
int Experience;
int Publications;
string Qualification;
string Avoid;

public:

 teacher()
        {
            Name = " " , Address = " " , ContactInfo = " " , EmailAddress = " " , Institution = " ";
            Department = " " , Type = '\n' , Designation = " " , AllocatedCourses=" " ;
            CreditHours = " " , CreditHoursPerWeek = 0 , MonthlySalary = 0;
            Experience = 0 , Publications = 0 , Qualification = " " ;
        }





        void updateRecord(){
        int choice;

        cout<<endl<<"Enter 1 to update qualification"<<endl<<
        "Enter 2 to update contact"<<endl<<
        "Enter 3 to update institution"<<endl
        <<"Enter Choice : " ;
        cin>>choice;

        if(choice==1){
             cout<<endl<<"Enter Qualification : ";
             getline(cin,Qualification);
             getline(cin,Qualification);
        }
        if(choice==2){
             cout<<endl<<"Enter Contact Info : ";
    getline(cin,ContactInfo);
    getline(cin,ContactInfo);
        }if(choice==3){
             cout<<endl<<"Enter Institution : ";
    getline(cin,Institution);
       getline(cin,Institution);
        }
        }




        void CalculateSalary(){
        if(Type=='V'){
        if(Designation=="Lecturer"){
            MonthlySalary+=(CreditHoursPerWeek*2000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Assistant Professor"){
            MonthlySalary+=(CreditHoursPerWeek*4000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Associate Professor"){
            MonthlySalary+=(CreditHoursPerWeek*7000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Professor"){
            MonthlySalary+=(CreditHoursPerWeek*9000);
            MonthlySalary=MonthlySalary*4;
        }
    }
    if(Type=='P'){
        if(Designation=="Lecturer"){
            MonthlySalary+=(CreditHoursPerWeek*100000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Assistant Professor"){
            MonthlySalary+=(CreditHoursPerWeek*175000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Associate Professor"){
            MonthlySalary+=(CreditHoursPerWeek*250000);
            MonthlySalary=MonthlySalary*4;
        }
        if(Designation=="Professor"){
            MonthlySalary+=(CreditHoursPerWeek*325000);
            MonthlySalary=MonthlySalary*4;
        }
    }



    if(Experience==1){
        MonthlySalary=MonthlySalary+((MonthlySalary*5)/100);
    }
    if(Experience==2){
        MonthlySalary=MonthlySalary+((MonthlySalary*10)/100);
    }
    if(Experience==3){
        MonthlySalary=MonthlySalary+((MonthlySalary*15)/100);
    }
    if(Experience==4){
        MonthlySalary=MonthlySalary+((MonthlySalary*20)/100);
    }

     MonthlySalary=MonthlySalary+(Publications*8000);
 outfile <<MonthlySalary<<endl;
        }






    void setDesignation(string name){
   Designation=name;
    }

    void setName(string name){
   Name=name;
    }

    void setAddress(string name){
     Address=name;
    }

    void setContactInfo(string name){
      ContactInfo=name;
    }

    void setEmailAddress(string name){
      EmailAddress=name;
    }

    void setInstitution(string name){
       Institution=name;
    }

    void setDepartment(string name){
      Department=name;
    }

      void setType(char name){
    Type=name;
    }



    void setAllocatedCourses(string name){
    AllocatedCourses=name;
    }


    void setCreditHours(string name){
   CreditHours=name;
   n = CreditHours.length();
    }

    void setCreditHoursPerWeek(){

    char char_array[n]={0};
    strcpy(char_array, CreditHours.c_str());
    for(int i=0;i<n;i++){
       if(i%2==0){
        CreditHoursPerWeek=CreditHoursPerWeek+char_array[i];
        CreditHoursPerWeek=CreditHoursPerWeek-48;
       }
    }


    }

    void setExperience(int N){
   Experience=N;
    }

    void setPublications(int N){
   Publications=N;
    }

    void setQualification(string name){
    Qualification=name;
    }

    void setMonthlySalary(){
    CalculateSalary();
    }


    void getDesignation(){
    cout<<"Designation : "<<Designation<<endl;
    }

    void getName(){
    cout<<endl<<endl<<"Name : "<<Name<<endl;
    }

    void getAddress(){
    cout<<"Address : "<<Address<<endl;
    }

    void getContactInfo(){
    cout<<"Contact Info : "<<ContactInfo<<endl;
    }

    void getEmailAddress(){
    cout<<"Email Address : "<<EmailAddress<<endl;
    }

    void getInstitution(){
   cout<<"Institution : "<<Institution<<endl;
    }

    void getDepartment(){
    cout<<"Department : "<<Department<<endl;
    }

      void getType(){
   cout<<"Type : "<<Type<<endl;
    }



    void getAllocatedCourses(){
    cout<<"Allocated Course : "<<AllocatedCourses<<endl;
    }

    void getCreditHours(){
        cout<<"Credit Hours : "<<CreditHours<<endl;
    }

    void getCreditHoursPerWeek(){
    cout<<"Credit Hours Per Week : "<<CreditHoursPerWeek<<endl;
    }

    void getExperience(){
    cout<<"Experience : "<<Experience<<endl;
    }

    void getPublications(){
    cout<<"Publications : "<<Publications<<endl;
    }

    void getQualification(){
    cout<<"Qualification : "<<Qualification<<endl;
    }

    void getMonthlySalary(){
    cout<<"Monthly Salary : "<<MonthlySalary<<endl<<endl;
    }

void showdata(){
        getName();
getAddress();
getContactInfo();
getEmailAddress();
getInstitution();
getDepartment();
getType();
getDesignation();
getAllocatedCourses();
getCreditHours();
getExperience();
getPublications();
getQualification();
getMonthlySalary();
        }

};


int main()
{
    int n;
    do{
    cout<<"Enter Number of teachers : ";
    cin>>n;
    cout<<endl<<endl;
    }while(n<3);
teacher t1[n];

ifstream MyReadFile("dataFile.txt");


for(int i=0;i<n;i++){
string myText;
int n;
char type;


getline (MyReadFile, myText);
t1[i].setName(myText);
getline (MyReadFile, myText);
t1[i].setAddress(myText);
getline (MyReadFile, myText);
t1[i].setContactInfo(myText);
getline (MyReadFile, myText);
t1[i].setEmailAddress(myText);
getline (MyReadFile, myText);
t1[i].setInstitution(myText);
getline (MyReadFile, myText);
t1[i].setDepartment(myText);
MyReadFile>>type;
t1[i].setType(type);
getline (MyReadFile, myText);
getline (MyReadFile, myText);
t1[i].setDesignation(myText);
getline (MyReadFile, myText);
t1[i].setAllocatedCourses(myText);
getline (MyReadFile, myText);
t1[i].setCreditHours(myText);
t1[i].setCreditHoursPerWeek();
MyReadFile>>n;
t1[i].setExperience(n);
MyReadFile>>n;
t1[i].setPublications(n);
getline (MyReadFile, myText);
getline (MyReadFile, myText);
t1[i].setQualification(myText);
cout<<endl<<endl;
t1[i].setMonthlySalary();
}

for(int i=0;i<n;i++){
if(i==1){
t1[1].updateRecord();
}
if(i==2){
t1[2].updateRecord();
}
}



for(int i=0;i<n;i++){
t1[i].showdata();
}
outfile.close();
MyReadFile.close();


    return 0;
}

