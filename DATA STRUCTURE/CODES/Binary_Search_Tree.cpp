W#include<iostream>
using namespace std;

class BT_NODE
{
	private:
		
		int Data;
		BT_NODE* LEFT_CHILD;
		BT_NODE* RIGHT_CHILD;
		 
	public:
		
		BT_NODE( int Data )
		{
			this->Data = Data;
			LEFT_CHILD = RIGHT_CHILD = NULL;
		}
		
		void Insert( int Data )
		{
			if(this->Data == Data )
			{
				return;
			}
			
			if( Data < this->Data )
			{
				if( LEFT_CHILD == NULL )
				LEFT_CHILD = new BT_NODE( Data );
				
				else
				LEFT_CHILD->Insert(Data);
			}
			else
			{
				
				if( RIGHT_CHILD == NULL )
				RIGHT_CHILD = new BT_NODE( Data );
				
				else
				RIGHT_CHILD->Insert(Data);
				
			}
		}
	
	void TRANSVERSEinORDER()
	{
		if(LEFT_CHILD != NULL)
		{
			LEFT_CHILD->TRANSVERSEinORDER();
		}
		
		cout << Data << endl;
		
		if(RIGHT_CHILD != NULL)
		{
			RIGHT_CHILD->TRANSVERSEinORDER();
		}
		
	}
	
				
};

class BST
{
	private:
			BT_NODE *Root;
	public:
			
			BST()
			{
				Root = NULL;
			}
		
			void insert( int Data )
			{
				if( Root == NULL )
				{
					Root = new BT_NODE( Data );
				}
				
				else
				{
					Root->Insert( Data );	
				}
				
			}
			
		void TRANSVERSEinORDER()
		{
			Root->TRANSVERSEinORDER();
		}	
	
};

int main()
{
	BST Tree;
	Tree.insert(22);
	Tree.insert(21);
	Tree.insert(23);
	Tree.insert(20);
	Tree.insert(24);
	Tree.insert(25);
	Tree.TRANSVERSEinORDER();
}
