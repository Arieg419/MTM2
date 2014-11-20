#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>



void createNewArray(char** oldMatrix, char** newMatrix, oldMatrixHeight, oldMatrixWidth) {
	int newMatrixRowIndex = 0;
	int newMatrixColumnIndex = 0;

	for(int i = 0 ; i < oldMatrixWidth ; i++, newMatrixRowIndex++) {
		newMatrixColumnIndex = 0;
		for(int j = oldMatrixHeight - 1; j >= 0; j--, newMatrixColumnIndex++) {
			newMatrix[newMatrixRowIndex][newMatrixColumnIndex] = oldMatrix[j][i];
		}
	}
}

MessageResult messageRotateClockwise(Message message) {
	if (message == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message->type == MESSAGE_TEXT) {
		return MESSAGE_WRONG_TYPE;
	}
	int oldMatrixHeight = message->content.image.height;
	int oldMatrixWidth = message->content.image.width;
//!!!!!!!!!!!!!!MALLOC NEW MATRIX!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	char **newMatrix = (char**)malloc(sizeof(char)*(oldMatrixHeight)*(oldMatrixWidth));
	createNewArray(message->content.image.data, newMatrix, oldMatrixHeight, oldMatrixWidth);

	message->content.image.data = newMatrix;

	return MESSAGE_SUCCESS;

	//do we have to free the memory which we did malloc to?
}

int main() {
	return 0;
}