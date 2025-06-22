#include <iostream>

using namespace std;

int main()
{
const int a=5;
const int b=12;
const int c=10;

const int *ptra=&a;
const int *ptrb=&b;
const int *ptrc=&c;

if((*ptra > *ptrb) && (*ptra < *ptrc)){
	cout<<"Median is : "<<*ptra
;}
if((*ptrb > *ptra) && (*ptrb < *ptrc)){
	cout<<"Median is : "<<*ptrb
;}
if((*ptrc > *ptra) && (*ptrc < *ptrb)){
	cout<<"Median is : "<<*ptrc
;}

    return 0;
}