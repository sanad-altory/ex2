/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    int select,flag,The_End;
    while (The_End) {
        printf("Choose an option:\n");
        printf("1. Happy Face\n");
        printf("2. Balanced Number\n");
        printf("3. Generous Number\n");
        printf("4. Circle Of Joy\n");
        printf("5. Happy Numbers\n");
        printf("6. Festival Of Laughter\n");
        printf("7. Exit\n");
        scanf("%d", &select);
        switch (select) {
            case 1: {
                // Case 1: Draw Happy Face with given symbols for eyes, nose and mouth
                /* Example:
                 * n = 3:
                 * 0   0
                 *   o
                 * \___/
                 */
                int number,space;
                char eyes, nose, mouth;
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth);
                printf("Enter face size:\n");
                do { // In this loop we make sure that the user enter a positive and odd number
                    scanf("%d", &number);
                    if ((number <= 0) || (number % 2 == 0))
                        printf("The face's size must be an odd and positive number, please "
                            "try again:\n");
                } while ((number <= 0) || (number % 2 == 0));
                space = (number + 1) / 2;//To calculate the distance for the nose
                for (int i = 0; i < number + 1; i++) {
                    if (i != 0)
                        printf(" ");//print tabs after the first eye
                    else
                        printf("%c", eyes);//print the first eye
                }
                printf("%c\n", eyes);//print the second eye
                for (int i = 0; i < space; i++)
                    printf(" ");//print tabs before the nose
                printf("%c\n\\", nose);
                for (int i = 0; i < number; i++)
                    printf("%c", mouth);
                printf("/\n");
                break;
            }
            case 2: {
                int number,size1,sum1,sum2,counter;
                // Case 2: determine whether the sum of all digits to the left of the middle
                // digit(s) and the sum of all digits to the right of the middle digit(s)
                // are equal
                /* Examples:
                Balanced: 1533, 450810, 99
                Not blanced: 1552, 34
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number:\n");
                do {//To make sure that the User enter a positive number
                    scanf("%d", &number);
                    if (number <= 0)
                        printf("Only positive number is allowed, please try again:\n");
                } while (number <= 0);
                if (number < 10)//If the number is below 10 we don't need to check the number
                    printf("This number is balanced and brings harmony!\n");
                else {
                    size1 = number;
                    counter = 0;
                    while (size1 != 0) {// a counter for the indexes in the number
                        counter++;
                        size1 = size1 / 10;
                    }
                    sum1 = 0;// a sum from the first index to the middle one
                    sum2 = 0;// a sum from the middle index to the last one
                    for (int i = 1; i <= counter; i++) {
                        if (i <= counter / 2) {
                            sum1 = sum1 + number % 10;
                            number = number / 10;
                        } else if (counter % 2 == 1 && i == (counter / 2) + 1) // If counter an odd number then we overlook the middle number and don't count it in the sums
                            number = number / 10;
                        else {
                            sum2 = sum2 + number % 10;
                            number = number / 10;
                        }
                    }
                    if (sum1 == sum2)
                        printf("This number is balanced and brings harmony!\n");
                    else
                        printf("This number isn't balanced and destroys harmony.\n");
                }
                break;
            }

            case 3: {
                int number,sum;
                // Case 3: determine whether the sum of the proper divisors (od an
                // integer) is greater than the number itself
                /* Examples:
                Abudant: 12, 20, 24
                Not Abudant: 3, 7, 10
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number:\n");
                do {// To make sure the User enter a positiver number
                    scanf("%d", &number);
                    if (number <= 0)
                        printf("Only positive number is allowed, please try again:\n");
                } while (number <= 0);
                sum = 0;// A sum for all the numbers that greater than the User number
                for (int i = 1; i <= number / 2; i++) {
                    if (number % i == 0)// check if number can be divided by i equal to 0 then add i to sum
                        sum += i;
                }
                if (sum > number)
                    printf("This number is generous!\n");
                else
                    printf("This number does not share.\n");
                break;
            }

            case 4: {
                int number;
                // Case 4: determine wether a number is a prime.
                /* Examples:
                This one brings joy: 3, 5, 11
                This one does not bring joy: 15, 8, 99
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number:\n");
                do { // to make sure the User enter a positive number
                    scanf("%d", &number);
                    if (number <= 0)
                        printf("Only positive number is allowed, please try again:\n");
                } while (number <= 0);
                if (number == 1)// if the number is 1 then it's not a prime number
                    printf("The circle remains incomplete.\n");
                else {
                    flag = 1;
                    for (int i = 2; i <= number / 2; i++) {// Just need to check to the number/2
                        if (number % i == 0)// we check that the number can't be divided by another number than it'self and 1
                            flag = 0;
                    }
                    if (flag)// if the flag 1 then it's a prime number else if it 0 then it's not aprime number
                        printf("This number completes the circle of joy!\n");
                    else
                        printf("The circle remains incomplete.\n");
                }
                break;
            }

            case 5: {
                int number,sum,Test,last_digit;
                // Happy numbers: Print all the happy numbers between 1 to the given number.
                // Happy number is a number which eventually reaches 1 when replaced by the
                // sum of the square of each digit
                /* Examples:
                Happy :) : 7, 10
                Not Happy :( : 5, 9
                Please notice: the number has to be bigger than 0.
                */
                printf("Enter a number:\n");
                do {// make sure that the User enter a positive number
                    scanf("%d", &number);
                    if (number <= 0)
                        printf("Only positive number is allowed, please try again:\n");
                } while (number <= 0);
                printf("Between 1 and %d only these numbers bring happiness:\n",number);
                for(int i = 1; i<= number; i++) {// i, run from 1 to the number of the user
                    flag = 1;
                    sum = 0;
                    last_digit = 0;
                    Test = i;
                    while (flag) {// we check if number i ,a happy number
                        while (Test > 0) {
                            sum += (Test % 10) * (Test % 10);
                            Test /= 10;
                            last_digit = Test % 10;
                        }
                        if ((sum % 10 == 0 && last_digit == 1) || sum == 1) {// to check if the sum can be divided by 10 or the last digit equal to 1
                            flag = 0;
                            printf("%d ",i);
                            break;
                        }else if (sum == 4) { // if in some point the sum equal to 4 then we are in an infinity loop and the number can't equal 1
                            flag = 0;
                            break;
                        }
                        Test = sum;
                        sum = 0;
                    }

                }
                printf("\n");
                break;
            }
            case 6 : {
                int smile,cheer,check,number;
                // Festival of Laughter: Prints all the numbers between 1 the given number:
                // and replace with "Smile!" every number that divided by the given smile
                // number and replace with "Cheer!" every number that divided by the given
                // cheer number and replace with "Festival!" every number that divided by both
                // of them
                /* Example:
                6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
                */
                printf("Enter a smile and cheer number:\n");
                do {
                    check = scanf(" smile: %d, cheer: %d", &smile, &cheer);
                   if(check != 2 || (smile <=0) || (cheer <=0)|| cheer==smile) {// we check if what the user enter match the format
                       printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                       scanf("%*[^\n]");// these scanfs are used to clean the buffer
                       scanf("%*c");
                   }
                }while( (check != 2)|| (smile <=0) || (cheer <=0)|| cheer==smile);
                printf("Enter maximum number for the festival:\n");
                do {// make sure the number that the user enter is positive
                    scanf("%d", &number);
                    if(number <= 0)
                        printf("Only positive number is allowed, please try again:\n");
                }while(number <=0);
                for(int i = 1; i <= number; i++) {
                    if ((i % smile == 0) && (i % cheer ==0)) {
                        printf("Festival!\n");// if the i, can be divided by cheer and smile numbers then print Festival
                        continue;
                    }
                    if (i % smile == 0 )
                        printf("Smile!\n");//if the i, can be divided by smile number then print Smile
                    else if(i % cheer ==0)
                        printf("Cheer!\n");//if the i, can be divided by cheer number then print Cheer
                    else
                        printf("%d \n",i);// if i, cant be divided by cheer or smile numbers then print i
                }
                break;
            }
            case 7 : {
                printf("Thank you for your journey through Numeria!\n");
                //The_End =0;
                break;

            }
            default:
                printf("This option is not available, please try again.\n");
                break;
        }
        The_End=0;
   }

return 0;



}
