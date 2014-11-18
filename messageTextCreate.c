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
	newMessage->Content = textCopy;
	newMessage->MessageType = MessageType[0];
	
	return newMessage;
}