#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int messageNumberOfLines(const Message message) {
	if(message == NULL || message->content.type == image) {
		return -1;
	}
	int i = 0;
	int lineCounter = 0;
	while(message->content.text) {
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




int main() {
	return 0;
}