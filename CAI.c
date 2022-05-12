#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int randomNumber( void );
int AnswerTheQuestion( unsigned int x , unsigned int y );


int main( void ){



	unsigned int number1, number2,result;
	int answer;
	
	srand( time( NULL ) );
	number1 = randomNumber();
	number2 = randomNumber();
	

	do{


		printf("How much is %u times %u? ( Press -1 to exit )\n", number1, number2 );
		result = AnswerTheQuestion( number1, number2 );

	    scanf("%d", &answer );

	   

	    while( answer != result && answer != -1 ){

		printf(".How much is %u times %u? ( Press -1 to exit )\n", number1, number2 );
		scanf("%u", &answer );
		}



		if( answer == result ){

	   		number1 = randomNumber();
			number2 = randomNumber();
	    }



	}while( answer == result && answer != -1 );

	

	
	

}


unsigned int randomNumber( void ){


	unsigned int n1;
	
	n1 = 1 + ( rand() % 9 );
	
	return n1;	
}



int AnswerTheQuestion( unsigned int x , unsigned int y ){

	return x * y;

}

