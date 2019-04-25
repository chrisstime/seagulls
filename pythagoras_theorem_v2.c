#include<stdio.h>
#include<math.h>

main void() {
	double x,y;
	readTriangleLegs(&x, &y);
	printf("hypotenuse = %f\n", hyp(x,y));
	return 0;
}

double hyp(double x, double y) {
	return sqrt(pow(x,2) + pow(y,2));
}

void readTriangleLegs(double*x, double*y) {
	printf("Enter length of leg one>");
	scanf("%f", x);
	printf("Enter length of leg two>");
	scanf("%f", y);
}