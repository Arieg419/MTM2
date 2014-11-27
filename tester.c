#include "aux_macros.h"
#include <assert.h>
#include <stdlib.h>
#include "conversation.h"
#include <stdbool.h>
#include "message.h"
#include <string.h>

#define CHECK_ARG_NULL(arg, returnValue) if(!arg) { \
											return returnValue; \
										}

#define TEST_RESULT_IS(flag, funcToRun, result) if (flag && (funcToRun != result)) { \
		flag = false; \
	}

#define ARG_IS_NULL(arg, returnValue) if(!arg){ \
										return returnValue; \
										}
#define INITIALIZING_ARRAY(arg, n) 	for(int i =0; i<n; i++) { \
														arg[i] = 0; \
														}

#define RETURN_CONV_RESULT(arg, correct, returnValue) if(arg == correct) { \
														return returnValue; \
													 }


bool conversation_test_Combo();

static unsigned char** allocateImage(unsigned height, unsigned width) {
	unsigned char** array;
	array = malloc(height*sizeof(unsigned char*));
	CHECK_ARG_NULL(array, NULL)
	for(int i = 0; i < height; i ++) {
		array[i] = malloc(width*sizeof(unsigned char));
		if(array[i] == NULL) {
			for(int j=0; j<i; j++) {
				free(array[j]);
			}
			free(array);
			return NULL;
		}
	}
	return array;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
static void copyMatrixValues(const unsigned char* const* src,
		 unsigned char** dst, unsigned height, unsigned width) {
	int i, j;
	for (i = 0 ; i < height ; i++) {
		for(j = 0; j < width ; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
*/
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
static bool dimensionCheckIsTrue (unsigned height, unsigned width) {
	if ((height <= 0 || width <= 0) ) {
		return false;
	} else {
		return true;
	}
}
*/
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
static void freeOldImage(unsigned char** image, unsigned int height) {
	 if(image == NULL) {
		 return;
	 }
	for(int i = 0; i < height; i ++) {
		free(image[i]);
	}
	free(image);
}


//!!!!!!!!!!!!!!!!!! MESSAGE IMAGE CREATE !!!!!!!!!!!!!!!!!
/*
Message messageImageCreate( int senderID, const unsigned char* const* image,
		 unsigned width, unsigned height){
	if(image == NULL) {
			return NULL;
		}
	if (!(dimensionCheckIsTrue(height, width))) {
		return NULL;
	}
	Message newImageMessage = malloc(sizeof(struct message_t));
	CHECK_ARG_NULL(newImageMessage, NULL)
	unsigned char** array = allocateImage(height, width);
	if(array == NULL) {
		free(newImageMessage);
		return NULL;
	}

	copyMatrixValues(image, array, height, width);
	newImageMessage->content.image.data = array;
	newImageMessage->senderID = senderID;
	newImageMessage->content.image.height = height;
	newImageMessage->content.image.width = width;
	newImageMessage->type = MESSAGE_IMAGE;
	return newImageMessage;
}
*/
//!!!!!!!!!!!!!!!!!! MESSAGE IMAGE CREATE !!!!!!!!!!!!!!!!!!!!!!!!




int main() {
	//RUN_TEST(conversation_test_Combo)
	bool flag;
	flag = conversation_test_Combo();
	if(flag) {
		printf("SUCCESS");
	} else {
		printf("Fail");
	}

	return 0;


}


bool conversation_test_Combo() {
	bool flag = true;

	TEST_RESULT_IS(flag, conversationCreate(0), NULL)
			if(!flag){
				printf("GARDEN OF EDEN\n");
				flag = true;
			}


	Conversation convo1 = conversationCreate(6);
	Conversation convo2 = ConversationCopy(convo1);
	Message textMsg1 = messageTextCreate(302365697, "hahahaha");
	Message textMsg2 = messageTextCreate(132424, "this is it");
	Message textMsg3 = messageTextCreate(132424, "");


	unsigned char** img1 = allocateImage(2, 2);
	if(img1 == NULL) {
		return 0;
	}
	unsigned char** img2 = allocateImage(2, 2);
	if(img2 == NULL) {
		freeOldImage(img1,2);
	}

	for(int i  = 0 ; i < 2 ; i++) {
		for(int j = 0 ; j < 2; j++) {
			img1[i][j] = j;
			img2[i][j] = i;
		}
	}

	Message imgMsg1 = messageImageCreate(302365697, (const unsigned char* const*)img1,2,2);
	Message imgMsg2 = messageImageCreate(132424, (const unsigned char* const*)img2,2,2);

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg1), CONVERSATION_SUCCESS)
		if(!flag){
			printf("MATAM\n");
			flag = true;
		}
	messageDestroy(textMsg1);

	int outSenderID;
		TEST_RESULT_IS(flag,conversationMostTextMessages(convo2, &outSenderID), CONVERSATION_NO_MESSAGES)//convo fail or something
		if(!flag){
						printf("START TO FINISH\n");
						flag = true;
					}

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg2), CONVERSATION_SUCCESS)
		if(!flag){
			printf("NOW\n");
			flag = true;
		}
	TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg3), CONVERSATION_SUCCESS)
		if(!flag){
			printf("GO\n");
			flag = true;
		}

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, imgMsg1), CONVERSATION_SUCCESS)
		if(!flag){
			printf("FINISH\n");
			flag = true;
		}
	TEST_RESULT_IS(flag, conversationAddMessage(convo1, imgMsg2), CONVERSATION_SUCCESS)
	if(!flag){
			printf("HAVE\n");
			flag = true;
		}

	TEST_RESULT_IS(flag, conversationDeleteMessage(convo1, 302365697, 37), CONVERSATION_OUT_OF_BOUNDS)
			if(!flag){
				printf("CONVO IS OUT OF BOUNDS SON\n");
				flag = true;
			}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NUMBER OF USERS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	TEST_RESULT_IS(flag, conversationNumberOfUsers(NULL), -1)
	if(!flag){
				printf("A SHORT\n");
				flag = true;
			}
	TEST_RESULT_IS(flag, conversationNumberOfUsers(convo1), 2)
	if(!flag){
				printf("NAP AND REST\n");
				flag = true;
			}
	TEST_RESULT_IS(flag, conversationNumberOfUsers(convo2), 0) //why zero, check func signatrue
	if(!flag){
				printf("AND PLEASE\n");
				flag = true;
			}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MOST TEXT MESSAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//int outSenderID;
	TEST_RESULT_IS(flag,conversationMostTextMessages(convo2, &outSenderID), CONVERSATION_NO_MESSAGES)//convo fail or something
	if(!flag){
					printf("START\n");
					flag = true;
				}
	Message messageOutput = NULL;
	TEST_RESULT_IS(flag, conversationLastMessage(convo1, 302365697, &messageOutput), CONVERSATION_SUCCESS)
	if(!flag){
					printf("AGAIN\n");
					flag = true;
				}
	messageDestroy(messageOutput);

	int outUserID = 4;
		TEST_RESULT_IS(flag, conversationMostImages(convo1, &outUserID), CONVERSATION_SUCCESS)
		//printf("%d\n", outUserID);
		if(!flag){
								printf("WEEKEND YALLLLLLL\n");
								flag = true;
							}

		TEST_RESULT_IS(flag,conversationMostTextMessages(convo2, &outSenderID), CONVERSATION_NO_MESSAGES)//convo fail or something
			if(!flag){
							printf("i failed\n");
							flag = true;
						}

		TEST_RESULT_IS(flag, conversationLength(convo1), 5)// check out what goes here
			if(!flag){
								printf("WEEKEND 11\n");
								flag = true;
							}

	TEST_RESULT_IS(flag, conversationDeleteMessage(convo1, 302365697, 0), CONVERSATION_SUCCESS)
	if(!flag){
						printf("HAVE A NICE\n");
						flag = true;
					}
	TEST_RESULT_IS(flag, conversationLength(convo1), 4)// check out what goes here
	if(!flag){
						printf("WEEKEND\n");
						flag = true;
					}
	Message imgMsg3 = messageImageCreate(302365697, (const unsigned char* const*)img1,2,2);
	Message imgMsg4 = messageImageCreate(132424, (const unsigned char* const*)img2,2,2);
	Message imgMsg5 = messageImageCreate(132424, (const unsigned char* const*)img2,2,2);

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, imgMsg3), CONVERSATION_SUCCESS)
			if(!flag){
				printf("EVERYBODY WAS\n");
				flag = true;
			}

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, imgMsg4), CONVERSATION_SUCCESS)
			if(!flag){
				printf("FINISH\n");
				flag = true;
			}

	TEST_RESULT_IS(flag, conversationAddMessage(convo1, imgMsg5), CONVERSATION_FULL)
				if(!flag){
					printf("FINISH MEEEEEEE\n");
					flag = true;
				}
	freeOldImage(img1, 2);
	freeOldImage(img2,2);
	//messageDestroy(textMsg1);
	messageDestroy(textMsg2);
	messageDestroy(textMsg3);
	messageDestroy(imgMsg1);
	messageDestroy(imgMsg2);
	messageDestroy(imgMsg3);
	messageDestroy(imgMsg4);
	messageDestroy(imgMsg5);
	//something could be deleted here if i misss up
	conversationDestroy(convo1);
	conversationDestroy(convo2);

	return flag;

}
