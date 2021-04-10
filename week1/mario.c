#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide,
so the pyramids themselves are also be taller than they are wide.

   #  #
  ##  ##
 ###  ###
####  ####

The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.
*/

int get_user_height() {
	int input;
	while (1) {
		input = get_int("Enter desired height: ");
		if (input < 1 || input > 8) {
			printf("Height has to be between 1 and 8.\n");
		}else{
			printf("\n");
			return input;
		}
	}
}

int main() {
	int a,b, spaces_amount,blocks_amount;
	//get height from user
	int height = get_user_height();

	//print the shape line by line
	for (a = 0; a < height; a++) {
		spaces_amount		= height - a;
		blocks_amount		= a;
		
		//reset the block components for rebuilding them
		char blocks[1000] = "";
		char spaces[1000]= "";

		//build string of spaces
		for (b =0; b<=spaces_amount; b++) {
			strcat(spaces, " ");
		}

		//build string of blocks
		for (b =0; b<=blocks_amount; b++) {
			strcat(blocks, "#");
		}

		//build the string for the current line and print it
		strcat(spaces, blocks);	//the first argument becomes both strings together
		printf("%s\n", spaces);
	}
}
