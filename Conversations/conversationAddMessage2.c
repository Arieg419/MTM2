#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

int isConversationFull(Conversation conversation) {
	int i = 0;
	while(conversation->messages_ptr[i]) {
		i++;
	}
	if (i >= conversation->maxNumOfMessages) {
		return -1;
	} else  {
		return i;
	}
}


Conversation conversationAddMessage(Conversation conversation, Message message) {
	if(message == NULL || conversation == NULL) {
		return CONVERSATION_NULL_ARGUMENT;
	}
	int currentIndex = 0;
	currentIndex = isConversationFull(conversation);
	if(currentIndex == -1) {
		return CONVERSATION_FULL;
	}
	Message newMessage;
	if(message->type  == MESSAGE_TEXT) {
		newMessage = messageTextCreate(message->senderID, message->content.text);
	} else {
		//newMessage = messageImageCreate(message);
	} 
	conversation->messages[currentIndex] = newMessage;
	return 	CONVERSATION_SUCCESS;
}



int main() {
	Conversation newConversation;
	newConversation = malloc(sizeof(struct conversation_t));
	newConversation = conversationCreate(3);
	Message newMessage;
	char *random = "abcdegf"
	newMessage = messageTextCreate(302365697, random);
	conversationAddMessage(newConversation, newMessage);
	printf("%s\n", newConversation->messages_ptr[0]->content.text);
	printf("%s\n", newConversation->messages_ptr[0]->senderID);
	return 0;
}