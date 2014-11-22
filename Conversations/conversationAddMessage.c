/*
 * conversationAddMessage.c

 *
 *  Created on: Nov 21, 2014
 *      Author: omer
 */

#include "message.h"
#include "conversation.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

Conversation createNode(Message message1, Conversation messageToReturn) {
	//messageToReturn->message = "jajaj";
	messageToReturn->maxNumOfMessages = 419;
	messageToReturn->next = NULL;
	return messageToReturn;
}

int countNumberOfMessages(Conversation head) {
	int counter = 0;
	Conversation currentNode;
	for(currentNode = head ; currentNode != NULL ; currentNode = currentNode->next){
		counter++;
	}
	return counter;
}

ConversationResult conversationAddMessage(Conversation conversation, Message message) {
	if (message == NULL || conversation == NULL) {
		return CONVERSATION_NULL_ARGUMENT;
	}
	int numOfMessages = countNumberOfMessages(conversation);
	//save head at some point separately
	if(numOfMessages >= conversation->maxNumOfMessages) {
		return CONVERSATION_FULL;
	}
	Message newMessage;
	if(message->type == MESSAGE_TEXT) {
		newMessage = messageTextCreate(message->senderID, message->content.text);
	} else {
		//newMessage = messageImageCreate(message->senderID, (const unsigned char* const*) message->content.image.data, message->content.image.width, message->content.image.height);
	}
	Conversation messageToReturn;
	messageToReturn = malloc(sizeof(struct conversation_t));
	messageToReturn = createNode(newMessage, messageToReturn);
	while(conversation->next) {
		conversation = conversation->next;
	}
	conversation->next = messageToReturn;
	return CONVERSATION_SUCCESS;
}


/*
int main() {
	Conversation root;
	Conversation next;
	next = malloc(sizeof(struct conversation_t));
	root = malloc(sizeof(struct conversation_t));
	root = conversationCreate(2);
	Message message1;
	message1 = malloc(sizeof(struct message_t));
	message1->content.text = "YOLO";
	message1->type = MESSAGE_TEXT;
	message1->senderID = 302365697;
	conversationAddMessage(root, message1);
	next = root->next;
	printf("%d", next->maxNumOfMessages);
	return 0;
}
*/


