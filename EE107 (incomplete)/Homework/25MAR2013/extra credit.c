/* Talen Phillips
 * EE107-01
 * 25MAR2013
 * "Summation Calculator"
 */
#include <stdio.h> //header file with definitions for basic functions
#include <conio.h>
int main (void) //function information: [output type] [name] [input]
//This is analogous to "integer f(x)". Here there's no output,
//since the program ends when the function does.
//All "output" is done within the function itself.
{
	//variable type definitions: int is integer
	//double is a very large variable type (can store larger numbers)
	int x; //user input with no initial value
	int n = 1; //starting n at 1 for this program
	int a = -1; //a is (-1)^n
	double result = 1; //sum at each increment
	double fact = 1; //n! variable (starts at 1! = 1)
	double exp = 3; //3^n variable (starts at 3^1 = 3)
	double sum; //this is our running total (displayed after exiting loop)

	printf("Enter a number: "); //display this to the screen
	scanf("%d",&x); //await user input. store in variable x
	
	//"while" starts a loop which executes the commands inside the curly
	//brackets as long as the statement in parentheses remains true
	//(it rechecks the statement after each iteration)
	while(n<=x)
		{
			result = (a/(exp*fact)); //calculate current sum
			printf("a%-2i =%17.14f\n",n,result); //display current sum
			sum = sum + result; //add current sum to total sum
			fact = fact * n; //increment factorial
			exp = exp * 3; //increment exponent
			n=n+1; //increment n
			a=-a; //"oscillate" a
		}
	printf("\nS%-2i =%17.14f\n",n-1,sum); //(lots of formatting)
	printf("\n\nPress any key to exit...");
	getch();
	return 0; //end program
}

