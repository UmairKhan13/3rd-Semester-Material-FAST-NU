#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *str, *ptr;
	
 ptr = (char *)calloc(1000, sizeof(char));
	
	printf("\nEnter string : ");
	gets(ptr);
	
	int  i , j , k , counter = 0;
	
	for ( i=0 ; *(ptr + i + 1 )!='\0' ; i++ )
	{
		if (*(ptr + i) == ' ' && *(ptr + i + 1) == ' ')
		{
			counter++;
			for ( j=i ; *(ptr + j )!='\0' ; j++ )
			{
				*(ptr + j) = *(ptr + j + 1);
			}
			i--;
		}
	}
	
//	int space = i;
//	for(int z = 0 ; z < counter ; z++ )
//	{
//		*(ptr + i) == ' ';
//		i--;
//	}
	
	puts("\n\nString after trimming : ");
	puts(ptr);
}
