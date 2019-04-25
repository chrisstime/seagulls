/*
Tute 3 April 14 Thursday

3. Write a switch statement to select an operation based on the color of a sample observed by an automated 
chemical-flow contrl system that is checking to see whether them material flowing into a processing vat
is acidic or basic. If the color is indicated as 'B' (for blue), add to the total_bases variable the valie of the 
variable base_strength. If the color is indicated as 'R' (for red), increase the value of the variable
total_acids by the value of acid_strength. If the color is 'P' (for purple), add to the variable neutrals
the value of sample_size. Do nothing if the color is 'Y' (for yellow). Display an error message if the value of 
color is not one of these values.
*/

switch(colour) {
	case 'B';
	total_bases += base_strength;
	break;

	case 'R';
	total_acids += acid_strength;
	break;

	case 'P';
	neutrals += sample_size;
	break;

	case 'Y';
	break;

	default printf("Error. Color is not part of the data base.\n");
}