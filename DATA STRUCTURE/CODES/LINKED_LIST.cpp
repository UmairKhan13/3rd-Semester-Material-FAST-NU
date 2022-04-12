#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	
	Node(int a = 0, Node *b = 0)
		: data(a)
		, next(b)
	{}
};

class SLL {  
    public:  
    Node *head; 
	int size;
    
    SLL();
    SLL(int, Node*);
    void Insert_at_Head(int);//Insert at Start 
    void Insert_at_End(int);//Insert at last
    void Insert_Before(int, int);//insert before a specific data
    void Insert_After(int, int);//Insert after a specific data
    void Insert_at(int, int);//Insert at a specific position
    void Delete_from_End();//Delete Last node
    void Delete_from_front();//Delete first node from front 
    void Delete_at(int);// Detele at a specific Position
    void Delete_before(int);// Delete the node before the data
    void Delete_After(int);//Delete the node after the data 
    void Display();//Displays the list
    int Search_data(int);//search the data and return the node number if present,  else return -1.  
    int Length_of_list();//counts the number of nodes in list
};


int main() {
	SLL s;
	cout << "inserting 5 at end: " << endl;
	s.Insert_at_End(5);
	s.Display();
	cout << "inserting 4 at head: " << endl;
	s.Insert_at_Head(4);
	s.Display();
	cout << "inserting 3, 1 at end: " << endl;
	s.Insert_at_End(3);
	s.Insert_at_End(1);
	s.Display();
	cout << "inserting 6 before 3: " << endl;
	s.Insert_Before(6, 3);
	s.Display();
	cout << "inserting 7 after 1: " << endl;
	s.Insert_After(7, 1);
	s.Display();
	cout << "inserting 8 at index 3: " << endl;
	s.Insert_at(8, 3);
	s.Display();
	cout << "deleting from end: " << endl;
	s.Delete_from_End();
	s.Display();
	cout << "deleting from front: " << endl;
	s.Delete_from_front();
	s.Display();
	cout << "deleting at index 2: " << endl;
	s.Delete_at(2);
	s.Display();
	cout << "deleting before 8: " << endl;
	s.Delete_before(8);
	s.Display();
	cout << "deleting after 3: " << endl;
	s.Delete_After(3);
	s.Display();
	cout << "searching for index of 3 (-1 if not found): " << endl;
	cout << s.Search_data(3) << endl;
	cout << "searching for index of 6 (-1 if not found): " << endl;
	cout << s.Search_data(6) << endl;
	cout << "size of list: " << endl;
	cout << s.Length_of_list() << endl;
	
}



SLL::SLL():head(0), size(0)
{
	head = new Node;
}

SLL::SLL(int, Node*){}

void SLL::Insert_at_Head(int x){//Insert at Start
 Node *n = new Node(x);
 n -> next = head;
 head = n;
 size++;
}

void SLL::Insert_at_End(int x){//Insert at last

	Node *current = head;
	
	if (!size) {
		head = new Node(x);
		size++;
		return;
	}
		
	
	
	while (current -> next) current = current -> next;
	
	current -> next = new Node(x);
	
	size++;

}
void SLL::Insert_Before(int x, int y){//insert before a specific data
	Node *current = head;
	while (current -> next && current -> next -> data != y)
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 
}
void SLL::Insert_After(int x, int y){//Insert after a specific data
	Node *current = head;
	while (current -> next && current -> data != y)
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 

}
void SLL::Insert_at(int x, int y){//Insert at a specific position
	Node *current = head;
	for (int i = 0; i < y - 1; i++) 
		current = current -> next;
	Node *n = new Node(x);
	n -> next = current -> next;
	current -> next = n;
	size++; 

}
void SLL::Delete_from_End(){//Delete Last node
	Node *current = head;
	while (current -> next -> next) current = current -> next;
	current -> next = 0;
	size--;
}
void SLL::Delete_from_front(){//Delete first node from front 
	head = head -> next;
	size--;
}
void SLL::Delete_at(int y){// Detele at a specific Position
	Node *current = head;
	for (int i = 0; i < y - 2; i++)
		current = current -> next;
	current -> next = current -> next -> next;
	size--; 
}
void SLL::Delete_before(int x){// Delete the node before the data
	Node *current = head;
	while (current -> next && current -> next -> data != x)
		current = current -> next;
	current -> next = current -> next -> next;
	size--;
}
void SLL::Delete_After(int x){//Delete the node after the data 
	Node *current = head;
	while (current -> next && current -> data != x)
		current = current -> next;
	current -> next = current -> next -> next;
	size--;
}
void SLL::Display(){//Displays the list
	Node *current = head;
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << current -> data;
		if (i != size - 1) cout << ", ";
		current = current -> next;
	} cout << "}" << endl;

}
int SLL::Search_data(int x){//search the data and return the node number if present, else return -1.  
	Node *current = head;
	int index = 0;
	while (current) {
		if (current -> data == x) return index;
		current = current -> next;
		index++;
	}
	return -1;
}
int SLL::Length_of_list(){//counts the number of nodes in list	
	return size;
}

