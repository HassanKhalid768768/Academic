#include<iostream>
using namespace std;


class Quadratic{
	int a,b,c;
	
	public:
		Quadratic(){
			a=0,b=0,c=0;
		}
		
		Quadratic(int x,int y,int z)
                {
                    a = x ;
                    b = y ;
                    c = z ;
                }
                
                Quadratic(Quadratic &obj) {
      a = obj.a;
      b = obj.b;
      c = obj.c;
    }

		
		 void display()
                {
                    cout<<endl<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
                }
	
	
	 Quadratic operator + (Quadratic& obj) {
        Quadratic temp;
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        temp.c = c + obj.c;
        return temp;
    }
    
     Quadratic operator - (Quadratic& obj) {
        Quadratic temp;
        temp.a = a - obj.a;
        temp.b = b - obj.b;
        temp.c = c - obj.c;
        return temp;
    }
    
     Quadratic operator * (Quadratic& obj) {
        Quadratic temp;
        temp.a = a * obj.a;
        temp.b = b * obj.b;
        temp.c = c * obj.c;
        return temp;
    }
    
   bool operator == (Quadratic& obj)
{
    if (a == obj.a ||
            b == obj.b ||
			c == obj.c
			)
			{
				return true;
			}
			else{
				return false;
			}
		}
		
		   bool operator != (Quadratic& obj)
{
    if (a != obj.a ||
            b != obj.b ||
			c != obj.c
			)
			{
				return true;
			}
			else{
				return false;
			}
		}
	
		


	~Quadratic(){
	}
};





int main(){
	int A,B,C,X,Y,Z;
	cout<<"Enter Co-efficients a, b and c respectively for 1 st equation : "<<endl;
	cin>>A;
	cin>>B;
	cin>>C;
	
	Quadratic Q(A,B,C);
cout<<"Enter Co-efficients a, b and c respectively for 2 nd equation : "<<endl;
	cin>>X;
	cin>>Y;
	cin>>Z;	
	Quadratic Q11,Q12,Q13;
		Quadratic Q10(X,Y,Z);
		Q11=Q10+Q;
	Q12=Q10-Q;
	Q13=Q*Q10;
	Quadratic Q1 = Q;
	Quadratic Q2,Q3,Q4;
	Q2=Q1+Q;
	Q3=Q1-Q;
	Q4=Q*Q1;
	
	

	cout<<endl<<"Equation : ";Q.display();
	cout<<endl<<"Copy Constructor Called ";Q1.display();
	cout<<endl<<"Addition";Q2.display();
	cout<<endl<<"Subtraction";Q3.display();
	cout<<endl<<"Multiplication";Q4.display();
	 if (Q == Q1){
        cout << endl<<"Equations are equal"<<endl;
}
else{
	cout <<endl<< "Equations are not equal"<<endl;
}
if (Q != Q1){
        cout << endl<<"Equations are not equal"<<endl;
}
else{
	cout <<endl<< "Equations are equal"<<endl;
}


cout<<endl<<"First Equation : ";Q.display();
	cout<<endl<<"Second Equation : ";Q10.display();
	cout<<endl<<"Addition";Q11.display();
	cout<<endl<<"Subtraction";Q12.display();
	cout<<endl<<"Multiplication";Q13.display();
if (Q == Q10){
        cout << endl<<"Equations are equal"<<endl;
}
else{
	cout <<endl<< "Equations are not equal"<<endl;
}
if (Q != Q10){
        cout << endl<<"Equations are not equal"<<endl;
}
else{
	cout <<endl<< "Equations are equal"<<endl;
}
	
	
	
	return 0;

}
