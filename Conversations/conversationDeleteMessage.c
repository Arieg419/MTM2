#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

void shiftArrayLeft(Conversation conversation, int indexToShiftFrom) {
	int maxNumOfMessages = 0;
	// numOfMessagesToShift = currLenMessages - indexToShiftFrom;
	for(int i = indexToShiftFrom ; i < currLenMessages - 1 ; i++) {
		conversation->messages_ptr[i] = conversation->messages_ptr[i+1];
	}
	conversation->messages_ptr[currLenMessages] = NULL;
}



ConversationResult conversationDeleteMessage(Conversation conversation, int userID, int index) {
	if(conversation == NULL) {
		return CONVERSATION_NULL_ARGUMENT;
	}
	int currentMsgCounter = 0;
	for(int i = 0 ; i < conversation->currLenMessages ; i++) {
		if(conversation->messages_ptr[i]->senderID == userID) {
			currentMsgCounter++;
		}
		if(currentMsgCounter == index) {
			messageDestroy(conversations->messages_ptr[i]);
			shiftArrayLeft(i);
			conversation->currLenMessages -= 1;
			return CONVERSATION_SUCCESS;
		}
	}
	if(currentMsgCounter == 0) {
		return CONVERSATION_BAD_ID;
	} 
	return CONVERSATION_OUT_BOUNDS;
}



int main() {
	return 0;
}