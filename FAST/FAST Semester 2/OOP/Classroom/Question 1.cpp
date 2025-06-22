#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
 ifstream is("synonyms.txt");
 string line;
 
 string ** lines;
 while (getline (is, line)) {
 stringstream sline(line);
 string word;
 string * synonyms;
 while(getline(sline, word, ' '))
 {
 *synonyms=word;
 }
 ** lines=*synonyms;
 }
 cout<<"Enter A String:";
 string sentence;
 getline(cin,sentence);
 stringstream sentence_stream(sentence);
 string word;
 while(getline(sentence_stream, word, ' '))
 {
 int i;
 for(i=0;i<sizeof(lines);i++){
 if(lines[i][0].compare(word)==0){
 int random=(rand() % (sizeof(lines[i])-1))+1;
 cout<<" "<<lines[i][random];
 break;
 }
 }
 if(i==sizeof(lines))
 cout<<" "<<word;
 }

}