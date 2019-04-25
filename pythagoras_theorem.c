#include<stdio.h>
#include<math.h>

double hypotenuse(double a, double b) {
	return sqrt(pow(a,2) + pow(b,2)); /* this is the pythogaras' theorem c= sqrt(a^2 + b^2) */
}

double userInput(char str[]) {
	double input;
	printf(str);
	scanf("%lf", &input);
	return input;
}

int main() {
	double legOne, legTwo;
	legOne = userInput("Input for leg one");
	legTwo = userInput("Input for leg two");
	printf("Hypotenuse: %s\n", hypotenuse(legOne, legTwo) );
	return 0;
}