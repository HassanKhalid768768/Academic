#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int TotalStudents;
int MagicNo;
int ID[100];
double Marks[100][11];
double Statistics[10][11];

void Sort(){
 int TotalStudents,Weight,Evaluation,count=0,Max=0;
    cout<<"Enter Total Students : ";
    cin>>TotalStudents;
ifstream inFile;
inFile.open("MARKS.DAT");
inFile >> MagicNo;
cout<<"Magic Number : "<<MagicNo<<endl;
inFile >> Weight;
cout<<"Total Weightage of all the components : "<<Weight<<endl;
inFile >> Evaluation;
cout<<"Total Evaluation : "<<Evaluation<<endl;
while(count!=(TotalStudents+1)){
    for(int t=0;t!=Evaluation;t++){
    inFile>>ID[t];
    if(ID[t]>Max){
        Max=ID[t];
    }
    cout<<ID[t]<<"   ";
}
    count++;
    cout<<endl;
}
cout<<"Max : "<<Max;
}

void LoadStudent(){
    int count=0;
ifstream inFile;
inFile.open("STUDENT.DAT");
inFile >> MagicNo;
cout<<"Magic Number : "<<MagicNo<<endl;
inFile >> TotalStudents;
cout<<"Total Students : "<<TotalStudents<<endl;
while(count!=TotalStudents){
    count++;
    inFile>>ID[count];
    cout<<ID[count]<<"   ";
}
}

void LoadMark(){
    int TotalStudents,Weight,Evaluation,count=0;
    cout<<"Enter Total Students : ";
    cin>>TotalStudents;
ifstream inFile;
inFile.open("MARKS.DAT");
inFile >> MagicNo;
cout<<"Magic Number : "<<MagicNo<<endl;
inFile >> Weight;
cout<<"Total Weightage of all the components : "<<Weight<<endl;
inFile >> Evaluation;
cout<<"Total Evaluation : "<<Evaluation<<endl;
while(count!=(TotalStudents+1)){
    for(int t=0;t!=Evaluation;t++){
    inFile>>ID[t];
    cout<<ID[t]<<"   ";
}
    count++;
    cout<<endl;
}
}


void Save(){
    int M1,M2,M3;
    cin>>M1>>M2>>M3;
    cout<<endl;
    ofstream outFile;
outFile.open("STUDENT.DAT");
    LoadMark();
    outFile<< M1<<"   ";
cout<<M1<<endl;
outFile<< M2<<"   ";
cout<<M2<<endl;
outFile<< M3<<"   "<<endl;
cout<<M3<<endl<<endl;
}

void DeleteStudents(){
    ofstream outFile;
outFile.open("STUDENT.DAT");
cin.ignore();
}

void DeleteMarks(){
    ofstream outFile;
outFile.open("MARKS.DAT");
cin.ignore();
}

void ViewAll(){
LoadStudent();
cout<<endl;
LoadMark();
}

void AddStudent(){
    int MagicNo,TotalStudents,count=1;
    cout<<"Enter Magic Number : ";
    cin>>MagicNo;
    cout<<"Enter Total Students : ";
    cin>>TotalStudents;
    cout<<endl;
ofstream outFile;
outFile.open("STUDENT.DAT");
outFile<<MagicNo<<endl;
outFile<<TotalStudents<<endl;
while(count<=TotalStudents){
    int temp;
    cout<<"Enter Student ID "<<count<<" : ";
    count++;
    cin>>temp;
    cout<<endl;
outFile<<temp<<"   ";
}
}

void AddMark(){
    int MagicNo,Weight,Evaluations,Students,count=1;
    cout<<"Enter Magic Number : ";
    cin>>MagicNo;
    cout<<"Enter Total Weightage of all the components : ";
    cin>>Weight;
    cout<<"Enter Total Evaluations : ";
    cin>>Evaluations;
    cout<<"Enter Total Students : ";
    cin>>Students;
    cout<<endl;
ofstream outFile;
outFile.open("MARKS.DAT");
outFile<<MagicNo<<endl;
outFile<<Weight<<endl;
outFile<<Evaluations<<endl;

while(count<=Evaluations){
    int temp;
    cout<<"Enter Max Mark in component "<<count<<" : ";
    count++;
    cin>>temp;
    cout<<endl;
outFile<<temp<<"   ";
}
outFile<<endl;
cout<<endl;
count=1;
int i=1;
while(i<=Students){
while(count<=Evaluations){
    int temp;
    cout<<"Enter Student "<<i<<" Marks in component "<<count<<" : ";
    cin>>temp;
    cout<<endl;
outFile<<temp<<"   ";
count++;
}
i++;
count=1;
outFile<<endl;
}
}

void Find(){
    int temp;
    cin>>temp;
    ifstream inFile;
inFile.open("STUDENT.DAT");
inFile >> MagicNo;
cout<<"Magic Number : "<<MagicNo<<endl;
}



int presentMenu(){
    int Choice = 0;
    do{
        cout<<"\t Marks Manager"<<endl<<endl
            <<"1. Load Data"<<endl
            <<"2. Save"<<endl
            <<"3. Add "<<endl
            <<"4. Delete "<<endl
            <<"5. Sort "<<endl
            <<"6. View All "<<endl
            <<"7. Search "<<endl
            <<"8. Exit"<<endl
            <<endl<<"Enter Your Choice (1-8) ";

        if(Choice <= 0 || Choice >= 8)
            cout<<endl<<"Please enter a valid choice between 1 and 8 "<<endl;

        cin >> Choice;
    }while(Choice < 1 || Choice > 8);

    return Choice;
}

int main()
{
    int Selection = 0;
    do{
        Selection = presentMenu();
        if(Selection == 1){
            cout<<"Loading Data"<<endl;
             int i;
            cout<<"If you want to Load STUDENT.DAT file then enter 1 or if you want to Load MARKS.DAT file then enter 2 : ";
            cin>>i;
            if (i==1){
                LoadStudent();
                break;
            }
            if(i==2){
                LoadMark();
                break;
            }
            else{
                cout<<"You have entered wrong choice try again";
            }
            break;
        }
        else if(Selection == 2){
            cout<<"Save "<<endl;
            int i;
            cout<<"If you want to SAVE STUDENT.DAT file then enter 1 or if you want to SAVE MARKS.DAT file then enter 2 : ";
            cin>>i;
            if (i==1){
                AddStudent();
                break;
            }
            if(i==2){
                AddMark();
                break;
            }
            else{
                cout<<"You have entered wrong choice try again";
            }
            break;
        }
        else if(Selection == 3){
            cout<<"Add "<<endl;
            int i;
            cout<<"If you want to Create STUDENT.DAT file then enter 1 or if you want to Create MARKS.DAT file then enter 2 : ";
            cin>>i;
            if (i==1){
                AddStudent();
                break;
            }
            if(i==2){
                AddMark();
                break;
            }
            else{
                cout<<"You have entered wrong choice try again";
            }
            break;
        }
        else if(Selection == 4){
            cout<<"Delete "<<endl;
            int i;
            cout<<"If you want to Delete STUDENT.DAT file then enter 1 or if you want to Delete MARKS.DAT file then enter 2 : ";
            cin>>i;
            if (i==1){
                DeleteStudents();
                break;
            }
            if(i==2){
                DeleteMarks();
                break;
            }
            else{
                cout<<"You have entered wrong choice try again";
            }
            break;
        }
        else if(Selection == 5){
            cout<<"Sort "<<endl;
            Sort();
            break;
        }
        else if(Selection == 6){
            cout<<"View All "<<endl;
            ViewAll();
            break;
        }
        else if(Selection == 7){
            cout<<"View Magic Number "<<endl<<"Enter Student ID"<<endl;
            Find();
            break;
        }

    }while(Selection != 8);

    return 0;
}
