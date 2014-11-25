#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

Conversation ConversationCopy(const Conversation conversation) {
	if(conversation == NULL) {
		return NULL;
	}
	ConversationResult flag;
	Conversation copiedConversation;
	copiedConversation = conversationCreate(conversation->maxNumOfMessages);
	copiedConversation->currLenMessages = conversation->currLenMessages;
	for(int i  = 0 ; i < conversation->currLenMessages; i++) {
		flag = conversationAddMessage(copiedConversation, conversation->messages_ptr[i]);
		if(flag == CONVERSATION_NULL_ARGUMENT || flag == CONVERSATION_FULL) {
			return NULL;
		}
	}
	return copiedConversation;
}


int main() {
	return 0;
}