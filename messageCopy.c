#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* stringCopy(char* originalString) {
	char* newString = (char*)malloc(sizeof(char)*(strlen(originalString)));
	if (newString == NULL) {
		return NULL;
	} else {
		strcpy(newString, originalString);
	}
	return newString;
}

char** pictureCopy(char** image, int height, int width) {
	char ** newMatrixImage = (char**)malloc(sizeof(char)*(height)*(width));
	if (newMatrixImage == NULL) {
		return NULL;
	} 
	for(int i  = 0; i < height; i ++) {
		for(int k = 0 ; j < width; j++) {
			newMatrixImage[i][j] = image[i][j];
		}
	}
	return newMatrixImage;
}


Message messageCopy(const Message message){
	if(message == NULL) {
		return NULL;
	}
	Message newMessage = malloc(sizeof(struct message_t));
	if(newMessage == NULL) {
		return NULL;
	}
	newMessage->senderID = message->senderID;
	newMessage->type = message->type;
	if(message->type == MESSAGE_TEXT) {
		newMessage->content.text = stringCopy(message->content.text);
	} else {
		newMessage->content.image.data = pictureCopy(message->content.image.data, message->content.image.height, message->content.image.width);
		newMessage->content.image.height = message->content.height;
		newMessage->content.image.width = message->content.width;
	}
	return newMessage;
}

int main() {
	return 0;
}