/*
Write a program that takes the x-y coordinates of a point in the Cartesian plane and displays a 
message  telling either an axis on which the point lies or the quadrant in which it is found.
*/

int main() {

	double x,y;
	printf("Enter x, y values>");
	scanf("%lf, %lf", &x, &y);
	if ( x>0 && y>0) {
		printf("QI\n");
	}
	else if(x<0 && y>0){
		printf("QII\n");
	}
	else if(x<0 && y<0){
		printf("QIII\n");
	}
	else (x>0 && y<0){
		printf("QII\n");
	}

	return 0;
}