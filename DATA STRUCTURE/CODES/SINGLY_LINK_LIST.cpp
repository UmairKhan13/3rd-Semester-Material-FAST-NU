#include<iostream>
using namespace std;

class NODE
{
	public:
		int data;
		NODE* nextptr;
		
		NODE(int a = 0 , NODE* b = 0)
		{
			data = a;
			nextptr = b;
		}
	
};

class Singly_List
{
	private:
		NODE* head;
		int size;
		
	public:
	
	Singly_List(); 
	Singly_List( int , NODE* );
	void Insert_at_Head(int);//Insert at Start 
    void Insert_at_End(int);//Insert at last
    void Insert_Before(int, int);//insert before a specific position
    void Insert_Before_Data(int, int); ////insert before a specific Data
    void Insert_After(int, int);//Insert after a specific position
    void Insert_After_Data(int, int);//Insert after a specific Data
	void Insert_at(int, int);//Insert at a specific position
    void Delete_from_End();//Delete Last node
    void Delete_from_front();//Delete first node from front 
    void Delete_at(int);// Detele at a specific Position
    void Delete_before(int);// Delete the node before the position
    void Delete_After(int);//Delete the node after the position 
    void Delete_before_Data(int);// Delete the node before the data
    void Delete_After_Data(int);//Delete the node after the data 
	void Display();//Displays the list
    void Search_data(int);//search the data
    int Length_of_list();//counts the number of nodes in list
	
	int find(int x)
	{
		NODE* current = head;
		
		while( current->nextptr)
		{
			if(current->data + current->nextptr->data == x)
			{
				return 1;
			}
			current = current->nextptr;
		}
		
		return 0;
		
	}
	
};

int main()
{
	
Singly_List L;
L.Insert_at_End(22);
L.Insert_at_End(38);
L.Insert_at_End(49);
L.Insert_at_End(51);
L.Insert_at_Head(100);
L.Insert_at_Head(33);
L.Insert_at_Head(76);
L.Insert_at_Head(97);
L.Insert_at_Head(47);
L.Display();
L.Delete_from_front();
L.Display();
L.Delete_from_End();
L.Display();
L.Insert_After(99,1);
L.Display();
L.Insert_at(103,1);
L.Display();
L.Insert_Before(201,2);
L.Display();
L.Delete_at(6);
L.Display();
L.Delete_After(4);
L.Display();
L.Delete_before(2);
L.Display(); 
L.Delete_After_Data(38);
L.Display();
L.Delete_before_Data(97);
L.Display();
L.Insert_After_Data(200,97);
L.Display();
L.Insert_Before_Data(1000,97);
L.Display();
L.Search_data(99);
cout << "LENGHT OF LIST : ";
cout << L.Length_of_list();
if( L.find(60) )
{
	cout << endl << "FOUND";
}
else
{
	cout << endl << "NOT FOUND";
}

}

void Singly_List::Insert_Before_Data( int input_data , int data )
{
	cout << "INSERTING DATA BEFORE " << data << endl;
	
	if( head->data == data )
	{
		NODE* N = new NODE(input_data);
		N->nextptr = head;
		head = N;
		size++;
		return;	
	}
	
	NODE* current = head;
	while (current -> nextptr && current -> nextptr -> data != data)
	{
		current = current -> nextptr;
	}	
	NODE *N = new NODE(input_data);
	N -> nextptr = current -> nextptr;
	current -> nextptr = N;
	size++; 
	
	
}

void Singly_List::Insert_After_Data( int input_data , int data )
{
	cout << "INSERTING DATA AFTER " << data << endl;
	
	NODE *current = head;
	while (current -> nextptr && current -> data != data)
	{
		current = current -> nextptr;
	}
	NODE *n = new NODE(input_data);
	n -> nextptr = current -> nextptr;
	current -> nextptr = n;
	size++; 
}

void Singly_List::Delete_before_Data( int data )
{
	if( head->data == data )
	{
		cout << "ERROR!! NO ELEMENT EXIST BEFORE  " << data << endl;
		return;
	}
	
	NODE *current = head;
	
	cout << "DELETING DATA BEFORE " << data << endl;
	
	if( head->nextptr->data == data )
	{
		head = head->nextptr;
		size--;
		return;
	}
	
	while (current -> nextptr && current -> nextptr ->nextptr -> data != data)
	{
		current = current -> nextptr;
	}
	
	NODE* temp = NULL;
	temp = current->nextptr->nextptr ;
	current->nextptr = NULL;
	current->nextptr = temp;
	size--;
	
}

void Singly_List::Delete_After_Data( int data )
{
	NODE *current = head;
	
	cout << "DELETING DATA AFTER " << data << endl;
	
	while (current -> nextptr && current -> data != data)
	{
		current = current -> nextptr;
	}
	
	current -> nextptr = current -> nextptr -> nextptr;
	size--;
}

void Singly_List::Search_data( int data )
{
	NODE* current = head;
	int position = 0;
	
	while( current->nextptr && current->data != data )
	{
		current = current->nextptr;
		position++;
	}
	
	if( current->data == data )
	{
		cout << data << " WAS FOUND AT POSITION " << position + 1 << endl; ;
	}
	else
	{
		cout << data << " IS NOT IN LIST\n" ;
	}
	
}

void Singly_List::Delete_before( int position )
{
	if( position == 1 )
	{
		cout << "ERROR!! NO DATA EXIST BEFORE POSITION " << position << endl;
		return;
	}
	
	cout << "DELETING BEFORE POSITION " << position << endl;
	
	if( position == 2 )
	{
		head = head->nextptr;
		size--;
		return;
	}
	
	NODE* current = head;
	
	
	for( int i = 0 ; i < position - 3 ; i ++ )
	{
		current = current->nextptr;
	}
	
	current->nextptr = current->nextptr->nextptr;
	size--;
	
}

void Singly_List::Delete_After( int position )
{
	if( position == size )
	{
		cout << "ERROR!! NO SUCH POSITION EXIST.\n";
		return;
	}
	
	NODE* current = head;
	
	cout << "DELETING AFTER POSITION " << position << endl;
	
	for( int i = 0 ; i < position - 1 ; i ++ )
	{
		current = current->nextptr;
	}
	current->nextptr = current->nextptr->nextptr;
	size--;
	
}

void Singly_List::Delete_at( int position )
{
	
	cout << "DELETING AT POSITION " << position << endl;
	
	if( position == 1)
	{
		head = head->nextptr;
		size --;
		return;
	}
	
	NODE* current = head;
	
	for( int i = 0 ; i < position - 2 ; i++ )
	{
		current = current->nextptr;
	}
	
	current->nextptr = current->nextptr->nextptr ;
	size--;
	
	
}

void Singly_List::Insert_Before(int data , int position) // inset before position
{
	if( position == 1)
	{
		cout << "ERROR!! CAN'T INSERT BEFORE 1";
		return;
	}
	
	NODE* current = head;
	
	if( position != 2)
	{
	for(int i = 0 ; i < position - 3 ; i++ )
	{
		current = current->nextptr;
	}
	
	cout << "INSERTING " << data << " BEFORE POSITION " << position << endl;
	NODE* N = new NODE(data);
	N->nextptr = current->nextptr;
	current->nextptr = N;
	size++;
	}
	else
	{
			NODE* N = new NODE(data);
			cout << "INSERTING " << data << " BEFORE POSITION " << position << endl;
			head = N;
			head->nextptr = current;
			size++; 		
	}
	
}
	

void Singly_List::Insert_at( int data , int position )
{
	NODE* current = head;
	
	if( position != 1)
	{
	for(int i = 0 ; i < position - 2 ; i++ )
	{
		current = current->nextptr;
	}
	
	cout << "INSERTING " << data << " AT POSITION " << position << endl;
	NODE* N = new NODE(data);
	N->nextptr = current->nextptr;
	current->nextptr = N;
	size++;
	}
	else
	{
	cout << "INSERTING " << data << " AT POSITION " << position << endl;
	NODE* N = new NODE(data);
	head = N;
	head->nextptr = current;
	size++;
	}
	
}

void Singly_List::Insert_After( int data , int position )
{	
	NODE* current = head;
	
	for(int i = 0 ; i < position - 1 ; i ++)
	{
		current = current->nextptr;	
	}
		
	cout << "INSERTING " << data << " AFTER POSITION " << position << endl;
	NODE* N = new NODE(data);
	N->nextptr = current->nextptr;
	current->nextptr = N;
	size++;
	
}

void Singly_List::Delete_from_End()
{
	NODE *current = head;
	
	while(current->nextptr->nextptr)
	{
	   current = current->nextptr;	
	}
	
	cout << "DELETING FROM END" << endl ;
	current->nextptr=NULL;
	size--;
}

void Singly_List::Delete_from_front()
{
	NODE *current = head;
	
    if( head == 0)
    {
    	cout << "LIST IS EMPTY";
    	return;
	}
	
	cout << "DELETING FROM FRONT. " << endl ;
	head = head->nextptr;
	size--;
	delete current;
	
}

int Singly_List::Length_of_list()
{
	return size;
}

Singly_List::Singly_List()
{
	head = NULL ;
	size = 0 ;
	head = new NODE();
}

Singly_List::Singly_List(int,NODE*)
{
	
}

void Singly_List::Insert_at_End(int data)
{
	NODE* current = head ;
	
	if( size == 0 )
	{
	head = new NODE(data);
	size++;
	return;
	}
	
	while(current->nextptr)
	{
		current = current->nextptr;
	}
	
	current->nextptr = new NODE(data);
	size++;
	
}

void Singly_List::Insert_at_Head(int data)
{
	if( head != 0)
	{
	NODE* current = new NODE(data);
	current->nextptr = head;
	head = current;
	size++; 
	}
	else
	{
		head = new NODE(data);
	}
}

void Singly_List::Display()
{
	NODE* current = head;
	cout << "LINK LIST : { " ;
	int i = 0;
	while(current)
	{
		cout << current->data ;
		current = current->nextptr;
		if(i!=size-1)
		{
			cout << " , " ;
		}
		i++;
	}
	cout << " }\n";
}
