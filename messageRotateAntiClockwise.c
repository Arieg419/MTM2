#include "message.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


//!!!!!!!!!!!!!!!! REMEMBER TO INCLUDE FUNCTION FROM OTHER FILE !!!!!!!!!!!!!!!!!!

MessageResult messageRotateAntiClockwise(Message message) {
	MessageResult flag;
	for (int i = 0 ; i < 3 ; i++) {
	 flag = messageRotateClockwise(message);
	 if (flag != MESSAGE_SUCCESS) {
	 	return flag;
	 }
	}
	return flag; 	
}

int main() {
	return 0 ;
}