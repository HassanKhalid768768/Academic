#include<iostream>
    using namespace std;

    class BiggerInt{

        int*big_int_= nullptr ;
        int int_length_;

        public:

        BiggerInt(int=0);
        void assign(int, int);
        BiggerInt(const BiggerInt &) ;
        void display(BiggerInt) const;
        void append(int);
        ~BiggerInt();
    };

    BiggerInt::BiggerInt(int SIZE){
    int_length_ = SIZE;
    big_int_ = new int[int_length_];
    for (int i = 0; i < int_length_; i++){
        big_int_[i] = 0;}
    }

    void BiggerInt::assign(int val, int index){
    if (index >= 0 || index<=int_length_)
        big_int_[index] = val;
    else
        cout << "Please Enter Size Again\n Wrong Size Entered"<<endl;
    }

    BiggerInt::BiggerInt(const BiggerInt & SIZE){
    int_length_ = SIZE.int_length_;
    big_int_ = new int[this->int_length_];
    for (int i = 0; i < this->int_length_; i++)
        {
        big_int_[i] = SIZE.big_int_[i];
        }
    }

    void BiggerInt::display(BiggerInt SIZE) const{
    cout << "Data of calling object array 1 \n";
    for(int i=0; i<this->int_length_; i++)
    {
    cout << this->big_int_[i] << endl;
    }
    cout << "Data of parameter array 2\n";
    for (int i = 0; i<SIZE.int_length_; i++)
    {
    cout << SIZE.big_int_[i] << endl;
    }
    }

    void BiggerInt::append(int n_size){
    int * arr = new int[n_size];
    if (n_size < this->int_length_)
    {
    for (int i = 0; i < n_size; i++)
    {
    arr[i] = this->big_int_[i];
    }
    }
    else
    {
    int i;
    for (i = 0; i < int_length_; i++)
    {
    arr[i] = this->big_int_[i];
    }
    while (i < n_size)
    {
    arr[i++] = 0;
    }
    }
    delete[] this->big_int_;
    this->big_int_ = arr;
    this->int_length_ = n_size;
    }

    BiggerInt::~BiggerInt(){
    delete[] this->big_int_;
    }

    int main(){
    int int_length_,size1;
    cout << "Enter size of array 1" << endl;
    cin >> int_length_;
    BiggerInt arr1(int_length_);
    int value;
    cout << "Enter data \n";
    for (int i = 0; i < int_length_; i++)
    {
    cout << "Enter Value : ";
    cin >> value;
    arr1.assign(value, i);
    }

    cout << "Enter size of array 2: ";
    cin >> int_length_;

    BiggerInt arr2(int_length_);
    arr1.display(arr2);

    cout << "Enter data \n";
    for (int j = 0; j < int_length_; j++)
    {
    cout << "Enter Value : ";
    cin >> value;
    arr2.assign(value, j);
    }
    arr1.display(arr2);
    cout << "Enter Size Of New Array" << endl;
    cin >> size1;
    arr1.append(size1);
    arr1.display(arr2);

    }
