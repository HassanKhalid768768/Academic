#include <iostream>

using namespace std;

int TotalStudents;
int MagicNo;
int ID[100];
double Marks[100][11];
double Statistics[10][11];

int presentMenu()
{
    int Choice = 0;
    do{
        cout<<"\t Marks Manager"<<endl<<endl
            <<"1. Load Data"<<endl
            <<"2. Save"<<endl
            <<"3. Add "<<endl
            <<"3. Delete "<<endl
            <<"5. Sort "<<endl
            <<"6. View All "<<endl
            <<"7. Search "<<endl
            <<"8. Exit"<<endl
            <<endl<<"Enter Your Choice (1-7) ";

        if(Choice < 0 || Choice > 7)
            cout<<endl<<"Please enter a valid choice between 1 and 4 "<<endl;

        cin >> Choice;
    }while(Choice < 1 || Choice > 7);

    return Choice;
}

int main()
{
    int Selection = 0;
    do{
        Selection = presentMenu();
        if(Selection == 1){
            cout<<"Loading Data"<<endl;
        }
        else if(Selection == 2){
            cout<<"Add "<<endl;
        }
        else if(Selection == 3){
            cout<<"Save "<<endl;
        }
        else if(Selection == 4){
            cout<<"Sort"<<endl;
        }
        else if(Selection == 5){
            cout<<"View All"<<endl;
        }
        else if(Selection == 6){
            cout<<"View Specific Student Record"<<endl;
        }

    }while(Selection != 7);

    return 0;
}
