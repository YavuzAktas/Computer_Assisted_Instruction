#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int randomNumber( void );



int main( void ){


	srand( time( NULL ) );

	unsigned int number1, number2;


	number1 = randomNumber();
	number2 = randomNumber();

	printf("How much is %u times %u ?\n", number1, number2 );


}


unsigned int randomNumber( void ){


	unsigned int n1;

	n1 = 1 + ( rand() % 9 );
	
	return n1;	
} 

