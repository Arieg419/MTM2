#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool indexNotNegative (unsigned row, unsigned column) {
	if (row < 0 || column < 0) {
		return false;
	} else {
		return true;
	}
}

bool isIndexLegal (unsigned row, unsigned column, int maxMatrixRow, int maxMatrixHeight) {
	if ( (row + 1 > maxMatrixRow) || (column + 1 > maxMatrixHeight) ) {
		return false;
	} else {
		return true;
	}
}

MessageResult messageGetColor(const Message message, unsigned row, unsigned column, unsigned char* outColor) {
	if(message == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message->type == MESSAGE_TEXT) {
		return MESSAGE_WRONG_TYPE;
	}
	
	int maxLegalHeight = message->content.image.height;
	int maxLegalWidth  = message->content.image.width;

	if ( (!indexNotNegative(row, column)) || (!isIndexLegal(row,column,maxLegalHeight, maxLegalWidth)) ) {
		return MESSAGE_OUT_BOUNDS;
	}

	*outColor = message->content.image.data[row][column];

	return MESSAGE_SUCCESS;
}



int main() {
	return 0;
}