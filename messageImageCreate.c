#include "message.h"

bool imageCheckisTrue (const unsigned char* const* image) {
	if (image == NULL) {
		return false;
	} else {
		return true;
	}
}

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
	Message newImageMessage = (Message) malloc(sizeof(Message));
	if (newImageMessage == NULL) return NULL;
	if (dimensionCheckIsTrue(image->height, image->width)) {
		if (imageCheckisTrue(image)) {
			image copiedImage = (image)malloc(sizeof(image));
			if (copiedImage == NULL) {
				return NULL;
			} else {
				imageCopy(image->data, copiedImage->data, image->height, image->width);
			}
			// copiedImage = image;
			// newImageMessage->image = image;
		} else {
			return NULL;
		}
	} else  {
		return NULL;
	}
	// Finished checking all Input, Now creating new Image
	newImageMessage->senderID = senderID;
	copiedImage->height = image->height;
	copiedImage->width = width->width;
	newImageMessage->content = copiedImage;
	newImageMessage->MessageType = MessageType[1];
	
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