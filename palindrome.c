#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isPalindrome(char *originalString) {
	bool result;
	char *copiedString = (char*)malloc(sizeof(char*strlen(originalString)));
	if (copiedString == NULL) {
		return false;
	}
	strcpy(copiedString, originalString);
	strrev(copiedString);
	 if( strcmp(originalString,copiedString) == 0 ) {
	 	result = true;
	 } else {
    	 result = false;
	 }
	 free(copiedString);
	 return result;
}

bool isPalindromePreparation(char *originalString, int beginningPoint, int endPoint) {
	int lengthOfString = endPoint - beginningPoint;
	bool resultFlag;
	if(!lengthOfString) { //this is for the case that the line is empty
		return true;
	}
	char *stringToBeSent = (char*)malloc(sizeof(char)*lengthOfString);
	if (stringToBeSent == NULL) {
		return false;
	} else {
		strcpy(stringToBeSent, originalString);
		resultFlag = isPalindrome(stringToBeSent);
		free(stringToBeSent);
		return resultFlag;
	}
}

MessageResult messageIsPalindrome(const Message message, bool* outIsPalindrome) {
	int lineLengthCounterEnd = 0;
	int lineLengthCounterStart = 0;
	bool palindromeFlag = true;

	if (message == NULL) {  //bad argument
		return MESSAGE_NULL_ARGUMENT;
	}
	if (message->type == MESSAGE_IMAGE) { //wrong type
		return MESSAGE_WRONG_TYPE;
	}
	while(message->content.text && palindromeFlag) {
		while(message->content.text[lineLengthCounterEnd] == '\n') { //Want to grab each line
			lineLengthCounterEnd++;
		}
		palindromeFlag = isPalindromePreparation(message->content.text, lineLengthCounterStart, lineLengthCounterEnd);
		lineLengthCounterStart = lineLengthCounterEnd + 1;
	}

	*outIsPalindrome = palindromeFlag;

	return MESSAGE_SUCCESS; // what are we supposed to return in these cases???

}

int main() {




	return 0;
}