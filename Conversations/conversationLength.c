#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

int conversationLength(const Conversation conversation) {
	if(conversation == NULL) {
		return -1;
	}
	return conversation->currLenMessages;
}


int main() {
	return 0;
}