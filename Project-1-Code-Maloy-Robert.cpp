/**
 * @name: Project-1-Code-Maloy-Robert.cpp
 * @date: 24 January 2019
 * @desc: "Implementation of Vignere Cipher in GNU C++"
 * @author: Robert Maloy
 *
 * This program is licensed under the GNU GPL v2.0 license. Please see LICENSE for further details. **/

/* standard libraries being imported; some of them probably aren't used, but might be. I don't know. */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

/* not always the most acceptable convention but I am not entering std:: in front of everything >:( */
using namespace std;

string testPhrases[] = {
	"A HEALTHY ATTITUDE IS CONTAGIOUS BUT DONT WAIT TO CATCH IT FROM OTHERS.",
	"IF YOU CARRY YOUR CHILDHOOD WITH YOU YOU NEVER BECOME OLDER.",
	"FROM PRINCIPLES IS DERIVED PROBABILITY BUT TRUTH OR CERTAINTY IS OBTAINED ONLY FROM FACTS.",
	"I WANT TO BREAK FREE",
	"Actions certainly do speak louder than words...",
	"Yesterday, all my troubles seemed so far away-- now it looks as if they're here to stay, oh I believe in Yesterday.",
	"Baby, you can light my fire...",
	"The Internationale unites the human race!"
};



int main(int argc, char* argv[]) {

	int i, j; //declare empty integer variables for counter purposes!
	string inString; //declare empty variable for a string

	if (!argv[1]) { //if there is no first argument...
		cout << "Please enter a string to encrypt\n :> "; //ask user to input a string into the thing.
		getline(cin, inString); //C-ism to get us a string that has no garbage at the end of it.
	}
	else {
		/* Create our syntax selector by converting the char* value
		 in argv[1] to a long integer, as it is required by the C++ library. */
		long syntaxSelect;
		syntaxSelect = strtol(argv[1], NULL, 10);

		/* Error checking statement to verify the integer is between 1 and 8. */
		if (syntaxSelect > 8 | syntaxSelect < 1) {
			printf("Please enter an integer value between 1 and 8.\n");
			return 0;
		}
		else {
			inString = testPhrases[syntaxSelect-1];
		}
	}

	/* Error checking statement to see if a user has entered too many integer values on the command line. */
	if (argc > 2) {
		printf("Please only enter one or no integers at a time.\n");
		return 0;
	}

	/* I was going to let you define your own key, but I kept having issues with line ending garbage, 
	so I have decided to remove that functionality. You'll just simply have to live with my last name... */
	string inKey = "MALOY";

	int msgLen = strlen(inString.c_str()); //get length and commit it to an integer
	char msg[msgLen]; //create a char array matching those parameters
	strcpy(msg, inString.c_str()); //copy the string we created into the new array.

	/* Now we're going to repeat the same process we just did but with the key. 
	Retrieve user input, get an integer of length, create a character array, copy string into array. */

	int keyLen = strlen(inKey.c_str());
	char key[keyLen];
	strcpy(key, inKey.c_str());

	/* create new key array to the proper length.*/
	char keyGen[msgLen];

	/* append some proper line endings so it doesn't create garbage... */
	for (int i = 0; i < msgLen; i++) keyGen[i] = '\0';

	for (i = 0, j = 0; i <= msgLen; ++i, ++j) { //dual for loop
		if (msg[i] == ' ') { //if there is a space inside the original message,
			keyGen[i] = ' '; //then you should simply push the space to the new key array.
			i++; //and then iterate i.
		}
		if (j == keyLen) { //if you reach the end of the original key,
			j = 0; //then reset the key back to origin.
		}
		keyGen[i] = key[j]; //set the new key array's current iterative value to that of the key's current value.
		if (msg[i] < 'A' | msg[i] > 'Z') { //if the character at msg[i] is not a capital letter...
			if (msg[i] >= 'a' && msg[i] <= 'z') { //double check to see if it's a lowercase letter.
				//do nothing if it is.
			}
			else {
				keyGen[i] = msg[i]; //if it isn't alphabetical, then simply push the original character to the keygen; this means any punctuation, or anything like that.
			}
		}
	}
	printf("msg: %s\n", msg);
	printf("keygen: %s\n", keyGen);
	//printf("length of key phrase=%lu\n", strlen(keyGen));
	//printf("expected length=%d\n", msgLen);

	/* debug statement */
	if ((int)strlen(keyGen) != msgLen) {
		printf("Generated key phrase exceeds original message size.\n");
	}

	/* Create encrypted message array and push some line endings to keep it sane. */
	char encryptedMsg[msgLen];
	for (int i = 0; i < msgLen; i++) encryptedMsg[i] = '\0';

	/* repeat process, but this time with the encryption. */
	for (i = 0; i <= msgLen; ++i) {
		if (msg[i] == ' ') {
			encryptedMsg[i] = ' ';
			i++;
		}
		encryptedMsg[i] = ((msg[i] + keyGen[i]) % 26) + 'A'; //following the formulae for this cipher. Original character + Key character mod 26.
		if (msg[i] < 'A' | msg[i] > 'Z') {
			if (msg[i] >= 'a' && msg[i] <= 'z') {
				//do nothing...
			}
			else {
				encryptedMsg[i] = msg[i];
			}
		}
	}

	/* print out and check to see if it matches expected length. */
	printf("encrypted msg: %s\n", encryptedMsg);
	if ((int)strlen(encryptedMsg) != msgLen) {
		printf("ERR: Encrypted message exceeds original message size.\n");
	}

	/* terminate program when complete :) */
	return 0;
}