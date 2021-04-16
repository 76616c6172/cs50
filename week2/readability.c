#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/*
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is:

index = 0.0588 * L - 0.296 * S - 15.8
Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

Let’s write a program called readability that takes a text and determines its reading level. For example, if user types in a line from Dr. Seuss:

$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3

The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words. And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words. Plugged into the Coleman-Liau formula, and rounded to the nearest whole number, we get an answer of 3: so this passage is at a third grade reading level.
*/

string get_user_input(string message){
	string input = get_string(message);
	printf("\n");
	return input;
}

int isPunctuation (char rune) {
	if ( rune == '!' || rune == '.' || rune == '?') {
		return 1;
	}else {
		return 0;
	}
}

int main() {
	int sentences, letters , words;
	sentences = letters = words = 0;

	//Prompt user for text input
	string text = get_user_input("Text: ");

	//Count letters and punctuation(as a proxy for sentenceos)
	int length = strlen(text);
	int inside = 0; // 1 = we are inside a word, 0 = we are outside a word;
	for (int i=0; i<length; i++) {
		//printf("%c",text[i]);
		if (isalpha(text[i]) && inside == 0){
			words++;
			inside = 1;
		}
		if (isalpha(text[i])) {
			letters++;
		}else if (isPunctuation(text[i])) {
			sentences++;
		}
		if (isblank(text[i]) && inside == 1) {
			inside = 0;
		}
	}

	//Compute the score and print information
	float index =  0.0588* ((float)letters)/((float)words) * 100.0  - 0.2960 * ((float)sentences)/((float)words) * 100.0 - 15.800;

	//Grade can't be less than 1;
	if (index < 1) {
		index = 1;
	}
	printf("\n%d Letters.\n%d words.\n%d sentences.\nGrade %0.f\n", letters, words, sentences, index);
}
