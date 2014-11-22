
#include "message.h"
#include "conversation.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>



Conversation conversationCreate(unsigned int maxNumOfMessages) {
	if(maxNumOfMessages <= 0 ) {
		return NULL;
	}
	Conversation head;
	head = malloc(sizeof(struct conversation_t));
	if(head == NULL) {
		return NULL;
	}
	//printf("%d\n", maxNumOfMessages);
	head->maxNumOfMessages = maxNumOfMessages;
	// head->content.text = NULL;
	head->next = NULL;
	return head;
}

/*
int main() {
	Conversation root;
	root = malloc(sizeof(struct conversation_t));
	root = conversationCreate(2);
	printf("shabbat shalom\n");
	printf("%d\n", root->maxNumOfMessages);
	return 0;
}
*/

