/*
 * messageGetSenderID.c

 *
 *  Created on: Nov 21, 2014
 *      Author: omer
 */

#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

MessageResult messageGetSenderID(const Message message, int* outSenderID) {
	if(message  == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	} else {
		*outSenderID = message->senderID;
		return MESSAGE_SUCCESS;
	}
}

int main() {
	int outSenderID;
	Message message1;
	message1 = malloc(sizeof(struct message_t));
	message1->senderID = 302365697;
	messageGetSenderID(message1, &outSenderID);
	printf("%d", outSenderID);
	return 0;
}


