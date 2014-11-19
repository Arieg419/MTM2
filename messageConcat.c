#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

MessageResult messageConcat(Message message1, const Message message2) {
	if(message1 == NULL || message2 == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message1->content.type == MESSAGE_IMAGE || message2->content.type == MESSAGE_IMAGE) {
		return MESSAGE_WRONG_TYPE;
	}
	if(message1->senderID != message2->senderID) {
		return MESSAGE_DIFFERENT_SENDER;
	}
	strcat(message1->content.text, "\n");
	strcat(message1->content.text, message2->content.text);
	return MESSAGE_SUCCESS;
}

int main() {
	return 0;
}