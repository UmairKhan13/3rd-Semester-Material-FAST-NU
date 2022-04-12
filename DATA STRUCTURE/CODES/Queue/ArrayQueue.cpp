#include<iostream>
#include<cstring>
using namespace std;

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
class ArrayQueue{

    private:
    DSA<T> *Q;
    int first;
    int last;
    int size;
    public:
    ArrayQueue();
    ArrayQueue(int size);
    ~ArrayQueue();
    void EnQueue(T data);
    T Dequeue();
    T& process();
    bool isEmpty();
    bool isFull();
};

template<class T>
ArrayQueue<T>::ArrayQueue()
{
    Q = new DSA<T>(0);
    first = last = -1;
    size = 0;
}
template<class T>
ArrayQueue<T>::~ArrayQueue()
{
	if(Q)
	delete Q;
}
template<class T>
ArrayQueue<T>::ArrayQueue(int size)
{
    Q = new DSA<T>(size);
    first = last = -1;
    this->size = size;
}
template<class T>
void ArrayQueue<T>::EnQueue(T data)
{
    if(!isFull())
    {
        if(last == size -1 || last == -1)
        {
            last = 0;
            Q->insert(last, data);

            if(first == -1)
            first = 0;
        }
        else
            Q->insert(++last, data);
        
    }
    else
    cout<<"Queue is full "<<endl;
    
}
template<class T>
T ArrayQueue<T>::Dequeue()
{
    T temp;
    if(!isEmpty())
    {
        if(first == last)
        {
            temp = Q->getValue(first);
            first = last = -1;
        }
        else if(first == size -1)
        {
            temp = Q->getValue(first);
            first = 0;
        }
        else
         temp = Q->getValue(first++);
    }
    else
    cout<<"Queue is empty"<<endl;
    return temp;
}
template<class T>
bool ArrayQueue<T>::isFull()
{
    return ((first == 0 && last == size -1) || (last == first-1) ) ;
}
template<class T>
bool ArrayQueue<T>::isEmpty()
{
    return ( (first == -1 ));
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
T DSA<T>::getValue(int index)
{
    return *(Data + index );
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
    ArrayQueue<int> q(5);
    q.EnQueue(5);
    q.EnQueue(6);
    q.EnQueue(10);
    q.EnQueue(3);
    q.EnQueue(9);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<endl;
    q.EnQueue(12);
    q.EnQueue(15);
    q.EnQueue(18);

    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    q.EnQueue(12);
    q.EnQueue(15);
    q.EnQueue(18);
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;

}
