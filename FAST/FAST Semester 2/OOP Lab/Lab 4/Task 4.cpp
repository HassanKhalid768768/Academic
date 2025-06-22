#include<iostream>
using namespace std;

class Sample{
	
private:
	
	int x;
	double y;
	
public:

	Sample( ){ //Constructor 1
	x=0;
	y=0;
	}
	
	Sample(int a){ //Constructor 2
		x=a;
		y=1;
	}
	
	Sample(int b, int c){ //Constructor 3
		x=b;
		y=c;
	}
	
	Sample(int d, double e){ //Constructor 4
		x=d;
		y=e;
	}

};



int main(){
	Sample();
	Sample(10);
	Sample(20,30);
	Sample(40,50.70);
	
	return 0;
	}
