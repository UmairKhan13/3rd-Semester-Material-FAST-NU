#include <bits/stdc++.h>

using namespace std;

class TNode{ //Tree Node class
	private:
		int data;
		TNode *left, *right;
		friend class BT;
	public:
		TNode():data(0), left(0), right(0){}
		TNode(int x):data(x), left(0), right(0){}
};

class Node{ //Node class for Singley Linked List
	private:
		TNode *data;
		Node *next;
		friend class SLL;
		friend class Queue;
	public:
		Node():data(0), next(0){}
		Node(TNode *x):data(x), next(0){}
};

class SLL{ //Singley Linked List
	private:
		Node *head;
		int size;
		friend class Queue;
	public:
		SLL():head(0), size(0){};
		void insert(TNode* x){
			Node *temp = new Node(x);
			if(!head){
				head = temp;
			}
			else{
				Node *curr = head;
				while(curr -> next != 0){
					curr = curr -> next;
				}
				curr -> next = temp;
			}
		}
		void deletefront(){
			if(head == NULL){
			}
			else if(head -> next == NULL){
				head = 0;
			}
			else{
				head = head -> next;
			}
		}
		void display(){
			Node *curr = head;
			while(curr){
				if(curr->next != 0){
					cout<<" -> ";
					curr=curr->next;
				}
				else
					break;
			}
		}
};

class Queue{ // Queue class
	private:
		SLL *Q;
		int size;
		friend class BT;
	public:
		Queue():Q(0), size(0){}
		void enqueue(TNode* x){
			if(Q == NULL){
				Q = new SLL();
				Q -> insert(x);
			}
			else{
				Q -> insert(x);
			}
			size++;
		}
		bool isEmpty(){
			return !size;
		}
		TNode *dequeue(){
			if(Q -> head){
				TNode *temp = Q -> head -> data;
				Q -> deletefront();
				size--;
				return temp;
			}
		}
		void display(){
			Q -> display();
		}
};



class BT{ //Binary tree class
	private:
		TNode *root;
		int size;
		int suma;
		TNode *a;
	public:
		BT():root(0), size(0), suma(0){}
		void insert(int x){ // inserts data into binary tree with the help of queue
			if(!root){
				root = new TNode(x);
				size++;
				return;
			}
			Queue q;
			q.enqueue(root);
			while(!q.isEmpty()){
				TNode *temp = q.dequeue();
				if(temp->left){
					q.enqueue(temp -> left);
				}
				else{
					temp -> left = new TNode(x);
					break;
				}
				if(temp -> right){
					q.enqueue(temp -> right);
				}
				else{
					temp -> right = new TNode(x);
					break;
				}
			}
			size++;
		}
		void fill(){ // fills appropriate data from input file
			ifstream i;
			i.open("input2.txt");
			i >> size;
//			cout << size;
			i >> suma;
			int n;
			i >> n;
			while(i != NULL){
				insert(n);
				i >> n;
			}
		}
		void findsub(){ //function to find subtree
//			int arr[size];
//			int count = 0;
			Queue *queue  = new Queue(); //Queue used to transverse tree in breadth first order
			TNode* temp = root;
			if (temp == NULL) return; //if tree doesnot exist return
			queue->enqueue(temp); // putting root in queue
			while (!queue->isEmpty()){ //ifqueue is not empty transverse the tree
				temp = queue->dequeue();
				TNode *curr = temp;
				int sum = 0;
				int c = 0;
				bool found = false;
				while(sum <= suma && found == false){ //checking if valid bst is found or sum matches
					Queue *q = new Queue;
					q->enqueue(curr);
					while(!q->isEmpty()){
						curr = q -> dequeue();
//						cout << curr -> data << " ";
						sum += curr -> data;
						c++;
						if(sum == suma){
//							cout << temp -> data;
							a = temp;
							found = copyBST(c); //calls copy function which copies all elements of btree in another tree
						}
						if(found == true){
							break;
						}
						if(curr -> left != NULL)
							q->enqueue(curr -> left);
//						else break;
						if(curr -> right != NULL)
							q->enqueue(curr -> right);
//						else break;
					}
				}
				if(found == true){
					break;
				}
//				arr[count] = temp -> data;
//				cout << temp -> data << " ";
				if (temp->left != NULL)
				queue->enqueue(temp->left);
				if (temp->right != NULL)
					queue->enqueue(temp->right);
//				count++;
			}
			delete queue;
//			cout << endl;
//			for(int i = 0; i < size; i++){
//				cout << arr[i] << " ";
//			}
//			return arr;
		}
		bool copyBST(int c){ //copies B tree in another Btree
			int count = c;
			BT temp;
			Queue *queue  = new Queue(); 
			TNode* treeRoot = a;
			queue->enqueue(treeRoot); 
			while (count){ // transverse tree breadth first till count is 0 and copies elements in a new tree
			TNode * traverse = queue->dequeue();
			temp.insert(traverse -> data);
			if (traverse->left != NULL)
				queue->enqueue( traverse->left);
			if (traverse->right != NULL) 
            	queue->enqueue(traverse->right);
            	count--;
			}
			delete queue;
			TNode*curr = temp.root;
			bool done = isBST(curr);
			if(done == true){
				output(temp.root); //calls output function if tree is a BST
				return true;
			}
			else return false;
		}
		bool isBST(TNode *temp){ //Checks if tree is a BST
			if(temp == NULL) return 1;
			if(temp->left != NULL && temp->left->data > temp->data) return false;
			if(temp->right != NULL && temp->right->data < temp->data) return false;  
			if(!isBST(temp->left) || !isBST(temp->right)) return false;
			return true; 
		}
		void output(TNode*  treeRoot) {//output function to output a tree{  
			ofstream o;
			o.open("output.txt");
 			Queue *queue  = new Queue();

      		if (treeRoot == NULL) return; //if tree doesnt xist , no output
       		queue->enqueue(treeRoot); 
       		while (!queue->isEmpty()){ //outputs a valid BST with sum provided to the output file.
			   TNode * traverse = queue->dequeue();
			   o << traverse->data << endl;
			   if (traverse->left != NULL)
			   	    queue->enqueue( traverse->left); 
					if (traverse->right != NULL) 
				    queue->enqueue(traverse->right); 
           } 
		   delete queue;
       } 

		
		
//       void TreeBreadthFirst1(){
//			TreeBreadthFirst(root);
//       } 
//		void printPreorder(TNode* node, level) 
//		{
//   	 		if (node == NULL) return;
//   	 		if(level >= 1) cout << node->data << " ";
//   	 		else{
//    			printPreorder(node->left, level - 1);
//				printPreorder(node->right - 1);
//			}
//		}
};

int main(){
	BT t1;
	t1.fill();
	t1.findsub();
}
