#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

int longest[100],s=0;
char all[100][100];

void printlongest()
{
	int high = 0;
	
	for(int l =0 ; l < s ; l ++)
	{
		if(longest[0] < longest[l])
        {
		   longest[0] = longest[l];
           high = l;
       }
	}
	
	ofstream out;
	out.open("output1.txt");
	
	for(int j = 0 ; j < strlen(all[high]) ; j ++)
	{
	out << all[high][j];
	cout << all[high][j];	
	}
	out.close();

}

void palindrome( char a[] , int lenght )
{
	
	
	int i;
    int flag = 0;
    for(i=0;i < lenght ;i++)
	{
         if(a[i] != a[lenght-i-1]) 
		 {
            flag = 1;
            break;
         }
      }
      
      if ( flag == 0 ) 
	  {
		longest[s] = lenght;
	
	for(int b = 0 ; b < lenght ; b ++)
	{
		all[s][b] = a[b];
	}
	s++;
	  
	  }
    
}
 
struct Node 
{ 
    int coeff; 
    struct Node *next; 
}; 
              
// Function to create new node 
void create_node(int x,struct Node **temp) 
{ 
    struct Node *r, *z; 
    z = *temp; 
    if(z == NULL) 
    { 
        r =(struct Node*)malloc(sizeof(struct Node)); 
        r->coeff = x;  
        *temp = r; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coeff = x;  
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 

  
// Display Linked list 
void show(struct Node *node) 
{ 
while(node->next != NULL) 
    {
	if(node->coeff != 0) 
    {
	printf("%d ", node->coeff); 
	}
	node = node->next;  
} 

}
  
void longestPalindrome(struct Node *node) 
{ 
	ifstream in;
    in.open("input1.txt",ios::in);
    char string[100],ch;
    int n=0;
    in >> ch;
    ch = '\0';
    
    while(!in.eof())
    {
    	in >> ch;
    	if( ch != 32)
       {
		string[n] = ch;
    	cout << string[n] ;
		n++;
       }
       ch = '\0';
	}
	cout << endl;
	in.close();
      
	int size = strlen(string);
    
    char string2[100];
      
	int i=0,k=1;
   
   printf("ALL POSSIBLE PALINDROMES ARE :\n");
    
   for( int y = 0 ; i != size - 2 ; y ++)
   {
      
	while(string[i]!=string[k])
    {
		  if(k == size -1 )
		  {
		  break;
	      }
		  k++;
	}
	  
	for(int z =i , l = 0 ; z <= k  ; z++)
	{
	  	string2[l] = string[z];
	  	l++;
	}
	
	int d = strlen(string2);
    palindrome(string2,d); 
	
	 
	if( k == size -1)  
	{
	
	for(int o = 0 ; o < d ; o ++)
	{
		string2[o] = '\0' ;	
	}  
	i++;
	k = i + 1;
    }
    else
    {
    	k++;
	}
	
    }
		
}

int NUMBER_CONVERTER(char ch) // member function to convert char into int
    {
    switch(ch)
	{
	case '0' :
	return 0;	
	case '1' :
	return 1;
	case '2' :
	return 2;
	case '3' :
	return 3;
	case '4' :
	return 4;
	case '5' :
	return 5;
	case '6' :
	return 6;
	case '7' :
	return 7;
	case '8' :
	return 8;
	case '9' :
	return 9;	
	return -1;	
	}	
	}
	

int main()
{
	struct Node *N;
	int count,num,coef;
	ifstream in;
    in.open("sub.txt",ios::in);
    
    in >> num;
    
    for(int i = 0 ; i < num ; i ++)
  	{
  		in >> coef;
  		create_node(coef,&N);
	}
	in.close();
	longestPalindrome(N);
	printlongest();   
    
     
	
	
	
	return 0; 
	
	  
	    
}
    

