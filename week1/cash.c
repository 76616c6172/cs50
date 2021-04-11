#include <cs50.h>
#include <stdio.h>


/*
Implement, a program that first asks the user how much change is owed_pennies and then prints the minimum number of coins with which that change can be made.

Use get_float to get the user’s input and printf to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
We ask that you use get_float so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed_pennies $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed_pennies $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is “formatted” like money should be.
You need not try to check whether a user’s input is too large to fit in a float. Using get_float alone will ensure that the user’s input is indeed a floating-point (or integral) value but not that it is non-negative.
If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
So that we can automate some tests of your code, be sure that your program’s last line of output is only the minimum number of coins possible: an integer followed by \n.
Beware the inherent imprecision of floating-point values. Recall floats.c from class, wherein, if x is 2, and y is 10, x / y is not precisely two tenths! And so, before making change, you’ll probably want to convert the user’s inputted dollars to cents (i.e., from a float to an int) to avoid tiny errors that might otherwise add up!
Take care to round your cents to the nearest penny, as with round, which is declared in math.h. For instance, if dollars is a float with the user’s input (e.g., 0.20), then code like

int cents = round(dollars * 100);
will safely convert 0.20 (or even 0.200000002980232238769531250) to 20.

Your program should behave per the examples below.

$ ./cash
Change owed_pennies: 0.41
4
$ ./cash
Change owed_pennies: -0.41
Change owed_pennies: foo
Change owed_pennies: 0.41
4
*/

float get_user_input_change_owed() {
	while (1) {
		float owed = get_float("Change owed_pennies: ");
		if (owed < 0)	{
			printf("Negative value for change not allowed.\n");
		}else{
			return owed;
		}

	}
}

int main() {
	int quarter		=	25;	//.25
	int dime			= 10;	//.10
	int nickel		= 5;	//.05
	int penny			= 1;	//.01

	float owed = get_user_input_change_owed();
	int owed_pennies = (int)(owed * 100);

	/* ## GREEDY ALGORITHM */
	//take out quarters until remainder < $0.25
	
	int coincounter = 0;
	while ( owed_pennies >= quarter) {
		owed_pennies -= quarter;
		coincounter++;
	}
	//take out dimes until remainder < $0.10
	while ( owed_pennies >= dime) {
		owed_pennies -= dime;
		coincounter++;
	}
	//take out nickels until remainder < $0.05
	while ( owed_pennies >= nickel) {
		owed_pennies -= nickel;
		coincounter++;
	}
	//take out pennies until remainder < $0.01
	//FIXME: For some reason it has trouble giving out the last penny sometimes.. as with 0.11 for example.
	while ( owed_pennies >= penny) {
		owed_pennies -= penny;
		coincounter++;
	}
	

	printf("Change remaining is %d and amount of coins given out is:\n%d\n", owed_pennies, coincounter);




}