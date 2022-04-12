#include "K181292_A3P1.h"

int main()
{
	
	ifstream in_File("InPut_File.txt");
	
	int integer;
	in_File >> integer;
	BinarySearchTree* bt = new BinarySearchTree( integer );
	
	while( !in_File.eof() )
	{
		in_File>>integer;
		bt->insertNode( integer );
	}

	bt->longestSequence();
	Display_Result( RESULT , TESTING );
	
	delete bt;
	
	return 0;

}
