/*
                        -- Course Name : Data Structure --
                        -- Course No   : SWE127, SWE128 --
                        -- Problem No  : 007            --
        -----------------------------------------------------------------
           Problem Statement :
        -----------------------------------------------------------------
        | Evaluate a Postfix Expression                                 |
        -----------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int Stack[100000];
int TOP = -1;
int maxStk = 100000;

int push( int item )
{
	if( TOP == maxStk - 1 ) {
		printf("Overflow\n");
		return 0;
	}
	TOP++;
	Stack[TOP] = item;
	return 1;
}

int pop()
{
	if( TOP == -1 ) {
		printf("Underflow\n");
		return 0;
	}
	TOP--;
	return 1;
}


int stoi ( char s[] ) {	// string to integer
	int len = strlen( s );
	int n = 0;
	int mul = 1;
	for( int i = len - 1; i >= 0; i-- ) {
		n += ( s[i] - '0' ) * mul;
		mul *= 10;
	}
	return n;
}

int evaluatePostfixExpression( char expression[10][10] )
{
	int i = 0, A, B, result;
	printf("Steps: \n");
	while( strcmp( expression[i], ")" ) != 0 ) {
		char sign = expression[i][0];
		if( sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^' ) {
			A = Stack[TOP]; pop();
			B = Stack[TOP]; pop();
			if( expression[i][0] == '+' ) result = B + A;
			else if( expression[i][0] == '-' ) result = B - A;
			else if( expression[i][0] == '*' ) result = B * A;
			else if( expression[i][0] == '/' ) result = B / A;
			else if( expression[i][0] == '^' ) {
				result = 1;
				for( int i = 0; i < A; i++ ) result *= B;
			}
			push( result );
			printf("%d %s %d = %d\n", B, expression[i], A, result);
		}
		else {
			int x = stoi( expression[i] );
			push( x );
		}
		i++;
	}
	int res = Stack[TOP];
	pop();
	printf("\n");
	return res;
}

int main()
{
	char expression[10][10] = { "5", "6", "2", "+", "*", "12", "4", "/", "-", ")" };

	printf( "Result : %d\n", evaluatePostfixExpression(expression) );
}