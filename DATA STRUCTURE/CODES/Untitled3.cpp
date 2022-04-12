#include<iostream>
using namespace std;
#define max 5

template<class T>
class stack
{
	private:
		T *stk;
		int top;
	
	public:
		int get_top()
		{
			return top;
		}
		stack();
		stack(unsigned int size);
		bool is_empty();
		bool is_full();
		int push(T d);
		T pop();
		
		void multipush(stack &rhs);
		stack& multipop(int s);
		
		void displayItems();
	
};


int main()
{
	stack<int> stk;
    int choice, n;
    int temp;
     
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
         
        cout<<"Enter your choice: ";
        cin>>choice;
         
       switch(choice){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp = stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<n<<" inserted."<<endl;
            break;
                 
            case 2:
                temp = stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped)."<<endl;
            break;
             
            case 3:
                stk.displayItems();
                break;
             
            default:
                cout<<"An Invalid choice."<<endl;
 }   
    }while(choice!=0);
 
     
    return 0;
}

template <class T>
void stack<T>::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    
	if (!is_empty())
    {
	for(i = top; i>=0; i--)
        cout<<stk[i]<<" ";
    cout<<endl;
     }
    else
    cout << "Empty";
}

template <class T>
stack<T>::stack()
{
	stk = new T();
	top = -1;
}

template <class T>
stack<T>::stack(unsigned int size)
{
	stk = new T(size);
	top = -1;
}

template <class T>
bool stack<T>::is_empty()
{
	 if(top == -1)
	 {
	 	return true;
	 }
	 
	 else
	 return false;
}

template <class T>
bool stack<T>::is_full()
{
	return ( top == max-1);
}

template <class T>
int stack<T>::push(T d)
{
	if(!is_full())
	{
		top++;
		stk[top] = d;
		return 1;
	}
	else 
	{
		return 0;
	}
}

template <class T>
T stack<T>::pop()
{
	if(!is_empty())
	{
		T temp;
		temp = stk[top];
		top--;
		return temp;
	}
	else
	{
		return 0;
	}
}
