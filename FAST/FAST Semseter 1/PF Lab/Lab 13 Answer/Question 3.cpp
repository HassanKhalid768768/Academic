#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
char filename[20] = "inventory.txt";
char NAME[10][15];
int QTY[10];
float cost[10];
int n = 10;

ifstream infile(filename);
if(!infile.is_open())
{
cout << "Could not open file " << filename << endl;
return 1;
}

cout << left << setw(7) << "Code" << setw(15) << "Name" << setw(10) << "Quantity" << setw(10) << "Cost" << endl;
for(int i = 0; i < n; i++)
{
infile >> NAME[i] >> QTY[i] >> cost[i];
cout << setw(7) << (i+1) << setw(15) << NAME[i] << setw(10) << QTY[i] << setw(10) << cost[i] << endl;

}
infile.close();
cout << endl;



string BILL = "";
int CODE;
float total = 0, SUBtotal;
string ans;
do
{
cout << "Enter CODE [1- 10]: ";
cin >> CODE;
if(CODE < 1 || CODE > n)
cout << "Invalid CODE " << endl;
else
{
int qty;
cout << "How many ? ";
cin >> qty;
SUBtotal = qty * cost[CODE-1];
total+= SUBtotal;
QTY[CODE-1] -= qty;
BILL = BILL + NAME[CODE-1] + " " + to_string(qty) + " @ $" + to_string(cost[CODE-1]) + " = " + to_string(SUBtotal) + "\n";
}

cout << "Do you want to purchase more y/n ? ";
cin >> ans;

}while(ans == "y" || ans == "Y");

cout << "Your BILL : " << endl << BILL << "TOTAL IS $" << total << endl;


ofstream outfile(filename);

for(int i = 0; i < n; i++)
outfile << NAME[i] << " " << QTY[i] << " " << cost[i] << endl;
outfile.close();
}
