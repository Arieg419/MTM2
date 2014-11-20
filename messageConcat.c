/*
 * messageConcat.c
 *
 *  Created on: Nov 20, 2014
 *      Author: omer
 */


#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void stringConcat(Message message1, Message message2) {
	    int lengthofFirst = strlen(message1->content.text);
		int lengthOfSecond = strlen(message2->content.text);
		char *newString = malloc(sizeof(char)*(lengthofFirst+1+lengthOfSecond));
		strcpy(newString, message1->content.text);
		newString[lengthofFirst]= '\n';
		strcpy(newString + lengthofFirst + 1, message2->content.text);
		printf("%s", newString);
		message1->content.text = newString;
}

MessageResult messageConcat(Message message1, const Message message2) {
	if(message1 == NULL || message2 == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message1->type == MESSAGE_IMAGE || message2->type == MESSAGE_IMAGE) {
		printf("this is the wrong type");
		return MESSAGE_WRONG_TYPE;
	}
	if(message1->senderID != message2->senderID) {
		return MESSAGE_DIFFERENT_SENDER;
	}
	/*int lengthofFirst = strlen(message1->content.text);
	int lengthOfSecond = strlen(message2->content.text);
	char *newString = malloc(sizeof(char)*(lengthofFirst+lengthOfSecond));
	strcpy(newString, message1->content.text);
	strcpy(newString + lengthofFirst, message2->content.text);
	*/
	stringConcat(message1, message2);
	return MESSAGE_SUCCESS;
}

/*
int main() {
		int id = 302365697;
		Message message1=malloc(sizeof(struct message_t));
		Message message2=malloc(sizeof(struct message_t));
		char* string = "Omer";
		char* string2 = "Nela";
		message1->content.text = string;
		message2->content.text = string2;
		message1->senderID = id;
		message2->senderID = id;
		message1->type =  MESSAGE_TEXT;
		message2->type = MESSAGE_IMAGE;
	    messageConcat(message1, message2);
		free(message1);
		free(message2);
		return 0;
}
*/

