#include<iostream>
#include<fstream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

// Node structure containing power and coefficient of variable 
struct Node 
{ 
    int coeff; 
    int pow; 
    struct Node *next; 
}; 
              
// Function to create new node 
void create_node(int x, int y, struct Node **temp) 
{ 
    struct Node *r, *z; 
    z = *temp; 
    if(z == NULL) 
    { 
        r =(struct Node*)malloc(sizeof(struct Node)); 
        r->coeff = x; 
        r->pow = y; 
        *temp = r; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coeff = x; 
        r->pow = y; 
        r->next = (struct Node*)malloc(sizeof(struct Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 
  
// Function Adding two polynomial numbers 
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
while(poly1->next && poly2->next) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next = (struct Node *)malloc(sizeof(struct Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
} 
 
// write output in file 
void output_file(struct Node *node) 
{ 
	ofstream out;
	out.open("output1.1.txt");
while(node->next != NULL) 
    {
	if(node->coeff != 0) 
    {
	out << node->coeff << "X^"  << node->pow; 
	}
	node = node->next; 
    if(node->next != NULL && node->coeff > 0 ) 
        out<<"+"; 
    }
	out << "=0"; 
	out.close();
} 

// write output in file 
void output_file_diff(struct Node *node) 
{ 
	ofstream out;
	out.open("output1.2.txt");
while(node->next != NULL) 
    {
	if(node->coeff != 0) 
    {
	out << node->coeff << "X^"  << node->pow; 
	}
	node = node->next; 
    if(node->next != NULL && node->coeff > 0 ) 
        out<<"+"; 
    }
	out << "=0"; 
	out.close();
} 
 
 
 
// Display Linked list 
void show(struct Node *node) 
{ 
while(node->next != NULL) 
    {
	if(node->coeff != 0) 
    {
	printf("%dX^%d", node->coeff, node->pow); 
	}
	node = node->next; 
    if(node->next != NULL && node->coeff > 0 ) 
        printf("+"); 
    }
	cout<<"=0"; 
} 

 
 
void differentiate(struct Node *node)
{
	struct Node *diff = NULL;
	int coef,pow;
	while(node->next != NULL)
	{
		coef = node->coeff * node->pow;
		pow = node->pow - 1;
		create_node(coef,pow,&diff);
		node = node->next;	
	}
	cout << endl << "Differentiated Polynomnial: ";
	show(diff);
	output_file_diff(diff);
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
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
	char array[100],ch;
	int count=0,coef[100],pow[100],neg;
	ifstream in;
    in.open("input1.txt",ios::in);
    in.getline(array,100);
    
    for(int j=0,k=0,i = 0 ; i < strlen(array) ; i++)
    {
    	if(array[i-1] != 61)
    	{
    	if( array[i] > 47 && array[i] < 58 )
    	{
    		if( array[i-1] != 94 )
    		{
			ch = array[i];
			neg = NUMBER_CONVERTER(ch);
			if(array[i-1]== 45)
    		{
    			neg = 0 - neg;
			}
			coef[j] = neg;
    		j++;
    		count++;
    	    
			}
    	    else
    	    {
    	    ch = array[i];
    		pow[k] = NUMBER_CONVERTER(ch);
			k++;
			}
		}
		}
	}

    // Create first list 
    for(int l = 0; l < count ; l++)
	{
	create_node(coef[l],pow[l],&poly1); 
	}
	  
    printf("1st LIST: ");  
    show(poly1);   
    
    memset(array,0,100);
    memset(coef,0,100);
    memset(pow,0,100);
    
    
	in.getline(array,100);
    
    for(int j=0,k=0,i = 0 ; i < strlen(array) ; i++)
    {
    	if(array[i-1] != 61)
    	{
    	if( array[i] > 47 && array[i] < 58 )
    	{
    		if( array[i-1] != 94 )
    		{
			ch = array[i];
			neg = NUMBER_CONVERTER(ch);
			if(array[i-1]== 45)
    		{
    			neg = 0 - neg;
			}
			coef[j] = neg;
    		j++;
    		count++;
    	    
			}
    	    else
    	    {
    	    ch = array[i];
    		pow[k] = NUMBER_CONVERTER(ch);
			k++;
			}
		}
		}
	}
 
    // Create second list  
    for(int l = 0; l < count ; l++)
	{
	create_node(coef[l],pow[l],&poly2); 
	}  
	
    printf("\n2nd LIST: "); 
    show(poly2);   
      
    poly = (struct Node *)malloc(sizeof(struct Node)); 
      
    // Function add two polynomial numbers 
    polyadd(poly1, poly2, poly); 
      
    // Display resultant List 
    printf("\nAdded polynomial: "); 
    show(poly); 
	in.close();
	output_file(poly); 
	differentiate(poly);
	
	
	return 0; 
}
    

