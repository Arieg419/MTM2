#include "message.h"

Message messageTextCreate (int senderID, const char* text) {
	if (text == NULL) return NULL;
	Message newMessage = (Message)malloc(sizeof(Message));
	if (newMessage == NULL) return NULL;
	char* textCopy = (char*)malloc(sizeof(char*));
	if (textCopy == NULL); {
		return NULL; 
	} else {
		int i = 0;
		while(text) {
			textCopy[i] = text[i];
			i++;
		}
		textCopy[i] = "\0";
	}
	newMessage->senderID = senderID;
	newMessage->Content.text = textCopy;
	newMessage->type = MessageType[0];

	return newMessage;
}



/*
 * messageImageCreate.c
 *
 *  Created on: Nov 19, 2014
 *      Author: omer
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "message.h"

Message messageTextCreate (int senderID, const char* text) {
	if (text == NULL) return NULL;
	Message newMessage = malloc(sizeof(Message));
	if (newMessage == NULL) return NULL;
	int i = 0;
	while(text) {
		newMessage->content.text[i] = text[i];
		i++;
	}
	//do we have to add \o?\\0?
	newMessage->senderID = senderID;
	newMessage->type = MESSAGE_TEXT;
	return newMessage;
}

int main() {
	int ID = 302365697;
	Message message1;
	char *string = "yellowOrange";
	message1 = messageTextCreate(ID, string);
	free(message1);
	return 0;
}

