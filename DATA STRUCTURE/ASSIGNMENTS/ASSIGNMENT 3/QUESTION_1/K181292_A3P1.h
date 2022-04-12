#ifndef K181292_A3P1_H
#define K181292_A3P1_H
#include<queue>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;


int COUNTER = 0,MAXIMUM = 0,TESTING;



struct Node {
	
		int data;
		Node* left;
		Node* right;
	
	public:
		
		Node()
		{
			data = -1;
			left = NULL;
			right = NULL;
		}
		
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
	
	void longestSequence( Node* HEAD )
	{
		if( HEAD->left != NULL )
 		{
 			HEAD->left->longestSequence( HEAD->left );
	 	}
	 			
		 Go_Left_Ka_Right( HEAD );
   			
		if( HEAD->right!=NULL )
 		{
 			HEAD->right->longestSequence( HEAD->right );
	 	}
	}
	
	friend void Go_Left_Ka_Right( Node *HEAD );
		
};

Node* RESULT;

int Go_RIGHT_SIDE( Node* Head )
{
	int text = 0;
	
	while( Head != NULL )
	{
		text++;
		Head = Head->right;
	}
	
	return text;
}


int GO_LEFT_SIDE( Node* Head )
{
	int text = 0;
	
	while( Head != NULL )
	{
		text++;
		Head = Head->left;
	}
	
	return text;
}



 void Go_Left_Ka_Right( Node *HEAD )
 {
 	
 	    int Right_Side = Go_RIGHT_SIDE( HEAD );
 	    int Left_Side = GO_LEFT_SIDE( HEAD );
 	    
	if( Right_Side > Left_Side)
 	    {
 	    	if(Right_Side > MAXIMUM )
 	    	{
			 	MAXIMUM = Right_Side;
 	    		RESULT = HEAD;
 	    		TESTING = 1;
			 }
		 }
		 else if( Left_Side > Right_Side )
		 {
		 	if( Left_Side > MAXIMUM )
 	    	{
 	    		MAXIMUM = Left_Side;
 	    		RESULT = HEAD ;
 	    		TESTING = 0;
			 }
		 }
}




class BinarySearchTree{
	
	private:
		Node* head;
		
		void DestroyRecursive(Node* node)
		{
		    if (node != NULL)
		    {
		        DestroyRecursive(node->left);
		        DestroyRecursive(node->right);
		        delete node;
		    }
		}
		
		void _inOrder(Node* n)
		{
			if(!n)
				return;
			
			_inOrder(n->left);
			cout<<n->data<<", ";
			_inOrder(n->right);
		}
		
		Node* _insert(Node* node, int val)
		{ 
		    if (node == NULL) return new Node(val); 
		  
		    if (val < node->data) 
		        node->left  = _insert(node->left, val); 
		    else if (val > node->data) 
		        node->right = _insert(node->right, val);    
		  
		    return node; 
		} 
		
	public:
		BinarySearchTree(int val)
		{
			head = new Node(val);
		}
		
		void insertNode(int val)
		{
			head = _insert(head, val); 
		}
		
		void inOrder()
		{
			_inOrder(head);
		}
		
		
		void longestSequence()
		{
			
 			head->longestSequence( head );
 
		}
		
		~BinarySearchTree()
		{
			DestroyRecursive(head);
		}
		
		
};

void Display_Result ( Node* HEAD , int INTEGERS )
{
	
	if( INTEGERS == 0 )
	{
		COUNTER = GO_LEFT_SIDE( HEAD );
	}
	else
	{
		COUNTER = Go_RIGHT_SIDE( HEAD );
	}
	
	fstream output_in_file;
	output_in_file.open("OutPut_File.txt",ios::out);
	output_in_file << COUNTER << endl;
	
	if( HEAD == NULL)
	{
		cout<<"NO FILE EXIST\n\n\n"<<endl;
		return;
	}
	
	int COUNTER_1 = 0;
	
	if( INTEGERS == 0 )
	{
		
	  while( HEAD != NULL )
	  {
		 COUNTER_1++;
		  
		  if( HEAD->left != NULL )
		 	{		
			 	output_in_file << HEAD->data << ",";
		  		HEAD = HEAD -> left;
		    }
	
	    else
	    {
	   	   output_in_file << HEAD->data<<" ";
		   HEAD = HEAD->left;
	    }
	    
	  }
   
	   output_in_file.close();		
	}
	else
	{
		while( HEAD != NULL )
	  {
		COUNTER_1++;

		  if( HEAD->right != NULL )
		 	{		
		 	output_in_file << HEAD->data << ",";
		  	HEAD = HEAD->right;
	    	}

	    	else
	    	{
	   	  		output_in_file << HEAD->data << " ";
		  		HEAD = HEAD->right;
	    	}
	}
	
	output_in_file.close();	
		
	}
	cout << "OUTPUT STORED IN FILE...!!!";
}



#endif

