/**********************************************************************
48430 Embedded C - Assignment 1
Name: Christine Vinaviles
Student ID: 11986282
Date of submission: 22 April 2016
A brief statement on what you could achieve (less than 50 words):


A brief statement on what you could NOT achieve (less than 50 words):


**********************************************************************/

/**********************************************************************
List of header files - do NOT use any other header files.
**********************************************************************/
#include <stdio.h>

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
char isodd(int); /* Check if an integer is odd */
char istriangle(int); /* Check if an integer is a triangular number */
void printtriangle(int); /* Print a triangle corresponding to an int */
int number(int); /* This is where the user inputted number will be stored */

/**********************************************************************
Main
**********************************************************************/
int main(void){
	printf("Enter a number between 0 and 200>");
	scanf("%lf", &number);
	char istriangle(number);
	printf("Printing even triangular numbers below %lf \n", number);
	if (isodd(n) == 0){
		printf("Printing numbers below %lf:\n", number);
		for ( int i = 0; n > i; i++ ){
			
		}
	}
    return 0;
}


/**********************************************************************
Check if an integer n is odd.
return 1 - if odd
return 0 - otherwise
**********************************************************************/
char isodd(int n){
    if ( n & 1 ){
    	return 1;
    }
	return 0;
}
	
/**********************************************************************
Check if an integer n is a triangular number.
return 1 - if n is triangular
return 0 - if n is not triangular
**********************************************************************/
char istriangle(int n){
    if (triangularNumber(n) != 0){
    	return 1;
    }
    else return 0;

}

/**********************************************************************
The equation to obtain the triangular number.
**********************************************************************/
int triangularNumber(int n){
    float triangleNumber = ((float)n + 1) /2;
	if (triangleNumber - (int)triangleNumber == 0){
		return triangleNumber;
	} 
	else return 0;
}

/**********************************************************************
Print all triangular numbers below n along the hypotenuse of a triangle
shape. e.g. 10 is a triangular number, therefore the function prints
01 
** 03 
** ** 06 
** ** ** 10 
PRE: This function assumes n is already a triangular number. i.e. this
function is called only if istriangle(n) returns 1.
**********************************************************************/
void printtriangle(int n){
    if istriangle(n) == 1 {
    	printf("");
    }

}

