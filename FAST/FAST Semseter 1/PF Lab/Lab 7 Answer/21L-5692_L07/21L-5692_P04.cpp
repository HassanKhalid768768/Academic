#include <iostream>
using namespace std;

void primenumbers(int sn,int en){
    int temp;
    bool isPrime = true;
     while (sn < en) {
        isPrime = true;
        if (sn == 0 || sn == 1) {
            isPrime = false;
        }
        else {
            for (temp = 2; temp <= sn / 2; ++temp) {
                if (sn % temp == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        
        if (isPrime)
            cout << sn << " ";

        ++sn;
    }
}

int main() {
    int SN, EN;
    cout << "Enter StartingPoint and Ending Point: ";
    cin >> SN >> EN;
primenumbers(SN,EN);
   

   

    return 0;
}