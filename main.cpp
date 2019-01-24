/**
 * @name: main.cpp
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

int msgLen, keyLen;

int main(int argc, char* argv[]) {

	/* Error checking statement to see if a user has entered an integer value as an argument. */
	if (argc == 1) {
		printf("Syntax: Please enter one integer value between 1 and 3.\n");
		return 0;
	}

	/* Error checking statement to see if a user has entered too many integer values on the command line. */
	if (argc > 2) {
		printf("Please only enter one integer at a time.\n");
		return 0;
	}

	/* Create our syntax selector by converting the char* value
	 in argv[1] to a long integer, as it is required by the C++ library. */
	long syntaxSelect;
	syntaxSelect = strtol(argv[1], NULL, 10);

	/* Error checking statement to verify the integer is between 1 and 3. */
	if (syntaxSelect > 3 | syntaxSelect < 1) {
		printf("Please enter an integer value between 1 and 3.\n");
		return 0;
	}

	/* setting up our messages with spaces! */

	/* our encryption key... */
	char encKey[] = "MALOY";
	char testKey[] = "KHOSHAVI"; //this is included in order to test the example test case given in the project PDF. Debug only.

	if (syntaxSelect == 1) {
		char msg[] = "A HEALTHY ATTITUDE IS CONTAGIOUS BUT DONT WAIT TO CATCH IT FROM OTHERS.";
		msgLen = strlen(msg); //msg
		printf("Message 1: %s\n", msg);
	}

	if (syntaxSelect == 2) {
		char msg[] = "IF YOU CARRY YOUR CHILDHOOD WITH YOU YOU NEVER BECOME OLDER.";
		msgLen = strlen(msg); //msg
		printf("Message 2: %s\n", msg);
	}

	if (syntaxSelect == 3) {
		char msg[] = "FROM PRINCIPLES IS DERIVED PROBABILITY BUT TRUTH OR CERTAINTY IS OBTAINED ONLY FROM FACTS.";
		msgLen = strlen(msg); //msg
		printf("Message 3: %s\n", msg);
	}

	keyLen = strlen(testKey); //proper encryption
	printf("msgLen: %d\n", msgLen);
	printf("keyLen: %d\n", keyLen);
	char keyGen[msgLen];

	for (int i = 0, j = 0; i < msgLen; ++i, ++j) {
		if (j == keyLen) {
			j = 0;
		}
		if (msg[i] = ' ') {
			keyGen[i] = ' ';
		}
		keyGen[i] = testKey[j];
	}

	return 0;
}
