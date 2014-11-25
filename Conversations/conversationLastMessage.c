#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

ConversationResult conversationLastMessage(const Conversation conversation, int userID, Message* outMessage) {
	if(conversation == NULL) {
		return CONVERSATION_NULL_ARGUMENT;
	}
	Message lastMessagePtr = NULL;
	for(int i = conversation->currLenMessages - 1; i >=0 ; i-- ) {
		if(conversation->messages_ptr[i]->senderID == userID) {
			lastMessagePtr = conversation->message_ptr[i];
			break;
		}
	}
	if(lastMessagePtr == NULL) {
		return CONVERSATION_BAD_ID;
	} 
	if(lastMessagePtr->type == MESSAGE_TEXT) {
		outMessage = messageTextCreate(lastMessagePtr->senderID,lastMessagePtr->text);
	} else {
		//here we would create an image message
	}
	return CONVERSATION_SUCCESS;

}

int main() {
	return 0;
}