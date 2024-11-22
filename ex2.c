/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
  int select, number, space, counter, sum1, sum2, size1, flag;
  char eyes, nose, mouse;
  while (1) {
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
    // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
    /* Example:
     * n = 3:
     * 0   0
     *   o
     * \___/
     */
    case 1: {
      printf("Enter symbols for the eyes, nose, and mouse:\n");
      scanf(" %c %c %c", &eyes, &nose, &mouse);
      printf("Enter face size:\n");
      do {
        scanf("%d", &number);
        if ((number <= 0) || (number % 2 == 0))
          printf("The face's size must be an odd and positive number, please "
                 "try again:\n");
      } while ((number <= 0) || (number % 2 == 0));
      space = (number + 1) / 2;
      for (int i = 0; i < number + 1; i++) {
        if (i != 0)
          printf(" ");
        else
          printf("%c", eyes);
      }
      printf("%c\n", eyes);
      for (int i = 0; i < space; i++)
        printf(" ");
      printf("%c\n\\", nose);
      for (int i = 0; i < number; i++)
        printf("%c", mouse);
      printf("/\n");
      break;
    }

    // Case 2: determine whether the sum of all digits to the left of the middle
    // digit(s) and the sum of all digits to the right of the middle digit(s)
    // are equal
    /* Examples:
    Balanced: 1533, 450810, 99
    Not blanced: 1552, 34
    Please notice: the number has to be bigger than 0.
    */
    case 2: {
      printf("Enter a number:\n");
      do {
        scanf("%d", &number);
        if (number <= 0)
          printf("Only positive number is allowed, please try again:\n");
      } while (number <= 0);
      if (number < 10)
        printf("This number is balanced and brings harmony!\n");
      else {

        size1 = number;
        counter = 0;
        while (size1 != 0) {
          counter++;
          size1 = size1 / 10;
        }
        sum1 = 0;
        sum2 = 0;
        for (int i = 1; i <= counter; i++) {
          if (i <= counter / 2) {
            sum1 = sum1 + number % 10;
            number = number / 10;
          } else if (counter % 2 == 1 && i == (counter / 2) + 1)
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
      // Case 3: determine whether the sum of the proper divisors (od an
      // integer) is greater than the number itself
      /* Examples:
      Abudant: 12, 20, 24
      Not Abudant: 3, 7, 10
      Please notice: the number has to be bigger than 0.
      */
      printf("Enter a number:\n");
      do {
        scanf("%d", &number);
        if (number <= 0)
          printf("Only positive number is allowed, please try again:\n");
      } while (number <= 0);
      sum1 = 0;
      for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0)
          sum1 += i;
      }
      if (sum1 > number)
        printf("This number is generous!\n");
      else
        printf("This number does not share.\n");
      break;
    }

    case 4: {
      // Case 4: determine wether a number is a prime.
      /* Examples:
      This one brings joy: 3, 5, 11
      This one does not bring joy: 15, 8, 99
      Please notice: the number has to be bigger than 0.
      */
      printf("Enter a number:\n");
      do {
        scanf("%d", &number);
        if (number <= 0)
          printf("Only positive number is allowed, please try again:\n");
      } while (number <= 0);
      if (number == 1)
        printf("The circle remains incomplete.\n");
      else {
        flag = 1;
        for (int i = 2; i <= number / 2; i++) {
          if (number % i == 0)
            flag = 0;
        }
        if (flag)
          printf("This number completes the circle of joy!\n");
        else
          printf("The circle remains incomplete.\n");
      }
      break;
    }
	
    case 5: {
      printf("Enter a number:\n");
      do {
        scanf("%d", &number);
        if (number <= 0)
          printf("Only positive number is allowed, please try again:\n");
      } while (number <= 0);
      int x = 0;
      int orignal_num = number;
      flag = 1;
      int last_digit = 0;
      while (flag) {
        while (number > 0) {
          x += (number % 10) * (number % 10);
          number /= 10;
          last_digit = number % 10;
        }

        printf("%d\n", x);

        if ((x % 10 == 0 && last_digit == 1) || x == 1) {
          flag = 0;
          printf("happy number\n");
        } else if (x == 4) {
          printf("not happy number/n");
          flag = 0;
        }
        number = x;
        x = 0;
      }
      break;
    }
    default:
      printf("This option is not available, please try again.\n");
      break;
    }
  }

  // Happy numbers: Print all the happy numbers between 1 to the given number.
  // Happy number is a number which eventually reaches 1 when replaced by the
  // sum of the square of each digit
  /* Examples:
  Happy :) : 7, 10
  Not Happy :( : 5, 9
  Please notice: the number has to be bigger than 0.
  */

  // Festival of Laughter: Prints all the numbers between 1 the given number:
  // and replace with "Smile!" every number that divided by the given smile
  // number and replace with "Cheer!" every number that divided by the given
  // cheer number and replace with "Festival!" every number that divided by both
  // of them
  /* Example:
  6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
  */
  return 0;
}
