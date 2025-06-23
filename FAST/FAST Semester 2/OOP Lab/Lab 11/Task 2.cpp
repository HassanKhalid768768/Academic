#include <iostream>

using namespace std;


class Account{

public:
    int accountnumber;
    float accountbalance;




    void setaccountnumber(int n){
    accountnumber=n;
    }

    void setaccountbalance(float n){
    accountbalance=n;
    }

    int getaccountnumber(){
    return accountnumber;
    }

    float getaccountbalance(){
    return accountbalance;
    }

    virtual void credit(float n)=0;

    virtual void debit(float m)=0;

    virtual void Print(){
    }
};

class CurrentAccount: public Account{
public:
    float servicecharges;
    float minimumbalance;



    void Print(){

    cout<<endl<<"Account Number : "<<accountnumber<<endl;
    cout<<"Account Balance : "<<accountbalance<<endl;
    cout<<"Minimum Balance : "<<minimumbalance<<endl;
    cout<<"Service Charges : "<<servicecharges<<endl;

    }

    void credit(float n){
    accountbalance=accountbalance+n;
    }

    void debit(float m){
        if(accountbalance>=m){
            accountbalance=accountbalance-m;
            if(accountbalance<minimumbalance){
                accountbalance=accountbalance-servicecharges;
            }
        }
    }

};

class SavingAccount: public CurrentAccount{
public:
    float InterestRate;

    void Print(){
    cout<<endl<<"Account Number : "<<accountnumber<<endl;
    cout<<"Account Balance : "<<accountbalance<<endl;
    cout<<"Interest Rate : "<<InterestRate<<endl;
    }

    void credit(float n){
    accountbalance=accountbalance+n;
    }

    void debit(float m){
        if(accountbalance>=m){
            accountbalance=accountbalance-m;
        }
    }

};


    int main()
{
    CurrentAccount ca;
    Account* a=&ca;
    int ACCOUNTNUMBER;
    float ACCOUNTBALANCE,MINIMUMBALANCE,SERVICECHARGES,INTERESTRATE,CREDIT,DEBIT;

    cout<<"Enter Account Number : ";
    cin>>ACCOUNTNUMBER;
    ca.accountnumber=ACCOUNTNUMBER;
    cout<<endl<<"Enter Account Balance : ";
    cin>>ACCOUNTBALANCE;
	ca.accountbalance=ACCOUNTBALANCE;
    cout<<endl<<"Enter Minimum Balance : ";
    cin>>MINIMUMBALANCE;
    ca.minimumbalance=MINIMUMBALANCE;
    cout<<endl<<"Enter Service Charges : ";
    cin>>SERVICECHARGES;
    ca.servicecharges=SERVICECHARGES;
     cout<<endl<<"Enter Interest Rate : ";
    cin>>INTERESTRATE;
    cout<<endl<<"Enter Amount to Credit : ";
    cin>>CREDIT;
    cout<<endl<<"Enter Amount to Debit : ";
    cin>>DEBIT;

    a->credit(CREDIT);
    a->debit(DEBIT);
    a->Print();


    return 0;


}
