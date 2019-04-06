// Problem 4 -  Logic Test ( Knowledge Base: Boolean Logic )

// This function gives the output below, given inputs A, B, C, D

/*
	Truth table of a function

		|	A	B	C	D	|	f(A, B, C, D)
	-----------------------------------------
	0	|	0	0	0	0	|	0
	1	|	0	0	0	1	|	0
	2	|	0	0	1	0	|	0
	3	|	0	0	1	1	|	0
	4	|	0	1	0	0	|	0
	5	|	0	1	0	1	|	0
	6	|	0	1	1	0	|	1
	7	|	0	1	1	1	|	0
	8	|	1	0	0	0	|	1
	9	|	1	0	0	1	|	1
	10	|	1	0	1	0	|	1
	11	|	1	0	1	1	|	1
	12	|	1	1	0	0	|	1
	13	|	1	1	0	1	|	1
	14	|	1	1	1	0	|	1
	15	|	1	1	1	1	|	0

*/

bool LogicTest( bool A, bool B, bool C, bool D )
{
	return ((A||B)&&(A||C)&&(!B||!C||!D));
}
