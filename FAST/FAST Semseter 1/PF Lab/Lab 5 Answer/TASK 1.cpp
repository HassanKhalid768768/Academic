#include <iostream>
const char PackageA='A';
const char PackageB='B';
const char PackageC='C';
using namespace std;
int main()
{
    const double PACKAGE_A_PRICE = 39.99,
                 PACKAGE_B_PRICE = 59.99,
                 PACKAGE_C_PRICE = 69.99,

                 PACKAGE_A_MINUTES = 450,
                 PACKAGE_B_MINUTES = 900,

                 PACKAGE_A_ADDITIONAL_CHARGES = .45,
                 PACKAGE_B_ADDITIONAL_CHARGES = .40;

    char choice;
    int minutes;
    
    cout << "\nPackage A: For $39.99 per month 450\n"
         << "minutes are provided.\n"
         << "--Additional minutes are $0.45 per minute.\n"
         << endl
         << "Package B: For $59.99 per month 900\n"
         << "minutes are provided.\n"
         << "--Additional minutes are $0.40 per minute.\n"
         << endl
         << "Package C: For $69.99 per month unlimited\n"
         << "minutes provided.\n" 
         << endl;
         
         cout << "Choose package: ";
    cin >> choice;
    cout << endl;
    
    
    if (choice==PackageA || choice==PackageB || choice==PackageC){
        cout << "Enter minutes used: ";
    cin >> minutes;
    cout << endl;
    if (choice==PackageA){
        if(minutes<450){
            cout<<"Bill is $39.99";
        }
        else{
            cout<<"Bill is $"<<(39.99+((minutes-450)*.45));
        }
    }
    
    if (choice==PackageB){
        if(minutes<900){
            cout<<"Bill is $59.99";
        }
        else{
            cout<<"Bill is $"<<(59.99+((minutes-900)*.40));
        }
    }
    
    if (choice==PackageC){
            cout<<"Bill is $69.99";
    }
    }
    else{
        cout<<"Wrong Choice Entered Please Rerun the program and try again.";
    }
    return 0;
}
    