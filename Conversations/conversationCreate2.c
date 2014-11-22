//#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

Conversation conversationCreate(unsigned int maxNumOfMessages) {
	if (maxNumOfMessages <= 0) {
		return NULL;
	}
	Conversation newConversation;
	newConversation = malloc(sizeof(struct conversation_t));
	if(newConversation == NULL) {
		return NULL;
	}
	Message* messageHistory = malloc(sizeof(*messageHistory)*maxNumOfMessages);
	if(messageHistory == NULL) {
		return NULL;
	}
	newConversation->messages_ptr = messageHistory;
	newConversation->maxNumOfMessages = maxNumOfMessages;

	return newConversation;
}

int main () {
	printf("hello world");
	return 0;
}