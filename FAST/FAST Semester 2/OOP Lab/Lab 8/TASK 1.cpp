#include<iostream>
    using namespace std;

    class BiggerInt{

        int *big_int_;
        int int_length_;
		int size;
		
        public:

        BiggerInt(){
		big_int_ = {0};
        int_length_ = 0;
        size = 0;
		}
		
        BiggerInt(int* b1 , int b2) 
		{
        big_int_ = b1;
        int_length_ = b2;
		}
		
		BiggerInt(BiggerInt &B) 
		{
        int_length_ = B.int_length_;
        big_int_ = new int [B.int_length_];
        for(int i = 0 ; i < B.int_length_ ; i++)
        {
            big_int_[i] = B.big_int_[i];
        }
		}
		
		
		int & operator[](int n);
		
    BiggerInt operator=(BiggerInt &B)
    {
        int_length_ = B.int_length_;
        for(int i = 0 ; i < int_length_ ; i++)
        {
            big_int_[i] = B.big_int_[i];
        }
        return B;
    }
	
	
	
	   
    ~BiggerInt () {
	    
	}



	 BiggerInt operator++(int)
    {
        this->int_length_ = int_length_;
        for(int i = 0 ; i < int_length_ ; i++)
        {
            big_int_[i] = ++(this-> big_int_[i]);
        }
        cout<<"Prefix Increment  : ";
        for(int i = 0 ;  i < int_length_ ; i++)
        {
            cout<<big_int_[i]<<" ";
        }
    }
    
    
    
		 BiggerInt operator--(int) 
    {
        this->int_length_ = int_length_;
        for(int i = 0 ; i < int_length_ ; i++)
        {
            big_int_[i] = --(this-> big_int_[i]);
        }
        cout<<"Prefix Decrement  : ";
        for(int i = 0 ; i < int_length_ ; i++)
        {
            cout<< big_int_[i]<<" ";
        }
        
        
        
    }
    BiggerInt operator++() 
    {
        this -> int_length_ = int_length_;
         cout<<"Postfix Increment : ";
        for(int i = 0 ; i < int_length_ ; i++)
        
        {
    
            cout<<this->big_int_[i]++<< " ";
        }
       
       
    }



     BiggerInt operator--() 
    {
        this->int_length_ = int_length_;
        cout<<"Postfix Decrement : ";
        for(int i = 0 ; i < int_length_ ; i++)
        {
            cout<<this->big_int_[i]--<<" ";
        }
        
       
    }


    };
    
    int & BiggerInt :: operator [](int n)
{
    if(n >= 0 || n < int_length_)
    {
        return n;
    }
    else
    {
        cout<<"NOT IN BOUNDS";
    }
}


    int main(){
    int size;
    cout<<"Enter Size :  ";
    cin >> size;
    int *Array;
    Array = new int[size];
    for(int i = 0 ; i < size ; i++)
    {
    	cout<<"Enter Elements : ";
        cin >> Array[i];
    }
    BiggerInt B(Array,size);
    B[size];
    cout<<endl;
    ++B;
    cout<<endl;
    --B;
    cout<<endl;
    B++;
    cout<<endl;
    B--;
    cout<<endl;
    return 0;


    }
