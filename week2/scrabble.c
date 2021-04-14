#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//int compute_score(char word[]);
//Computes and returns score for string
int compute_score(char word[]) {
	char wordUpper[strlen(word)];

	 //convert string to uppercase
	for (int i = 0; i < strlen(word); i++) {
		wordUpper[i] = toupper(word[i]);
	}
	//Iterate over the chars of the string and calculate its score
	int score = 0;
	int letter;

	for (int a = 0; a < strlen(wordUpper); a++) {
		letter = (int)(wordUpper[a])-65;
		//debug printf("character: %c\nletter: %d\n", wordUpper[a], letter);
		score += POINTS[letter];
	}
	return score;
}

int main(void) {
    //Get input words from both players
    char word1[1000]; strcpy(word1, get_string("Player 1: "));
    char word2[1000]; strcpy(word2, get_string("Player 2: "));

    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

		//Print the scores for debugging
		//printf("%s: scored %d\n%s: scored %d\n",word1 ,score1, word2, score2);

    //Print the winner
		if ( score1 > score2) {
			printf("Winner: %s\n", word1)	;
		}else if ( score1 < score2 ){
			printf("Winner: %s\n", word2)	;
		}else{
			printf("Tie.\n");
		}
}
