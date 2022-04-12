/****************************************************************************
* Author: k181292 Muhammad Umair Khan                                       *
* Purpose: WORD PUZZLE                                                      *
* Dated: September 28, 2019                                                 *
* Version: 1.0                                                              *                                                 
* Last modified: September 30, 2019                                         *
*****************************************************************************/

	
	
	// HEADER FILES
	
	#include <iostream>
    #include <fstream>
    #include <cstring>
    
    using namespace std;
    
    // class declaration 
    class WORD_PUZZLE
    {
    
	public:
	

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
	
	int *backward_locator(char str1[][100], char str2[][100], int n, int size, int p)
	{
	int static array[2],t,counter=0,a,b;
	array[0]=array[1]=-1;
	for(int i=0; i<n; i++)
	{
	for(int j=strlen(str1[i])-1; j>=0; j--)
	{
	if(str1[i][j]==str2[p][0])
	{
	t=j-1;	
	for(int k=1; k<strlen(str2[p]); k++)
	{
	if(str1[i][t--]==str2[p][k])
	{
	a=i;
	b=j;	
	++counter;	
	}
	}	
	}
	if(counter+1==strlen(str2[p]))
	{
	array[0]=a;
	array[1]=b;	
	}
	counter=0;
    }
	}	
	return array;
	}
    
	int *forward_locator(char str1[][100], char str2[][100], int n, int size, int p)
	{
	int static array[2],t,counter=0,a,b;
	array[0]=array[1]=-1;
	for(int i=0; i<n; i++)
	{
	for(int j=0; j<strlen(str1[i]); j++)
	{
	if(str1[i][j]==str2[p][0])
	{
	t=j+1;	
	for(int k=1; k<strlen(str2[p]); k++)
	{
	if(str1[i][t++]==str2[p][k])
	{
	a=i;
	b=j;	
	++counter;	
	}
	}	
	}
	if(counter+1==strlen(str2[p]))
	{
	array[0]=a;
	array[1]=b;	
	}
	counter=0;
	}
	}	
	return array;
	}
    
    int *downward_locator(char str1[][100], char str2[][100], int n, int m, int size, int p)
	{
	int static array[2],t,counter=0,a,b;
	array[0]=array[1]=-1;
	for(int i=0; i<m; i++)
	{
	for(int j=0; j<n; j++)
	{
	if(str1[j][i]==str2[p][0])
	{
	t=j+1;	
	for(int k=1; k<strlen(str2[p]); k++)
	{
	if(str1[t++][i]==str2[p][k])
	{
	a=j;
	b=i;	
	++counter;	
	}
	}	
	}
	if(counter+1==strlen(str2[p]))
	{
	array[0]=a;
	array[1]=b;	
	}
	counter=0;
	}
	}	
	return array;
	}
    
    int *upward_locator(char str1[][100], char str2[][100], int n, int m, int size, int p)
	{
	int static array[2],t,counter=0,a,b;
	array[0]=array[1]=-1;
	for(int i=0; i<m; i++)
	{
	for(int j=n-1; j>=0; j--)
	{
	if(str1[j][i]==str2[p][0])
	{
	t=j-1;	
	for(int k=1; k<strlen(str2[p]); k++)
	{
	if(str1[t--][i]==str2[p][k])
	{
	a=j;
	b=i;	
	++counter;	
	}
	}	
	}
	if(counter+1==strlen(str2[p]))
	{
	array[0]=a;
	array[1]=b;	
	}
	counter=0;
	}
	}	
	return array;
	}
  	
    void INPUT_OUTPUT_FILE()
    {
  	int i=0,j=0,c=0,n,m,z,x,size,k=0,l=0;
    char str[100],ch,str1[100][100],str2[100][100];
    bool bol=true;
    ifstream in;
    in.open("Q_1_Input_File.txt",ios::in);
	
    in.get(ch);		
	n=NUMBER_CONVERTER(ch);	
	
    in.get(ch);		
	in.get(ch);		
	m=NUMBER_CONVERTER(ch);
	
    in.getline(str,100);
	cout<<str;
	
    while(!in.eof())
	{
	
    in.getline(str,100);
	
    if(!(strcmp(str,"10")))
	{
	in.getline(str,100);	
	size=10;
	bol=false;	
	} 	
	
    else if(NUMBER_CONVERTER(str[0])>-1 && NUMBER_CONVERTER(str[0])<10)
	{
	if(NUMBER_CONVERTER(str[1])>-1)
	{
	cout<<"Invalid Value! WORD_PUZZLE Elements Should Be Less Than 10.";
	exit(-1);	
	}	
	size=NUMBER_CONVERTER(str[0]);	
	bol=false;	
	in.getline(str,100);
	}
	
    if(bol)	
	strcpy(str1[i++],str);
	
    else
	strcpy(str2[j++],str);
	}
	
    in.close();
	
    ofstream out;
	out.open("Q_1_Output_File.txt",ios::out);
	
    int *ptr1,*ptr2,*ptr3,*ptr4;
	for(int i=0; i<size; i++)
	{	
	ptr1=forward_locator(str1,str2,n,size,i);	
	ptr2=backward_locator(str1,str2,n,size,i);	
	ptr3=downward_locator(str1,str2,n,m,size,i);
	ptr4=upward_locator(str1,str2,n,m,size,i);
	
    if(*ptr1!=-1)
	{
	cout<<*ptr1<<*(ptr1+1);
	out<<*ptr1<<*(ptr1+1)<<endl;	
	}
	
    if(*ptr2!=-1)
	{
	cout<<*ptr2<<*(ptr2+1);
	out<<*ptr2<<*(ptr2+1)<<endl;		
	}
	
    if(*ptr3!=-1)
	{
	cout<<*ptr3<<*(ptr3+1);
	out<<*ptr3<<*(ptr1+3)<<endl;			
	}
	
    if(*ptr4!=-1)
	{
	cout<<*ptr4<<*(ptr4+1);
	out<<*ptr4<<*(ptr4+1)<<endl;				
	}
	
    if(*ptr1==-1 && *ptr2==-1 && *ptr3==-1 && *ptr4==-1)
	{
	cout<<'n';	
	out<<'n'<<endl;					
	}
	cout<<endl;
    }
	out.close();
	}
  	
	};
	
	
	// driver 
	int main()
    {
    WORD_PUZZLE OBJECT;
	OBJECT.INPUT_OUTPUT_FILE();	
    }
