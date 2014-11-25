#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "conversation.h"

void conversationDestory(Conversation conversation) {
	if(conversation == NULL) {
		return;
	}
	for(int i = 0 ; i < currLenMessages; i++) {
		//messageDestroy(conversation->messages_ptr[i]);
	}
	free(conversation);
}

int main() {
	return 0;
}