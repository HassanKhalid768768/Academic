#include<iostream>
using namespace std;

int countMostlyWhite(int data[][1000], int m, int n, int k){
    int total=0;
    int value=(k*k)/2;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        int sum=0;
        int c=i;
        int d=j;
        for(int a=i;a<k+c;a++){
    for(int b=j;b<k+d;b++){
        if(((k+c)<=m)&&((k+d)<=n)){
            if (data[a][b]==1){
            sum++;
        }
        }
    }
        }
        if (sum>=value){
            total++;
        }
    }
    }
    return total;
}
 
 int main()
{
    int m,n,k;
cout<<"Enter Rows : "<<endl;
cin>>m;
cout<<"Enter Columns : "<<endl;
cin>>n;
cout<<"Enter K Value : "<<endl;
cin>>k;
int data[m][1000]={0};

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<"Enter Number for Array : ";
        cin>>data[i][j];
    }
}

cout<<"Number Of White Boxes : "<<countMostlyWhite(data,m,n,k);


return 0;
}
