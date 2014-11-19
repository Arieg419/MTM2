#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool dimensionCheckIsTrue (unsigned height, unsigned width) {
	if (height > 0 && width > 0) {
		return true;
	} else {
		return false;
	}
}

void imageCopy (char **data, char **copiedImage, unsigned height, unsigned width) {
	int i = 0, j = 0;
	for (i = 0 ; i < width ; i++) {
		for(j = 0; j < height ; j++) {
			copiedImage[i][j] = data[i][j];
		}
	}
}

Message messageImageCreate( int senderID, const unsigned char* const* image,
		unsigned width, unsigned height){
	if (image == NULL || !(dimensionCheckIsTrue(height, width))) {
		return NULL;
	}
	Message newImageMessage = (Message) malloc(sizeof(Message));
	if (newImageMessage == NULL) return NULL;
	imageCopy(image->data, newImageMessage->content.image, height, width);  //why is this not working?
	
	// Finished checking all Input, Now creating new Image
	newImageMessage->senderID = senderID;
	newImageMessage->content.image.height = height;
	newImageMessage->content.image.width = width;
	newImageMessage->type = MESSAGE_IMAGE;
	
	return newImageMessage;
}

int main () {
	Message mainMessage;
	int senderID = 302365697, i = 0, j = 0;
	const unsigned char* const* image;
	image->height = 4;
	image->width = 4;
	for (i = 0 ; i < width ; i++ ) {
		for(j = 0 ; j < height; j++) {
			image->data[i][j] = 1;
		}
	}
	
	mainMessage = messageImageCreate(senderID, image, width, height);
	
	printf("%d\n", mainMessage->senderID);
}