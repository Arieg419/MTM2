#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

MessageResult messageCompare(const Message message1, const Message message2, bool* outIdentical) {
	if (message1 == NULL || message2 == NULL) {
		*outIdentical = false;
		return MESSAGE_NULL_ARGUMENT;
	}
	if(message1->senderID != message2->senderID) {
		*outIdentical = false;
		return MESSAGE_DIFFERENT_SENDER;
		//what am i supposed toreturn in this case
	}
	if(message1->type != message2->type) {
		*outIdentical = false;
		return MESSAGE_WRONG_TYPE;
	}

	int message1MatrixHeight;
	int message2MatrixHeight;
	int message1MatrixWidth;
	int message2MatrixWidth;

	int strCompareValue = 0;
	if(message1->type == MESSAGE_TEXT) {
		strCompareValue = strcmp(message1->content.text, message2->content.text);
		if (strCompareValue == 0) {
			*outIdentical = true;
			printf("here!");
			return MESSAGE_SUCCESS;
		} else {
			printf("bad here");
			*outIdentical = false;
			return MESSAGE_WRONG_TYPE; //what m i supposed to put here?
			// something from the enum array ??
		}
	}

	else  {
		message1MatrixHeight = message1->content.image.height;
		message2MatrixHeight = message2->content.image.height;
		message1MatrixWidth = message1->content.image.width;
		message2MatrixWidth = message2->content.image.width;

		if ((message1MatrixWidth != message2MatrixWidth) || (message1MatrixHeight != message2MatrixHeight)) {
			*outIdentical = false;
			return MESSAGE_WRONG_TYPE;
		}

		for (int i = 0 ; i < message1MatrixHeight ; i++) {
			for(int j = 0 ; j < message1MatrixWidth ; j++) {
				if (message1->content.image.data[i][j] != message2->content.image.data[i][j]) {
					*outIdentical = false;
					return MESSAGE_WRONG_TYPE;
				}
			}
		}

		*outIdentical = true;
	}
	return MESSAGE_SUCCESS;
}

int main() {
	int ID = 302365697;
	bool outIdentical;
	Message message1;
	message1 = malloc(sizeof(struct message_t));
	Message message2;
	message2 = malloc(sizeof(struct message_t));
	message1->senderID = ID;
	message2->senderID = ID;
	message1->type  = MESSAGE_TEXT;
	message2->type = MESSAGE_TEXT;
	message1->content.text = "heythisOmerNela";
	message2->content.text = "heythisOmerNela";
	messageCompare(message1, message2, &outIdentical);

	return 0;
}
