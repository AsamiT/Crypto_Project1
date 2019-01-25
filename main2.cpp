/**
 * @name: main2.cpp
 * @date: 24 January 2019
 * @desc: "Implementation of Vignere Cipher in GNU C++"
 * @author: Robert Maloy
 *
 * This program is licensed under the GNU GPL v2.0 license. Please see LICENSE for further details. **/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

string testPhrase1 = "A HEALTHY ATTITUDE IS CONTAGIOUS BUT DONT WAIT TO CATCH IT FROM OTHERS.";
string testPhrase2 = "IF YOU CARRY YOUR CHILDHOOD WITH YOU YOU NEVER BECOME OLDER.";
string testPhrase3 = "FROM PRINCIPLES IS DERIVED PROBABILITY BUT TRUTH OR CERTAINTY IS OBTAINED ONLY FROM FACTS.";
string testPhrase4 = "I WANT TO BREAK FREE";

int main(int argc, char* argv[]) {

	int i, j; //declare empty integer variables for counter purposes!
	string inString; //declare empty variable for a string

	if (!argv[1]) {
		cout << "Please enter a string to encrypt\n :> "; //ask user to input a string into the thing.
		getline(cin, inString);
	}
	else {
	/* Create our syntax selector by converting the char* value
	 in argv[1] to a long integer, as it is required by the C++ library. */
		long syntaxSelect;
		syntaxSelect = strtol(argv[1], NULL, 10);

	/* Error checking statement to verify the integer is between 1 and 4. */
		if (syntaxSelect > 4 | syntaxSelect < 1) {
			printf("Please enter an integer value between 1 and 4.\n");
			return 0;
		}
		if (syntaxSelect == 1) {
			inString = testPhrase1;
		}
		if (syntaxSelect == 2) {
			inString = testPhrase2;
		}
		if (syntaxSelect == 3) {
			inString = testPhrase3;
		}
		if (syntaxSelect == 4) {
			inString = testPhrase4;
		}
	}

	/* Error checking statement to see if a user has entered too many integer values on the command line. */
	if (argc > 2) {
		printf("Please only enter one or no integers at a time.\n");
		return 0;
	}

	string inKey = "MALOY";

	int msgLen = strlen(inString.c_str()); //get length and commit it to an integer
	char msg[msgLen]; //create a char array matching those parameters
	strcpy(msg, inString.c_str()); //copy the string we created into the new array.

	/* Now we're going to repeat the same process we just did but with the key. 
	Retrieve user input, get an integer of length, create a character array, copy string into array. */

	int keyLen = strlen(inKey.c_str());
	char key[keyLen];
	strcpy(key, inKey.c_str());

	char keyGen[msgLen];
	for (int i = 0; i < msgLen; i++) keyGen[i] = '\0';

	for (i = 0, j = 0; i <= msgLen; ++i, ++j) {
		if (msg[i] == ' ') {
			keyGen[i] = ' ';
			i++;
		}
		if (j == keyLen) {
			j = 0;
		}
		keyGen[i] = key[j];
		if (msg[i] < 'A' | msg[i] > 'Z') {
			keyGen[i] = msg[i];
		}
	}
	printf("msg: %s\n", msg);
	printf("keygen: %s\n", keyGen);
	//printf("length of key phrase=%lu\n", strlen(keyGen));
	//printf("expected length=%d\n", msgLen);
	if ((int)strlen(keyGen) != msgLen) {
		printf("Generated key phrase exceeds original message size.\n");
	}

	char encryptedMsg[msgLen];
	for (int i = 0; i < msgLen; i++) encryptedMsg[i] = '\0';

	for (i = 0; i <= msgLen; ++i) {
		if (msg[i] == ' ') {
			encryptedMsg[i] = ' ';
			i++;
		}
		encryptedMsg[i] = ((msg[i] + keyGen[i]) % 26) + 'A';
		if (msg[i] < 'A' | msg[i] > 'Z') {
			encryptedMsg[i] = msg[i];
		}
	}

	printf("encrypted msg: %s\n", encryptedMsg);
	if ((int)strlen(encryptedMsg) != msgLen) {
		printf("ERR: Encrypted message exceeds original message size.\n");
	}

	return 0;
}