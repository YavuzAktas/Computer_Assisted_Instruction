#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int randomNumber( unsigned int x );
int AnswerTheQuestion( unsigned int x , unsigned int y, unsigned int z, unsigned int t ); //
void message( int x, unsigned int y );
void percent( int x, int y );
int arithmeticProblem( unsigned int x, unsigned int y );
unsigned int randomMessage( void );


int main( void ){

	unsigned int number1, number2, result, difficulty, arithmetic, backupNumber;
	int answer, trueAnswer, falseAnswer, counter;
	char math;
	unsigned int n;
	
	srand( time( NULL ) );

	do{

		printf("Specify the arithmetic operation by selecting one of the numbers\n( 1- Addition problems   2- Subtraction problem   3- Multiplication problems   4- Random mixture of all these types ) : ");
		scanf("%u", &arithmetic );

		printf("Enter the difficulty level ( 1, 2 or 3 ): ");
		scanf("%u", &difficulty );

		number1 = randomNumber( difficulty );
		number2 = randomNumber( difficulty );

		if( number1 < number2 ){

			backupNumber = number1;
			number1 = number2;
			number2 = backupNumber;
		}

	}while( difficulty <= 0 && difficulty >= 4 && arithmetic < 1 && arithmetic > 4 );
	
	counter = 0;


	while( counter <= 10 && arithmetic >= 1 && arithmetic <= 4 ){

		trueAnswer = 0;
		falseAnswer = 0;

		do{

			n = 1 + ( rand() % 4 );
			math =arithmeticProblem( arithmetic, n );
			printf("How much is %u %c %u?\n", number1, math, number2 );
			result = AnswerTheQuestion( number1, number2, arithmetic, n );

	   		scanf("%d", &answer );
	    	message( answer, result );

	
	    	while( answer != result && counter < 10 ){

				printf("How much is %u %c %u?\n", number1, math, number2 );
				scanf("%u", &answer );
				message( answer, result );
				++falseAnswer;
				++counter;
			}

			if( answer == result && counter < 10 ){

	   			number1 = randomNumber( difficulty );
				number2 = randomNumber( difficulty );

				if( number1 < number2 ){

					backupNumber = number1;
					number1 = number2;
					number2 = backupNumber;
				}

				++trueAnswer;
				++counter;
	    	}

		}while( answer == result  && counter < 10);

		percent( trueAnswer, falseAnswer );	
		puts("");
		printf("New User : \n");
		counter = 0;

		do{

			printf("Specify the arithmetic operation by selectingone of the numbers\n( 1- Addition problems   2- Subtraction problem   3- Multiplication problems   4- Random mixture of all these types ) : ");
			scanf("%u", &arithmetic );			
		
		}while( arithmetic > 4 && arithmetic < 1 );


		printf("Enter the difficulty level ( 1, 2 or 3 ): ");
		scanf("%u", &difficulty );
	}
}



unsigned int randomNumber( unsigned int x ){

	unsigned int n;
	
	switch( x ){

		case 1 :
			n = 1 + ( rand() % 9 );
			break;

		case 2 :
			n = 1 + ( rand() % 40 );
			break; 

		case 3 :
			n = 20 + ( rand() % 99 );
			break;

		default:
			puts("You entered the wrong difficulty level! ");
	}	
	
	return n;	
}


void message( int x, unsigned int y ){
	
	if( x == y ){

		switch( randomMessage() ){

			case 1:
				puts("Very good!");
				puts("----------------------");
				break;

			case 2:
				puts("Excellent!");
				puts("----------------------");
				break;

			case 3:
				puts("Nice work!");
				puts("----------------------");
				break;

			default:
				puts("Keep up the good work!");
				puts("----------------------");
				break;
		}
	}

	else if( x != y && x != -1 ){

		switch( randomMessage() ){

			case 1:
				puts("No. Please try again.");
				puts("----------------------");
				break;

			case 2:
				puts("Wrong. Try once more.");
				puts("----------------------");
				break;

			case 3:
				puts("Don't give up!");
				puts("----------------------");
				break;

			default:
				puts("No. Keep trying.");
				puts("----------------------");
				break;
		}
	}

	else{

		puts("See you ;)");
	}

	puts(" ");
}


void percent( int x, int y ){

	int percentOfCorrect;
	percentOfCorrect = ( x * 100 ) / ( x + y );

	printf("Percentage of correct questions : %%%d\n", percentOfCorrect );

	if( percentOfCorrect < 75 ){

		puts("Please ask your teacher for extra help.");
	}

	else if( percentOfCorrect >= 75 ){

		puts("Congratulations, you are ready to go to the next level!");
	}
	puts("*******************************************************");
}


int arithmeticProblem( unsigned int x , unsigned int y ){

	if( x == 1 ){

		return 43;
	}

	else if( x == 2 ){

		return 45;
	}

	else if( x == 3 ){

		return 42;
	}

	else {

		switch( y ){

			case 1: 
				return 43;
				break;

			case 2: 
				return 45;
				break;

			case 3:
				return 42;
				break;

			default:
				return 47;
		}
	}
}

int AnswerTheQuestion( unsigned int x , unsigned int y , unsigned int z, unsigned int t ){

	unsigned int backupNumber;
	backupNumber = 1;

	if( z == 1 ){

		return x + y;
	}

	
	else if( z == 2 ){

		return x - y;
	}

	
	else if( z == 3 ){

		return x * y;
	}

	
	else if( z == 4 ){

		switch( t ){

			case 1: 
				return x + y;
				break;                         

			case 2: 
				return x - y;
				break;

			case 3:
				return x * y;
				break;

			default:
				return x / y;
				break;
		}
	}
}

unsigned int randomMessage( void ){

	unsigned int x;
	x = 1 + ( rand() % 4 );

	return x;
}