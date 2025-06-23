#include <iostream>
using namespace std;

class Package{
public:
    string sendername;
    string senderaddress;
    string sendercity;
    string senderstate;
    int senderzipcode;

    string recipentname;
    string recipentaddress;
    string recipentcity;
    string recipentstate;
    int recipentzipcode;

    double weight;
    double cost;


    Package(){
        sendername="";
        senderaddress="";
        sendercity="";
        senderstate="";
        senderzipcode=0;

        recipentname="";
        recipentaddress="";
        recipentcity="";
        recipentstate="";
        recipentzipcode=0;

        weight=0.0;
        cost=0.0;
    }

    void setweight(double m){
    m=weight;
    }

    void setcost(double m){
    m=cost;
    }

    virtual double calculateCost(){
        double totalcost;
        totalcost=weight*cost;
        return totalcost;
    }

};

class TwoDayPackage: public Package{
private:
    double flatfee;
public:
    TwoDayPackage(double m,double d1,double d2){
        flatfee=m;
        weight=d1;
        cost=d2;
    }

    double calculateCost(){
        double totalcost;
        totalcost=weight*cost;
        totalcost+=flatfee;
        cout<<endl<<"Total Cost for Two Day Package :"<<totalcost;
    }
};

class OvernightPackage: public Package{
private:
    double additionalfee;
public:
    OvernightPackage(double m,double d1,double d2){
        additionalfee=m;
        weight=d1;
        cost=d2;
    }

    double calculateCost(){
    double totalcost,temp1,temp2;
        temp1=weight*cost;
        temp2=weight*additionalfee;
        totalcost=temp1+temp2;
        cout<<endl<<"Total Cost for Overnight Package : "<<totalcost;
    }
};


int main()
{
    string s1,s2,s3,s4,s5,s6,s7,s8;
    int n1,n2;
    double d1,d2,d3,d4;

cout<<"Enter Name of sender : ";
cin>>s1;
cout<<"Enter Address of sender : ";
cin>>s2;
cout<<"Enter City of sender : ";
cin>>s3;
cout<<"Enter State of sender : ";
cin>>s4;
cout<<"Enter ZipCode of sender : ";
cin>>n1;
cout<<endl<<"Enter Name of recipent : ";
cin>>s5;
cout<<"Enter Address of recipent : ";
cin>>s6;
cout<<"Enter City of recipent : ";
cin>>s7;
cout<<"Enter State of recipent : ";
cin>>s8;
cout<<"Enter ZipCode of recipent : ";
cin>>n2;
cout<<endl;

do{
cout<<"Enter Weight of parcel : ";
cin>>d1;
}while(d1<=0);
do{
cout<<"Enter Cost Per Ounce : ";
cin>>d2;
}while(d2<=0);
do{
cout<<"Enter Flat fee : ";
cin>>d3;
}while(d3<=0);
do{
cout<<"Enter Additional Fee : ";
cin>>d4;
}while(d4<=0);
cout<<endl;

TwoDayPackage t1(d3,d1,d2);
OvernightPackage t2(d4,d1,d2);
cout<<"============================="<<endl;
cout<<"Name of sender : ";
cout<<s1;
cout<<endl<<"Address of sender : ";
cout<<s2;
cout<<endl<<"City of sender : ";
cout<<s3;
cout<<endl<<"State of sender : ";
cout<<s4;
cout<<endl<<"ZipCode of sender : ";
cout<<n1;
cout<<endl<<endl<<"Name of recipent : ";
cout<<s5;
cout<<endl<<"Address of recipent : ";
cout<<s6;
cout<<endl<<"City of recipent : ";
cout<<s7;
cout<<endl<<"State of recipent : ";
cout<<s8;
cout<<endl<<"ZipCode of recipent : ";
cout<<n2<<endl;


Package *temp1=&t1;
Package *temp2=&t2;
temp1->calculateCost();
temp2->calculateCost();
cout<<endl;

    return 0;
}
