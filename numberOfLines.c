/*
 * messageNumberOfLines.c
 *
 *  Created on: Nov 20, 2014
 *      Author: omer
 */


#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int messageNumberOfLines(const Message message) {
	if(message == NULL || message->type == MESSAGE_IMAGE) {
		return -1;
	}
	int i = 0;
	int lineCounter = 0;
	while(message->content.text[i]) {
		if(message->content.text[i] == '\n') {
			lineCounter++;
		}
		i++;
	}
	if(lineCounter == 0) { //this is in the case the there is only an empty string
		lineCounter = 1;
	}
	return lineCounter;
}




/*int main() {
	    int numberOfLines = 1000;
		printf("this is broke");
		Message message1 = malloc(sizeof(struct message_t));
		char *string = "";
		printf("stop 1");
		message1->senderID = 123;
		message1->type = MESSAGE_TEXT;
		message1->content.text = string;
		numberOfLines = messageNumberOfLines(message1);
		printf("sender%d:\n", message1->senderID);
		printf("string:%s\n", message1->content.text);
		printf("%d", numberOfLines);
		free(message1);
	return 0;
}
*/

