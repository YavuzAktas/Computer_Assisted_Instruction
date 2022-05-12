#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int randomNumber( void );
int AnswerTheQuestion( unsigned int x , unsigned int y );
void message( int x, unsigned int y );
unsigned int randomMesasage( void );



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
	    message( answer, result );

	
	    while( answer != result && answer != -1 ){

		printf("How much is %u times %u? ( Press -1 to exit )\n", number1, number2 );
		scanf("%u", &answer );
		message( answer, result );
		}


		if( answer == result ){

	   		number1 = randomNumber();
			number2 = randomNumber();
	    }

	}while( answer == result && answer != -1 );	


}



unsigned int randomNumber( void ){


	unsigned int n;
	
	n = 1 + ( rand() % 9 );
	
	return n;	
}



int AnswerTheQuestion( unsigned int x , unsigned int y ){

	return x * y;
}



void message( int x, unsigned int y ){

	
	if( x == y ){

		switch( randomMesasage() ){

			case 1:
				puts("Very good!");
				break;

			case 2:
				puts("Excellent!");
				break;

			case 3:
				puts("Nice work!");
				break;

			default:
				puts("Keep up the good work!");
		}

	}


	else if( x != y && x != -1 ){

		switch( randomMesasage() ){

			case 1:
				puts("No. Please try again.");
				break;

			case 2:
				puts("Wrong. Try once more.");
				break;

			case 3:
				puts("Don't give up!");
				break;

			default:
				puts("No. Keep trying.");
		}

	}


	else{

		puts("See you ;)");
	}


	puts(" ");
}



unsigned int randomMesasage( void ){

	unsigned int n;

	n = 1 + ( rand() % 4 );

	return n;
}


