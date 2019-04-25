#include <stdio.h>

/*

1. Making the decision between two alternative courses of action is usually 
implemented with an IF statement in C.

2. When a multiple-alternative IF statement to display a message based on the level of force, 
in newtons, being applied by a robot hand attempting to turn a large threaded part into a machine. 
Force levels and associated messages are: 0, Part not found; 1-44, Insecure grip; 45-88, Nominal grip; 89-100,
Part may be misaligned; and above 100,DANGER -- part may be stuck. Print a message to indicate bad data as well.
		1. 0
		2. Port not found
		3. 1-44
		4. Insecure grip
		5. 45-58
		6. nominal grip 
*/

int main(void){
	int forceinN;
	printf("Please indicate the amount of force in newtons to be applied>");
	scanf("%d", &forceinN);

	if (forceinN == 0) {
		printf("Port not found\n");
	}
	else if (forceinN <= 44 && forceinN >= 1) {
		printf("Insecure grip\n");
	}
	else if (forceinN <= 88 && forceinN >= 45) {
		printf("Nomical Grip\n");
	}
	else if (forceinN <= 100 && forceinN >= 89) {
		printf("Part may be misaligned\n");
	}
	else if (forceinN > 100) {
		printf("DANGER -- part may be stuck\n");
	}
	else printf("Error. Bad data. Please input a positive whole number.\n");
}

