#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int randomNumber( void );
int AnswerTheQuestion( unsigned int x , unsigned int y );
void message( int x, unsigned int y );
unsigned int randomMesasage( void );
void percent( int x, int y );



int main( void ){


	unsigned int number1, number2,result, ;
	int answer, trueAnswer, falseAnswer, counter;
	
	srand( time( NULL ) );
	number1 = randomNumber();
	number2 = randomNumber();
	counter = 0;

	
	while( counter <= 10 ){

		trueAnswer = 0;
		falseAnswer = 0;

	
		do{

			printf("How much is %u times %u?\n", number1, number2 );
			result = AnswerTheQuestion( number1, number2 );

	   		scanf("%d", &answer );
	    	message( answer, result );

	
	    	while( answer != result && counter < 10 ){

				printf("How much is %u times %u?\n", number1, number2 );
				scanf("%u", &answer );
				message( answer, result );
				++falseAnswer;
				++counter;
			}


			if( answer == result && counter < 10 ){

	   			number1 = randomNumber();
				number2 = randomNumber();

				++trueAnswer;
				++counter;
	    	}


		}while( answer == result  && counter < 10);


		percent( trueAnswer, falseAnswer );
		puts("");
		printf("New User : \n");
		counter = 0;
	}
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

		switch( randomMesasage() ){

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




unsigned int randomMesasage( void ){

	unsigned int n;

	n = 1 + ( rand() % 4 );

	return n;
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
	puts("************************");
}


