#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<queue>

struct Node {
	
		int value;
		Node* left;
		Node* right;
	
	public:
		
		Node()
		{
			value = -1;
			left = NULL;
			right = NULL;
		}
		
		Node(int val)
		{
			value = val;
			left = NULL;
			right = NULL;
		}
	
};

class BinaryTree{
	
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
			cout<<n->value<<", ";
			_inOrder(n->right);
		}
		
	public:
		BinaryTree(int val)
		{
			head = new Node(val);
		}
		
		void insertNode(int val)
		{
			queue<Node*> q; 
		    q.push(head);
		    Node* temp;
		  
		    while (!q.empty()) { 
		        temp = q.front(); 
		        q.pop(); 
		  
		        if (!temp->left) { 
		            temp->left = new Node(val); 
		            break; 
		        } else
		            q.push(temp->left); 
		  
		        if (!temp->right) { 
		            temp->right = new Node(val); 
		            break; 
		        } else
		            q.push(temp->right); 
		    } 
		}
	
		void inOrder()
		{
			_inOrder(head);
		}
		
		~BinaryTree()
		{
			DestroyRecursive(head);
		}
		
		
};

#endif

	
//		void setLeft(int val)
//		{
//			this.left= new Node(val);
//		}
//		
//		void setRight(int val)
//		{
//			this.right = new Node(val);
//		}
//		
//		void setValue(int val)
//		{
//			value = val;
//		}
//		
//		int getValue()
//		{
//			return this.value;
//		}
//		
//		bool hasLeft()
//		{
//			if(this.left == NULL)
//				return false;
//			else
//				return true;	
//		}
//		
//		bool hasRight(){
//			if(this.right == NULL)
//				return false;
//			else
//				return true;	
//		}
//		
//		bool isSet()
//		{
//			if(val == -1)
//				return false;
//				
//			else return true;	
//		}

