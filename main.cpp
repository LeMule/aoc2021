#include <Declarations.h>

int main()
{

	//Scoped so we drop each solution obj when we're done.
	{
		Solution1 sol1("Inputs/Dec1/puzzle.input");
	}
	{
		Solution2 sol2("Inputs/Dec1/puzzle.input");
	}
	return 0;
}
