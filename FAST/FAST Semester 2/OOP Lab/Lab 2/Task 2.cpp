#include<iostream>
using namespace std;

void Counter(char c_arr[]){
	int letters=0,upper=0,spaces=0,lower=0,vowel=0,consonant=0;
	
	for(int i=0;i<100;i++){
		if(c_arr[i]>='A' && c_arr[i]<='Z'){
			upper++;
		
}

if(c_arr[i]==' '){
			spaces++;
		
}

if(c_arr[i]>='a' && c_arr[i]<='z'){
			lower++;
}

if(c_arr[i]=='a' || c_arr[i]=='e' || c_arr[i]=='i' || c_arr[i]=='o'  || c_arr[i]=='u' || c_arr[i]=='A' || c_arr[i]=='E' || c_arr[i]=='I' || c_arr[i]=='O' || c_arr[i]=='U'){
			vowel++;
			
}
if(c_arr[i]==0 || c_arr[i]==' '){
			letters++;
}

	}
	consonant=((upper+lower)-vowel);
	
	cout<<"No. of letters are:"<<(100-letters)<<endl;
	cout<<"No. of spaces are:"<<spaces<<endl;
	cout<<"No. of uppercase letters are:"<<upper<<endl;
	cout<<"No. of lowercase letters are:"<<lower<<endl;
		cout<<"No. of Vowels:"<<vowel<<endl;
		cout<<"No. of Consonants:"<<consonant;
}


int main(){

char c_arr[100]={0};

    cout<<"Enter the Sentence : ";
    gets(c_arr);
	
	
	
	Counter(c_arr);
}
