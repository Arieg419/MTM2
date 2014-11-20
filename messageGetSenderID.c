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
	return 0;
}