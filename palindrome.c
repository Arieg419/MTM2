#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *strRev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char* subString(char* string, int lengthOfString, int beginningPoint) {
	if(string == NULL) {
		return NULL;
	}
	char* stringToReturn = malloc(sizeof(char)*lengthOfString);
	if(stringToReturn == NULL) {
		return NULL;
	}
	for(int i  = 0 ; i < lengthOfString; i++) {
		stringToReturn[i] = string[beginningPoint + i];
	}
	return stringToReturn;
}

bool isPalindrome(char *originalString) {
	bool result;
	char *copiedString = malloc(strlen(originalString)*sizeof(char));
	if (copiedString == NULL) {
		return false;
	}
	strcpy(copiedString, originalString);
	strRev(copiedString);
	 if( strcmp(originalString,copiedString) == 0 ) {
		printf("stringCompare is true\n");
	 	result = true;

	 } else {
    	 result = false;
	 }
	 free(copiedString);
	 printf("result is %d\n", result);
	 return result;
}

Message messageIsPalindrome(const Message message, bool* outIsPalindrome) {
	if(message == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message->type == MESSAGE_IMAGE) {
		return MESSAGE_WRONG_TYPE;
	}
	int counter  = 0;
	int numOfLines = 0;
	numOfLines = messageNumberOfLines(message);
	int indexArray = malloc(sizeof(int)*numOfLines);
	if(indexArray == NULL) {
		return NULL;
	}

	int indexArrayCounter = 0;
//!!!!!!!!!!!!!!!!! Getting All Indexes !!!!!!!!!!!!!!!!!!!!
	while(message->content.text[counter]) {
		if(message->content.text[counter] == '\n') {
			indexArray[indexArrayCounter] = counter;
			indexArrayCounter++;
		}
		counter++;
	}
//!!!!!!!!!!!!!!!! Printing all Indexes !!!!!!!!!!!!!!!!!!!!!!
	for(int  i = 0 ; i < numOfLines ; i++) {
		printf("%d\n", indexArray);
	}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	free(indexArray);
	return message;
}

int main() {
	Message message1;
	message1 = malloc(sizeof(struct message_t));
	if(message1 == NULL){
		return NULL;
	}
	message1->type  = MESSAGE_TEXT;
	message1->content.text = "abba";
	//printf("")
	free(message1);
}
