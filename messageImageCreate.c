
#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool dimensionCheckIsTrue (unsigned height, unsigned width) {
	if ((height <= 0 || width <= 0)  ) {
		return true;
	} else {
		return false;
	}
}

char** imageCopy (char **data, char** copiedImage, unsigned height, unsigned width) {
	int i = 0, j = 0;
	for (i = 0 ; i < height ; i++) {
		for(j = 0; j < width ; j++) {
			copiedImage[i][j] = data[i][j];
		}
	}
	return copiedImage;
}

Message messageImageCreate( int senderID, char** image,
		unsigned width, unsigned height){
	if (image == NULL || !(dimensionCheckIsTrue(height, width))) {
		return NULL;
	}
	Message newImageMessage = malloc(sizeof(struct message_t));
	if (newImageMessage == NULL) return NULL;
	char **matrixToBeSent = malloc(sizeof(char)*height*width);
	if(matrixToBeSent == NULL) {
		return NULL;
	}

	newImageMessage->content.image.data = imageCopy(image, matrixToBeSent, height, width);  //why is this not working?

	// Finished checking all Input, Now creating new Image
	newImageMessage->senderID = senderID;
	newImageMessage->content.image.height = height;
	newImageMessage->content.image.width = width;
	newImageMessage->type = MESSAGE_IMAGE;

	return newImageMessage;
}

/*

 /*
        int main () {
	    int ID = 302365697;
		printf("this is broke");
		Message message1;
		int height = 2;
		int width = 2;
		char image[2][2] = {{1,2},{3,4}};
		message1 = messageImageCreate(ID, image, width, height);
		printf("sender%d:\n", message1->senderID);
		//printf("string:%s", message1->content.text);
		for(int i = 0 ; i < height ; i++) {
			for(int j = 0 ; j < width ; j++) {
				printf("This is the array number %d\n", image[i][j]);
			}
		}
		return 0;
}


*/
/*
} * messageImageCreate.c
 *
 *  Created on: Nov 20, 2014
 *      Author: omer
 */



