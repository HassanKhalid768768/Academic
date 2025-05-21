using namespace std;
#include <iostream>
int main(){
    int StartYear,EndYear,NumberOfLeapYears;
    cout<<"Enter Start Year"<<endl;
    cin>>StartYear;
    cout<<"Enter End Year"<<endl;
    cin>>EndYear;
    NumberOfLeapYears=(((EndYear-StartYear)+1)/4);
    cout<<"Number Of Leap Years :"<<NumberOfLeapYears<<endl;
    return 0;
}
