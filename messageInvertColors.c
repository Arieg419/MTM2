#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

MessageResult messageInvertColors(Message message) {
	if (message == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}

	if (message->type == MESSAGE_TEXT) {
		return MESSAGE_WRONG_TYPE;
	} 
	int  i = j = 0;
	for(i = 0 ; i < message->content.image.height ; i++) {
		for(j = 0 ; j < message->content.image.width ; j++) {
			message->content.image.data[i][j] = 255 - message->content.image.data[i][j];
		}
	}

	return MESSAGE_SUCCESS;
}



int main() {
	return 0;
}