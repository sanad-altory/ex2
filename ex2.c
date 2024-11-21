/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int select,size,space;
	char eyes,nose,mouse;
	while(1) {
		printf("Choose an option:\n");
		printf("	1. Happy Face\n");
		printf("	2. Balanced Number\n");
		printf("	3. Generous Number\n");
		printf("	4. Circle Of Joy\n");
		printf("	5. Happy Numbers\n");
		printf("	6. Festival Of Laughter\n");
		printf("	7. Exit\n");
		scanf("%d", &select);
		switch (select) {
			case 1:
				printf("Enter symbols for the eyes, nose, and mouse:\n");
				scanf(" %c %c %c",&eyes,&nose,&mouse);
				printf("Enter face size:\n");
				do {
					scanf("%d",&size);
					if((size<=0)||(size%2==0))
						printf("The face's size must be an odd and positive number, please try again:\n");
				}while((size<=0)||(size%2==0));
				space = (size +1)/2;
				for (int i=0;i<size+1;i++) {
					if(i!=0)
						printf(" ");
					else
						printf("%c",eyes);
				}printf("%c\n",eyes);
				for(int i=0;i<space;i++)
					printf(" ");
				printf("%c\n\\",nose);
				for(int i=0;i<size;i++)
					printf("%c",mouse);
				printf("/\n");
				break;
			default:
				printf("This option is not available, please try again.\n");
				break;

		}
	}



	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/
    

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
