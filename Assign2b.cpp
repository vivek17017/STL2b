#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1;
#define INDEX_INVALID 2;
#define ARRAY_UNDERFLOW 3;
template<typename X>
class DynArray
{
    private:
        int lastIndex;
        int capacity;
        X *ptr;
    public:
        DynArray();
        DynArray(int);
        void createArray(int);
        void doubleArray();
        void halfArray();
        bool isFull();
        bool isEmpty();
        void apend(X);
        void edit(X,int);
        void insertData(X,int);
        void deleteData(int);
        X getElement(int);
        int findElement(X);
        ~DynArray();
        void operator=(DynArray &);
        DynArray(DynArray<X> &);
        int getCapacity();
        int count();
};

template<typename X>
void DynArray<X>::doubleArray()
{
    capacity=2*capacity;
    X *temp=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
template<typename X>
void DynArray<X>::halfArray()
{
    capacity=capacity/2;
    X *temp=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
}
template<typename X>
DynArray<X>::DynArray()
{
    lastIndex=-1;
    ptr=nullptr;
    capacity=0;
}
template<typename X>
DynArray<X>::DynArray(int size)
{
    lastIndex=-1;
    capacity=size;
    ptr=new X[size];
}
template<typename X>
void DynArray<X>::createArray(int size)
{
    lastIndex=-1;
    capacity=size;
    ptr=new X[size];
}
template<typename X>
bool DynArray<X>::isEmpty()
{
    return lastIndex==-1;
}
template<typename X>
bool DynArray<X>::isFull()
{
    return lastIndex==capacity-1;
}
template<typename X>
int DynArray<X>::count()
{
    if(isEmpty())
        throw ARRAY_UNDERFLOW;
    return lastIndex+1;
}
template<class X>
void DynArray<X>::apend(X data)
{
    if(isFull())
        doubleArray();
    ptr[lastIndex+1]=data;
    lastIndex++;
}
template<class X>
int DynArray<X>::getCapacity()
{
    return capacity;
}
template<class X>
void DynArray<X>::edit(X data,int index)
{
    if(index<0||index>lastIndex)
        throw INDEX_INVALID;
    ptr[index]=data;
}
template<class X>
void DynArray<X>::insertData(X data,int index)
{
    if(index<0||index>lastIndex-1)
        throw INDEX_INVALID;
    if(isFull())
        doubleArray();
    for(int i=lastIndex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=data;
}
template<class X>
void DynArray<X>::deleteData(int index)
{
    if(isEmpty())
        throw ARRAY_OVERFLOW;
    if(index<0||index>lastIndex-1)
        throw INDEX_INVALID;
    for(int i=index;i<lastIndex-1;i--)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
    if(capacity/2>=lastIndex && capacity>1)
        halfArray();
}
template<class X>
X DynArray<X>:: getElement(int index)
{
    if(isEmpty())
        throw ARRAY_OVERFLOW;
    if(index<0||index>lastIndex-1)
        throw INDEX_INVALID;
    return ptr[index];
}
template<typename X>
int DynArray<X>::findElement(X data)
{
    if(isEmpty())
        throw ARRAY_OVERFLOW;
    for(int i=0;i<=lastIndex;i++)
        if(data==ptr[i])
            return i;
    return -1;
}
template<typename X>
DynArray<X>::~DynArray()
{
    delete []ptr;
}
template<typename X>
void DynArray<X>::operator=(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=nullptr)
        delete []ptr;
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];

}
template<typename X>
DynArray<X>::DynArray(DynArray<X> &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new X[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];

}
int main()
{

}