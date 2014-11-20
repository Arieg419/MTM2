#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

MessageResult messageGetType(const Message message, MessageType* outType) {
	if(message == NULL) {
		return MESSAGE_NULL_ARGUMENT;
	} else  {
		*outType = message->type;
		return MESSAGE_SUCCESS;
	}
}

int main() {
	return 0;
}