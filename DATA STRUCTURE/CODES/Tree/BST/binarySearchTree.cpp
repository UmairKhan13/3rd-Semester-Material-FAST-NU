#include<iostream>
using namespace std;
class TreeNode;

class TreeNode{

    public:
    int data;
    TreeNode *leftNode;
    TreeNode *rightNode;

    public:

    TreeNode(int data)
    {
        this->data = data;
        leftNode = rightNode =   NULL;
    }
    
    void insert(int value)
    {
        if(data == value)
        return;

        if(value < data)
        {
            if(leftNode == NULL)
            leftNode = new TreeNode(value) ;
            else
            leftNode->insert(value);                
            
        } else if(value > data)
        {
            if(rightNode == NULL)
            rightNode = new TreeNode(value) ;
            else
            rightNode->insert(value);                
            
        }
    }

    void traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<data<<" ";

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }
  
};

class Tree{

    private:
    TreeNode *root;

    public:
    Tree()
    {
        root = NULL;
    }

    void insert(int data)
    {
        if(root == NULL)
        root = new TreeNode(data);
        else
        root->insert(data);
    }
    void traverseInOrder()
    {
        root->traverseInOrder();
    }
};
int main()
{

    Tree *tree = new Tree();
//5,4,8,6,7,10,2,18,14,15
    tree->insert(5);
    tree->insert(4);
    tree->insert(8);
    tree->insert(6);
    tree->insert(7);
    tree->insert(10);
    tree->insert(2);
    tree->insert(18);
    tree->insert(14);
    tree->insert(15);

    tree->traverseInOrder();
}
