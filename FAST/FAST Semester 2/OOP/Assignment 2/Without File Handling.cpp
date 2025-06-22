#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    int size=0;

class teacher{

string Name;
string Address;
string ContactInfo;
string EmailAddress;
string Institution;
string Department;
char Type;
string Designation;
string AllocatedCourses[100];
int CreditHours[100];
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
            Department = " " , Type = '\n' , Designation = " " , AllocatedCourses[100] ;
            CreditHours[100] , CreditHoursPerWeek = 0 , MonthlySalary = 0;
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

        }


    void setDesignation(){
    cout<<"Enter Designation : ";
    getline(cin,Designation);
    }

    void setName(){

         cout<<"Enter Name : ";

    getline(cin,Name);
    }



    void setAddress(){
    cout<<"Enter Address : ";
    getline(cin,Address);
    }

    void setContactInfo(){
    cout<<"Enter Contact Info : ";
    getline(cin,ContactInfo);
    }

    void setEmailAddress(){
    cout<<"Enter Email Address : ";
    getline(cin,EmailAddress);
    }

    void setInstitution(){
    cout<<"Enter Institution : ";
    getline(cin,Institution);
    }

    void setDepartment(){
    cout<<"Enter Department : ";
    getline(cin,Department);
    }

      void setType(){
    cout<<"Enter P for Permanent or V for Visiting : ";
    cin>>Type;
    }



    void setAllocatedCourses(){

    while(size<3){
    cout<<"Enter Number of Courses"<<endl<<"Courses must be at least 3 : ";
    cin>>size;
    }
    for(int i=0;i<size;i++){
    cout<<"Enter Allocated Course : ";
    cin>>AllocatedCourses[i];
    }
    }

    void setCreditHours(){
    for(int i=0;i<size;i++){
    cout<<"Enter Credit Hours for each Course : ";
    cin>>CreditHours[i];
    }
    }

    void setCreditHoursPerWeek(){
    for(int i=0;i<size;i++){
    CreditHoursPerWeek=CreditHoursPerWeek+CreditHours[i];
    }
    }

    void setExperience(){
    do{
    cout<<"Enter Experience"<<endl<<"Experience must be in between 1 and 4 : ";
    cin>>Experience;
    }while(Experience>4 && Experience<0);
    }

    void setPublications(){
    cout<<"Enter Publications : ";
    cin>>Publications;
    }

    void setQualification(){
    cout<<"Enter Qualification : ";
    getline(cin,Qualification);
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
    for(int i=0;i<size;i++){
    cout<<"Allocated Course "<<i<<" : "<<AllocatedCourses[i]<<endl;
    }
    }

    void getCreditHours(){
    for(int i=0;i<size;i++){
    cout<<"Credit Hours for Course "<<i<<" : "<<CreditHours[i]<<endl;
    }
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
getDesignation();
getType();
for(int i=0;i<size;i++){
    cout<<"Allocated Course "<<i<<" : "<<AllocatedCourses[i]<<endl;
    }
for(int i=0;i<size;i++){
cout<<"Credit Hours for Course "<<i<<" : "<<AllocatedCourses[i]<<endl;
}
getCreditHoursPerWeek();
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

t1[0].setName();
for(int i=0;i<n;i++){
t1[i].setName();
t1[i].setAddress();
t1[i].setContactInfo();
t1[i].setEmailAddress();
t1[i].setInstitution();
t1[i].setDepartment();
t1[i].setDesignation();
t1[i].setType();
t1[i].setAllocatedCourses();
t1[i].setCreditHours();
t1[i].setCreditHoursPerWeek();
t1[i].setExperience();
t1[i].setPublications();
t1[i].setQualification();
t1[i].setQualification();
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
    return 0;
}

