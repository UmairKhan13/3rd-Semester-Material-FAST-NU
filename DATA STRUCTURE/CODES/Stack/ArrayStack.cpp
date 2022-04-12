#include<iostream>
#include<cstring>
using namespace std;
#define MAX 30
template<class T>
class DSA;
template<class T>
class ArrayStack;

template<class T>
class DSA{
	
	private:
		int size;
		T * Data;
	public:
	
	     DSA(); // it is default constructor which assigns 0 to size and data
	     DSA(int Size); //Construtor to intialize and to allocate memory for variable memebers;
		 DSA(const DSA<T>& rhs); // copy constructor
	     ~DSA();
	     int Size(); // it returns size of array
	     void ReSize(int nSize);
		 DSA<T>& operator = (const DSA<T>& rhs); // assignment operator overloading
		 T& operator [](int i); // it returns refence of of given element index
		 const T& operator[](int i) const; // it just return value at given index
		 bool find(T element); // 
		  void printArray();
		 T getValue(int i);
		 void insert(int i  , T data);
};

template<class T>
class ArrayStack
{
private:
    int top;
    DSA<T> *stk;
public:
    ArrayStack();
    ArrayStack(int);
    ~ArrayStack();
    void push(T d);
    T pop();
    ArrayStack<T>& multiPop(int elements);
    void multiPush(DSA<T>& stack);
    T& peek();
    bool isFull();
    bool isEmpty();

};

template<class T>
ArrayStack<T>::ArrayStack()
{
    stk = new DSA<T>(0);
    top = -1;
}
template<class T>
ArrayStack<T>::ArrayStack(int size)
{
    stk = new DSA<T>(size);
    top = -1;
}
template<class T>
ArrayStack<T>::~ArrayStack()
{
    if(stk)
    delete stk;
}
template<class T>
void ArrayStack<T>::push(T d)
{
    if(!isFull())
    stk->insert(++top , d);

}
template<class T>
T ArrayStack<T>::pop()
{
    if(!isEmpty())
    {
   	 return stk->getValue(top--) ;	
	}
	else
	return 0;
    
}
template<class T>
bool ArrayStack<T>::isFull()
{
    return top>=MAX ;
}
template<class T>
bool ArrayStack<T>::isEmpty()
{
    return top == -1 ;
}
template<class T>
void ArrayStack<T>::multiPush(DSA<T> &obj)
{
    ArrayStack<T> *temp;
    while(!obj.isEmpty())
    {
        temp->push(obj.pop());
    }

    while (!temp->isEmpty())
    {
        push(temp->pop());
    }
    
}
template<class T>
ArrayStack<T>& ArrayStack<T>::multiPop(int elements)
{
    ArrayStack<T> *temp;

    for (int i = 0; i < elements; i++)
    {
        temp->push(pop());
    }
    return temp;
    
}
template<class T>
T& ArrayStack<T>::peek()
{
	return stk[top];
}

template<class T>
DSA<T>::DSA () 
	{
		size=0;
	}
template<class T>	
DSA<T>::DSA (int Size) 
	{
		Data=new T[Size];
		size=Size;
	}
template<class T>
DSA<T>::DSA(const DSA & rhs){
			
			 this->size= size;
			 this->Data= new T[size];
			 memcpy(this->Data,rhs.Data,(sizeof(T)*size));
}
template<class T>
void DSA<T>::insert(int i , T data)
{
	*(Data + i) = data;
}
template<class T>
T DSA<T>::getValue(int index)
{
    return *(Data + index );
}
template<class T>
DSA<T>& DSA<T>:: operator=( const DSA<T> & rhs)
{
    if (this  != &rhs)
        {
        int s=rhs.size; 
        this->size=s;
        this->Data= new T[s];
        memcpy(this->Data,rhs.Data, sizeof(T)*s);
        }
	return (*this);
         
}

template<class T>
T& DSA<T>::operator [] (int i){   
   		
   		
   			 return (*(Data+i));
}

template<class T>
const T& DSA<T>::operator [] (int i) const {   
   		
   			return (*(Data+i));
}

template<class T>
int DSA<T>::Size ()
	{
		return size;
	}
	
template<class T>
void DSA<T>::ReSize(int nSize)
{
	if (size != nSize )  
			{
				T * temp= new T[size];
			 	
			    for(int i=0; i<size ; i++)
			    	temp[i]= *(Data+i);

			    delete[] Data;
			    Data=0;
			    
			    Data = new T[nSize];
			    memset(this->Data, 0, sizeof(T)*nSize);

  				for(int i=0; i<size ; i++)
			    	*(Data+i)=temp[i];

			    size= nSize;
			    delete [] temp;
			    temp=0;
  	
				
			} 		
}

template<class T>
DSA<T>::~DSA(){

 if (Data != 0)
 {
 	delete [] Data;
 	Data=0;
 	size=0;
 }
}
	
template<class T>
void DSA<T>::printArray()
{
	for(int i = 0 ; i < size -1 ; i ++)
		cout<< * ( Data + i ) ;
	cout<<endl;
}

template<class T>
bool DSA<T>::find(T element)
{
	for(int i = 0 ; i < size ; i ++)
	{
		if(element == Data[i])
		return true;
	}
	
	return false;
}


int main()
{
	ArrayStack<int> stack(10);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
}
