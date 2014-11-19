#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int messageLength(cont Message message) {
// 	size_t strlen (char *str) {
//     size_t len = 0;
//     while (*str != '\0') {
//         str++;
//         len++;
//     }
//     return len;
// }
	if(message == NULL || message->type == MESSAGE_IMAGE) {
		return -1;
	}
	
	int textLength = 0;
	textLength = strlen(message->content.text);
	return textLength;
}



int main() {
	return 0;
}