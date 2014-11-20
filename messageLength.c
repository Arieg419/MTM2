/*
 * messageLength.c
 *
 *  Created on: Nov 20, 2014
 *      Author: omer
 */


#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int messageLength(const Message message) {
	if(message == NULL || message->type == MESSAGE_IMAGE) {
		return -1;
	}

	int textLength = 0;
	textLength = strlen(message->content.text);
	return textLength;
}



int main() {
	int messageLengthReturn;
	Message message1 = malloc(sizeof(struct message_t));
	char *string = "yele";
	message1->content.text = string;
	message1->type = MESSAGE_TEXT;
	messageLengthReturn = messageLength(message1);
	printf("%d", messageLengthReturn);
	return 0;
}
