#include<iostream>

using namespace std;

template <class T>
class DNode ;

template <class T>
class DLL ;

template <class T>
class DNode{

    public :
    T Data;
    DNode<T> *next;
    DNode<T> *prev;

    public:

    DNode();
    DNode(T Data);
    void  setNext(DNode *node);
    void setPrev(DNode *node);
    DNode<T> getNext();
    DNode<T> getPrev();

};

template<class T>
class DLL{
    private:
    DNode<T> * head;
    DNode<T> * tail;
    int size;
    public:
    DLL();
    void insertAtFront(T value);
    void insertAtEnd(T value);
    void insertAt(int position, T value);
    void deleteFromFront();
    void deleteFromEnd();
    void deleteAt(int position);
    void printInForward();
    void printInReverse();
	int getLength();
	int search(T value);
	void sort();
};


template<class T>
DNode<T>::DNode(): prev(0), next(0) {}

template<class T>
DNode<T>::DNode(T value) : Data(value), prev(0) , next(0) {}

template<class T>
void DNode<T>::setNext(DNode *node)
{
    next = node;
}

template<class T>
void DNode<T>::setPrev(DNode *node)
{
    prev = node;
}

template<class T>
DNode<T> DNode<T>::getNext(){ return next ;}

template<class T>
DNode<T> DNode<T>::getPrev(){ return prev ;}

template<class T>
DLL<T>::DLL()
{
    head = 0;
    tail = 0;
    size = 0;
}

template<class T>
void DLL<T>::printInForward()
{
    DNode<T> *temp = head;
    
    while(temp != tail)
    {
        cout<< temp->Data<<" , ";
        temp = temp->next;
    }
    cout<< temp->Data<<" , ";
    cout<<endl;
}
template<class T>
void DLL<T>::printInReverse()
{
	DNode<T> *temp = tail;
	
	while(temp != head)
	{
		cout<<temp->Data<<" , ";
		temp = temp->prev;
	}
		cout<<temp->Data<<" , ";
		cout<<endl;
}
template<class T>
void DLL<T>::insertAtFront(T value)
{
    DNode<T> *newNode = new DNode<T>(value);

    if(size==0)
    {
        head = newNode;
        tail = newNode;

        newNode->next  = tail;
        newNode->prev = tail;        
    }
    else
    {

        DNode<T> *temp = head;
        while (temp != tail)
        {
            temp = temp->next;
        }

        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        head = newNode;
        temp->next = head;
    }
    size++;
    
}
template<class T>
void DLL<T>::insertAtEnd(T value)
{
	DNode<T> *newNode = new DNode<T>(value);
	if(head == 0)
	{
		head = newNode;
        tail = newNode;

        newNode->next  = tail;
        newNode->prev = tail;	
	}
	else
	{
		newNode->next = tail->next;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}
template<class T>
void DLL<T>::insertAt(int pos, T value)
{
	if(size == 0 && pos > 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else if(pos == 0)
	{
		insertAtFront(value);
	}
	else if(pos == size -1 )
	{
		insertAtEnd(value);
	}
	else
	{
		DNode<T> *temp = head;
		
		for(int i = 0 ; i < pos ; i++)
		{
			temp = temp->next;
		}
		
		DNode<T> *newNode = new DNode<T>(value);
		
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		
		size++;
	}
}
template<class T>
void DLL<T>::deleteFromFront()
{
	if(head==0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{
		head->next->prev = head->prev ;
		head = head->next;
		tail->next = head;
		size--;
	}
}
template<class T>
void DLL<T>::deleteFromEnd()
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else
	{
		tail->prev->next = head ;
		tail = tail->prev;
		head->prev = tail;
		size--;
	}
}
template<class T>
void DLL<T>::deleteAt(int pos)
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	else if(pos == 0)
	deleteFromFront();
	else if(pos == size - 1)
	deleteFromEnd();
	else
	{
		DNode<T> *temp = head;
		
		for(int i = 0 ; i < pos ; i ++)
		temp = temp->next;
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		size--;
	}
}
template<class T>
int DLL<T>::getLength() {
	return size;
}

template<class T>
int DLL<T>::search(T value)
{
	if(head == 0)
	{
		cout<<"List is empty"<<endl;
		return -1;
	}
	else
	{
		DNode<T> *temp = head;
		int count = 0;
		while(temp != tail )
		{
			if(temp->Data == value)
			return count;
			
			temp = temp->next;
			count++;
		}
		
		if(temp->Data = value)
			return count;
	}
	
	cout<<"Not found"<<endl;
}
template<class T>
void DLL<T>::sort()
{
	if(size==1 || size == 0)
	return;
	if(size == 2)
	{
		
	}
	else
	{
		DNode<T> *temp = head;
		
		do
		{
			DNode<T> *inner = temp;
			
			do
			{
				if((inner->Data) > (inner->next->Data))
				{
					DNode<T> *tempNext = inner->next;
					DNode<T> *tempPrev = inner->prev;
					bool headFlag = false , NullFlag = false; 
					
					if(tempPrev == head )
					headFlag = true;
					if(tempNext->next == 0)
					NullFlag = true;
					
					
					inner->next= inner->next->next;
					inner->next->prev = inner;
					inner->prev = tempNext;
					tempNext->next = inner;
					tempPrev->next = tempNext;
					
					if(headFlag == true)
					head = tempNext;
					if(NullFlag == true)
					tempNext->next->next = 0;
				}
				inner = inner->next;
			}while(inner != 0);
			temp = temp->next;
		}while(temp != 0);
	}
	
}
int main()
{
    DLL<int> *list = new DLL<int>();
    list->insertAtFront(4);
    list->insertAtFront(1);
    list->insertAtFront(10);
    list->insertAtEnd(30);
    list->insertAtEnd(90);
    list->insertAtFront(20);
    list->printInForward();
    list->insertAt(3,50);
    list->printInForward();
    list->deleteFromFront();
    list->printInForward();
    list->deleteFromEnd();
    list->printInForward();
    cout<<"Search 1"<<endl;
    cout<<list->search(1)<<endl;
    list->deleteAt(3);
    list->printInForward();
    list->printInReverse();
    cout<<"Size of list =  "<<list->getLength();
    list->sort();
    list->printInForward();
}
