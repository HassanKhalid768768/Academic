#include<iostream>
#include<cstring>
using namespace std;

string upper(string s){
    for(int i=0 ; i<s.length() ; i++){
            if((int)s[i]>=97 && (int)s[i]<=122){
        s[i]=(char)((int)s[i]-32);
        }
    }
    return s;
}

string lower(string s){
    for(int i=0 ; i<s.length() ; i++){
            if((int)s[i]>=65 && (int)s[i]<=90){
        s[i]=(char)((int)s[i]+32);
            }
    }
    return s;
}

char *concatenate(string s,string s1){
   int len=s.length()+s1.length();
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s.length();i++){
       temp[i]=s.at(i);
   }
   int j;
   for(j=i;j<len;j++){
       temp[j]=s1.at(j-i);
   }
   temp[j]='\0';
   return temp;
}

char *concatenate(string s,char *s1){
   int len=s.length()+strlen(s1);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s.length();i++){
       temp[i]=s.at(i);
   }
   int j;
   for(j=i;j<len;j++){
       temp[j]=s1[j-i];
   }
   temp[j]='\0';
   return temp;

}

char *concatenate(string s,char s1){
   int len=s.length();
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s.length();i++){
       temp[i]=s.at(i);
   }
temp[i++]=s1;
   temp[i]='\0';
   return temp;
}

char *concatenate(string s,int s1){
   char chararray[10];
   itoa(s1,chararray,10);

   int len=s.length()+strlen(chararray);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s.length();i++){
       temp[i]=s.at(i);
   }
   int j;
   for(j=i;j<len;j++){
       temp[j]=chararray[j-i];
   }
   temp[j]='\0';
   return temp;
}




//////// prepend

char *prepend(string s,string s1){
   int len=s.length()+s1.length();
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s1.length();i++){
       temp[i]=s1.at(i);
   }
   int j;
   for(j=i;j<len;j++){
       temp[j]=s.at(j-i);
   }
   temp[j]='\0';
   return temp;
}

char *prepend(string s,char *s1){
   int len=s.length()+strlen(s1);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<strlen(s1);i++){
       temp[i]=s1[i];
   }

   int j;
   for(j=i;j<len;j++){
       temp[j]=s.at(j-i);
   }
   temp[j]='\0';
   return temp;

}

char *prepend(string s,char s1){
   int len=s.length();
   int i=0;
   char *temp=new char[len+2];
   temp[i++]=s1;
   for(;i<s.length()+1;i++){
       temp[i]=s.at(i-1);
   }

   temp[i]='\0';
   return temp;
}

char *prepend(string s,int s1){
   char chararray[10];
   itoa(s1,chararray,10);

   int len=s.length()+strlen(chararray);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<strlen(chararray);i++){
       temp[i]=chararray[i];
   }

   int j;
   for(j=i;j<len;j++){
       temp[j]=s.at(j-i);
   }
   temp[j]='\0';
   return temp;
}



int ndigits(float f){
   int x=(int)f;
   float y=f-x;
   int count=0;

   while(x!=0){
       x=x/10;
       count++;
   }
   while((y-(int)y)>0.01){
       y=y*10;
       count++;
   }
   count++;

   return count;
}

char *concatenate(string s,float s1){
   char temparr[20];

   gcvt(s1, ndigits(s1)+1,temparr);

   int len=s.length()+strlen(temparr);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<s.length();i++){
       temp[i]=s.at(i);
   }
   int j;
   for(j=i;j<len;j++){
       temp[j]=temparr[j-i];
   }
   temp[j]='\0';
   return temp;
}

char *prepend(string s,float s1){
   char temparr[20];
   gcvt(s1, ndigits(s1)+1,temparr);

   int len=s.length()+strlen(temparr);
   int i=0;
   char *temp=new char[len+2];
   for(i=0;i<strlen(temparr);i++){
       temp[i]=temparr[i];
   }

   int j;
   for(j=i;j<len;j++){
       temp[j]=s.at(j-i);
   }
   temp[j]='\0';
   return temp;
}

void compare(string s1, string s2)
{

    if (s1 != s2)
    {
        cout << s1 << " is not equal to " << s2 << endl;
        if (s1 > s2)
            cout << s1 << " is greater than " << s2 << endl;
        else
            cout << s2 << " is greater than " << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}

char* operator+(string a,string b){
   return concatenate(a,b);
}

char* operator+(string a,char* b){
   return concatenate(a,b);
}

char* operator+(string a,char b){
   return concatenate(a,b);
}

char* operator+(string a,int b){
   return concatenate(a,b);
}

char* operator+(string a,float b){
   return concatenate(a,b);
}


char* operator+(char* b,string a){
   return prepend(a,b);
}

char* operator+(char b,string a){
   return prepend(a,b);
}

char* operator+(int b,string a){
   return prepend(a,b);
}

char* operator+(float b,string a){
   return prepend(a,b);
}


int main(){
   string str1,str2,word1,word2,word3,word4;
   char ch;
   int integer,indexstart,indexend;
   float f;
   cout<<"Enter String 1 : ";
   getline(cin,str1);
   cout<<"Enter String 2 : ";
   getline(cin,str2);
   char str[20];
   cout<<"Enter Character String : ";
   cin.get(str,20);
   cout<<"Enter Character : ";
   cin>>ch;
   cout<<"Enter Integer : ";
   cin>>integer;
   cout<<"Enter Float : ";
   cin>>f;


   cout<<endl<<"String 1 : "<<str1<<endl;
   cout<<"String 2 : "<<str2<<endl;
   cout<<"Character string : "<<str<<endl;
   cout<<"Character : "<<ch<<endl;
   cout<<"Integer : "<<integer<<endl;
   cout<<"Float : "<<f<<endl;

   cout<<endl<<"String 1 UpperCase : "<<upper(str1)<<endl;
   cout<<"String 1 LowerCase : "<<lower(str1)<<endl;
   cout<<"String 2 UpperCase : "<<upper(str2)<<endl;
   cout<<"String 2 LowerCase : "<<lower(str2)<<endl;

   cout<<endl<<"Enter Starting Word Of Substring 1 : ";
   cin>>word1;
   cout<<"Enter Ending Word Of Substring 1 : ";
   cin>>word2;
   cout<<endl<<"Enter Starting Word Of Substring 2 : ";
   cin>>word3;
   cout<<"Enter Ending Word Of Substring 2 : ";
   cin>>word4;

   indexstart=str1.find(word1);
   indexend=str1.find(word2);
   for(int i=indexend;str1[i]!=(char)32 && i!=str1.length();i++){
    indexend++;
   }

   cout<<endl<<endl<<"Substring of String 1 : ";
   for(int i=indexstart;i<=indexend;i++){
    cout<<str1[i];
   }

    cout<<endl<<"Starting index of substring 1 : "<<indexstart<<endl;

   indexstart=str2.find(word3);
   indexend=str2.find(word4);
   for(int i=indexend;str2[i]!=(char)32 && i!=str2.length();i++){
    indexend++;
   }

   cout<<endl<<"Substring of String 2 : ";
   for(int i=indexstart;i<=indexend;i++){
    cout<<str2[i];
   }

   cout<<endl<<"Starting index of substring 2 : "<<indexstart<<endl<<endl;

   cout<<"Comparing The Strings : "<<endl;
   compare(str1,str2);


   cout<<endl<<"Concatenating String 1 and String 2 : "<<concatenate(str1,str2)<<endl;
   cout<<"Concatenating String 1 and Character String : "<<concatenate(str1,str)<<endl;
   cout<<"Concatenating String 1 and Character : "<<concatenate(str1,ch)<<endl;
   cout<<"Concatenating String 1 and Integer : "<<concatenate(str1,integer)<<endl;
   cout<<"Concatenating String 1 and Float : "<<concatenate(str1,f)<<endl<<endl;

   cout<<"Prepending String 1 and String 2 : "<<prepend(str1,str2)<<endl;
   cout<<"Prepending String 1 and Character String : "<<prepend(str1,str)<<endl;
   cout<<"Prepending String 1 and Character : "<<prepend(str1,ch)<<endl;
   cout<<"Prepending String 1 and Integer : "<<prepend(str1,integer)<<endl;
   cout<<"Prepending String 1 and Float : "<<prepend(str1,f)<<endl<<endl;

   cout<<"String 1 + String 2 By Concatenation : "<<(str1+str2)<<endl;
   cout<<"String 1 + Character String By Concatenation : "<<(str1+str)<<endl;
   cout<<"String 1 + Character By Concatenation : "<<(str1+ch)<<endl;
   cout<<"String 1 + Integer By Concatenation : "<<(str1+integer)<<endl;
   cout<<"String 1 + Float By Concatenation : "<<(str1+f)<<endl<<endl;


   cout<<"Character String + String 1 By Prepending : "<<(str+str1)<<endl;
   cout<<"Character + String 1 By Prepending : "<<(ch+str1)<<endl;
   cout<<"Integer + String 1 By Prepending :  "<<(integer+str1)<<endl;
   cout<<"Float + String 1 By Prepending :  "<<(f+str1)<<endl<<endl;


   return 0;
}
