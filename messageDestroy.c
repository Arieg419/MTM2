#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void messageDestroy(Message message) {
	if (message == NULL) {
		return;
	}
	if(messsage->type == MESSAGE_TEXT) {
		free(message->content.text);
	} else  {
		//free 2 dimensional matric.. how is this done properly?
	}
	free(message);
}


int main() {
	return 0;
}