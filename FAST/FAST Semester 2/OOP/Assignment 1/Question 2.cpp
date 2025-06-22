#include <iostream>
using namespace std;

void showArr(int *arraynew)
{
for(int i=0;i<sizeof(arraynew)+1;i++)
cout<<arraynew[i]<<" ";
}


int twoDimToOneDim(int**arrayold ,int*arraynew ,int columns[],int n)
{

int k=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < columns[i]; ++j) {
			arraynew[k] = arrayold[i][j];
			k++;
		}
	}
return *arraynew;
}


void fillArray(int **arrayold,int columns[],int n)
{


for(int i = 0; i < n; ++i){
    for(int j = 0; j < columns[i]; ++j){
    cout<<"Enter data: ";
int temp;
cin>>temp;
      arrayold[i][j] = temp;
    }
}
}

void SortArr(int *arraynew)
{

int n=sizeof(arraynew)+1;
for (int i = 0; i < n-1; i++)
{
for (int j = 0; j < n-i-1; j++)
if (arraynew[j] > arraynew[j+1])
swap(arraynew[j],arraynew[j+1]);
}
}


int main()
{
int n;
cout<<" Enter the size of rows: ";
cin>>n;

int columns[n];
for(int i=0;i<n;i++){
cout<<"Enter the columns for row#" <<i<<": ";
cin>>columns[i];
}

 int* arraynew = new int[n];
int** arrayold = new int*[n];
for(int i = 0; i < n; ++i)
      arrayold[i] = new int[columns[i]];

fillArray(arrayold,columns,n);

*arraynew=twoDimToOneDim(arrayold,arraynew,columns,n);
SortArr(arraynew);
showArr(arraynew);
return 0;
}
