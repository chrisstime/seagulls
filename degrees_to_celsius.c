#include <stdio.h>

double depthToDegreesCelcius(double depth)
{
	return (10 * depth) + 20;
}

double depthToDegreesFahrenheit(double depth)
{
	return (1.8 * depthToDegreesCelcius(depth)) +32;
}

int main()
{
	double depthInKM = 0.0;
	printf("Please input number of kilometers below surface>");
	scanf("%lf", &depthInKM);

	printf("Celcius: %f\nFahrenheit: %f\n", depthToDegreesCelcius(depthInKM), depthToDegreesFahrenheit(depthInKM));
	return 0;
}