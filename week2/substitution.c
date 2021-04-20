#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
Design and implement a program, substitution, that encrypts messages using a substitution cipher.

$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN

Implement your program in a file called substitution.c in a directory called substitution.
Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

Here’s how the program might work if the user provides a key of VCHPRZGJNTLSKFBDQWAXEUYMOI and a plaintext of hello, world:

$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp

...
*/

int main(int arc, char *argv[]){
	int i;

	/* Take in the encryption key and perform various checks
	--- */

	string key = argv[1];
	if (arc > 2) {
		printf("Error: Only 1 key allowed.\nUsage: ./substitution key\n");
		return 1;
	}
	if (arc == 1) {
		printf("Usage: ./substitution key\n");
		return 1;
	}
	//check to only allowe 26 char keys
	if (!(strlen(key)) == 26) {
		printf("Error: Key must contain 26 characters.\n");
		return 1;
	}
	//create all uppercase key
	char keyUpper[strlen(key)];
	for (i = 0; i < strlen(key); i++) {
		keyUpper[i] = toupper(key[i]);
	}
	//create all lowercase key
	char keyLower[strlen(key)];
	for (i = 0; i < strlen(key); i++) {
		keyLower[i] = tolower(key[i]);
	}
	int sumOfletters = 0;
	for (i = 0; i < strlen(key); i++) {
		if (!isalpha(key[i])) {
		printf("Error: Only alphabetic characters allowed in key.\n");
		return 1;
		}
		sumOfletters += (int)keyUpper[i];
	}
	//2015 is the sum of all upper case letters character codes (Quick way to check for duplicate letters)
	if (!(sumOfletters == 2015)) {
		printf("Error: Key must be 26 characters and contain each letter exactly once.\n");
		return 1;
	}

	/* Ask the user for plaintext, then encrypt and print it
	--- */

	string text = get_string("Plaintext: ");

	//convert plaintext to uppercase
	char textUpper[strlen(text)];
	for (i = 0; i < strlen(text); i++) {
		textUpper[i] = toupper(text[i]);
	}

	printf("ciphertext: ");

	//convert the plaintext to ciphertext and print it
	int letterPosition;
	for (int a = 0; a < strlen(text); a++) {
		letterPosition = ((int)(textUpper[a])) -65;
		if (!isalpha(text[a])) {	//don't encrypt commas, periods, ..etc
			printf("%c",text[a]);
		}else if (islower(text[a])) {	//encrypt lowercase with the lowercase key
			printf("%c",keyLower[letterPosition]);
		}else if (isupper(text[a])) {
			printf("%c",keyUpper[letterPosition]);
		//printf("%c",key[letterPosition]);
		}	
	}

	printf("\n");
	return 0;
}
