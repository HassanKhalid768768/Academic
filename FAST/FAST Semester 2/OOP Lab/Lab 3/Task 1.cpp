#include <iostream>
using namespace std;

char Encrypt(char arr[],int size){
	char key;
		
		cout<<endl<<"Enter ecryption key : ";
	cin>>key;
	key=int(key)-96;
	
		cout<<endl<<endl<<"OUTPUT:"<<endl;
	cout<<"New Size of array : "<<size;
	
	for(int i=0;i<size;i++){
		
		if(int(arr[i])==32){
			arr[i]='j';
		}
		
		else if(int(arr[i])==100){
			arr[i]='z';
		}
		
		else if(int(arr[i])==99){
			arr[i]='y';
		}
		
		else if(int(arr[i])==98){
			arr[i]='x';
		}
		
		else if(int(arr[i])==97){
			arr[i]='w';
		}
		
		else if(int(arr[i])==68){
			arr[i]='Z';
		}
		
		else if(int(arr[i])==67){
			arr[i]='Y';
		}
		
		else if(int(arr[i])==66){
			arr[i]='X';
		}
		
		else if(int(arr[i])==65){
			arr[i]='W';
		}
		
		else {
	arr[i]=int(arr[i])-key;
	}
	
	}
	
	cout<<endl<<"Encrypted Array : ";
	for(int i=0;i<size;i++){
		cout<<arr[i];
	}
    
	
}



int main(){
	int s,size=0;
	
	
	cout<<"INPUT:"<<endl;
cout<<"Enter Size of array : ";
	cin>>s;
	
	char *arr=new char[s];
	cout<<endl<<"Enter the array elements : ";
	cin.ignore();
    cin.getline(arr,s);
	

	
for(int i=0;arr[i]!='\0';i++){
	size++;
}
cout<<Encrypt(arr,size);
	
	return 0;
	
}
