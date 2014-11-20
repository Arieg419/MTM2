

/*
 * messageTextCreate.c
 *
 *  Created on: 20 ???? 2014
 *      Author: TB
 */




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "message.h"
#include <string.h>

Message messageTextCreate (int senderID, const char* text) {
	if (text == NULL) return NULL;
	printf("hereeee");
	Message newMessage = malloc(sizeof(struct message_t));  //malloc returns pointer
	if (newMessage == NULL) return NULL;

	char* copiedText = malloc(sizeof(char)*strlen(text));
	strcpy(copiedText, text);
	newMessage->senderID = senderID;
	newMessage->content.text = copiedText;
	newMessage->type = MESSAGE_TEXT;

return newMessage;

}



int main() {
	int ID = 302365697;
	printf("this is broke");
	Message message1;
	char *string = "yellowOrange";
	printf("stop 1");
	message1 = messageTextCreate(ID, string);
	printf("Im here\n");
	printf("sender%d:\n", message1->senderID);
	printf("string:%s", message1->content.text);
	return 0;




}