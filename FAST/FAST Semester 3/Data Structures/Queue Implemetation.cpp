#include <iostream>
using namespace std;

class Queue
{
    int front; 
    int rear;
    int maxsize;
    int currsize;
    int *arr;
    
    public:
    
    Queue(int n=10)
    {
        front=-1;
        rear=-1;
        maxsize=n;
        currsize=0;
        arr=new int [maxsize];
    }
    
    ~Queue()
    {
        if(arr!=0)
        {
            delete[] arr;
            arr=0;
        }
    }
    
    bool isFull()
    {
        if(currsize==maxsize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isEmpty()
    {
        if(currsize==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool enqueue(int val)
    {
        if(isFull())
        {
            return false;
        }
        else
        {
            rear=(rear+1)%maxsize;
            arr[rear]=val;
            currsize++;
            return true;
        }
    }
    
    bool dequeue()
    {
        int val;
        if(isEmpty())
        {
            return false;
        }
        else
        {
            front=(front+1)%maxsize;
            val=arr[front];
            currsize--;
            return true;
            return val;
        }
    }
    
    int rearvalue()
    {
        return arr[rear];
    }
    
     int frontvalue()
    {
        return arr[front];
    }
    
    int size()
    {
        return currsize;
    }

};

int main()
{
    cout<<"Hello World";

    return 0;
}