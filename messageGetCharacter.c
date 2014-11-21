

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "message.h"
#include <string.h>

bool isIndexLegal (char *text, int index, char* outValue) {
int i = 0 ;
while(text[i] != '\n' && (text[i]) ) {
if (i == index){
*outValue = text[i];
return true;
}
i++;
}
return false;
}



MessageResult messageGetCharacter(const Message message, int line, int index, char* outValue) {
if (message == NULL) {
return MESSAGE_NULL_ARGUMENT;
}
if(message->type == MESSAGE_IMAGE) {
return MESSAGE_WRONG_TYPE;
}

int numberOfLinesCounter = 0;
int i = 0;
int currentLineCounter = 0;
bool resultFlag;

numberOfLinesCounter = messageNumberOfLines(message);
if (line > numberOfLinesCounter) {
return MESSAGE_OUT_OF_BOUNDS;
}
while(message->content.text[i]) {
if(message->content.text[i] == '\n') {
currentLineCounter ++;
}
i++;
if(currentLineCounter == line) {
    resultFlag = isIndexLegal(&(message->content.text[i]), index, outValue);
    break;
 }
}




if (!resultFlag) {
return MESSAGE_OUT_OF_BOUNDS;
} else {
return MESSAGE_SUCCESS;
}
}

/*
int main() {
char outValue;
Message message1 = malloc(sizeof(struct message_t));
char *string = "abcde\nfgpi\njklmn";
message1->content.text = string;
message1->type = MESSAGE_TEXT;
messageGetCharacter(message1,1,3,&outValue);
printf("%c", outValue);
free(message1);
return 0;
}
*/

