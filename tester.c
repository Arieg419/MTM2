#include "aux_macros.h"
#include <assert.h>
#include <stdlib.h>
#include "conversation.h"
#include <stdbool.h>

#define TEST_RESULT_IS(flag, funcToRun(), result) if((funcToRun) != result) {
	flag = false;
}

int main() {
	//Run test script here
	return 0;
}

if(!flag) {
	printf("uh oh\n");
}
//!!!!!!!!!!!!!!!!!!!!!! 
// ALLOCATE NEw IMAGE FUNC HERE
//!!!!!!!!!!!!!!!!!!!!!!!

bool conversationTest() {

ConversationResult convoResult;

Conversation convo1 = conversationCreate(5);
Conversation convo2  = conversationCopy(convo1);

Message textMsg1 = messageTextCreate(302365697, "hahahaha");
Message textMsg2 = messageTextCreate(132424, "this is it");
Message textMsg3 = messageTextCreate(132424, "");
Message textMsg4 = messageTextCreate(302365697, "YOLO");

//Message imgMsg = messageImageCreate()
//Message imgMsg = messageImageCreate()

//!!!!!!!!!!!!! This is needed in order to run tests
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CONVERSATION ADD MESSAGE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg1), CONVERSATION_SUCCESS)
TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg2), CONVERSATION_SUCCESS)
TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg3), CONVERSATION_SUCCESS)
TEST_RESULT_IS(flag, conversationAddMessage(convo1, textMsg4), CONVERSATION_SUCCESS)
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NUMBER OF USERS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TEST_RESULT_IS(flag, conversationNumberOfUsers(NULL), -1)
TEST_RESULT_IS(flag, conversationNumberOfUsers(convo1), 2)
// TEST_RESULT_IS(flag, conversationNumberOfUsers(convo2), 2345)
TEST_RESULT_IS(flag, conversationNumberOfUsers(convo2), 0) //why zero, check func signatrue
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MOST TEXT MESSAGES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int outSenderID;
TEST_RESULT_IS(flag,conversationMostTextMessages(convo2, &outSenderID), CONVERSATION_NO_MESSAGES)//convo fail or something
//!!!!!!!!!!!!!!!!!!!!!!!!!!!! MUST ADD IMAGE CREATER FUNC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//TEST_RESULT_IS(flag, conversationMostImages(convo1, &outSenderID), CONVERSATION_SUCCESS)
Message messageOutput = NULL;
TEST_RESULT_IS(flag, conversationLastMessage(convo1, 302365697, &messageOutput), CONVERSATION_SUCCESS)
bool isIdentical;
TEST_RESULT_IS(flag, messageCompare(messageOutput, textMsg4, &isIdentical), MESSAGE_SUCCESS)//not sure about this
TEST_RESULT_IS(flag, conversationDeleteMessage(convo1, 302365697, 1), CONVERSATION_SUCCESS)
TEST_RESULT_IS(flag, conversationDeleteMessage(convo1, 302365697, 0), CONVERSATION_SUCCESS)
TEST_RESULT_IS(flag, conversationLength(convo1), 2)// check out what goes here
messageDestroy(textMsg1);
messageDestroy(textMsg2);
messageDestroy(textMsg3);
messageDestroy(textMsg4);
//delete here two messageImages
//delete an additonal mesage Image deltere thing
conversationDestroy(conv1);
conversationDestroy(conv2);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CONVO CREATE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! there were braces here
		Conversation convoToCheck = conversationCreate(10);

		int outPutUserID;
		TEST_RESULT_IS(flag, conversationMostTextMessages(convoToCheck, &outPutUserID), CONVERSATION_NO_MESSAGES)
		//no messages added here yet
		Message messageToCheck1 = messageTextCreate(419, "this is strictly for test purposes");
		Message messageToCheck2 = messageTextCreate(228, "this is for fun");
		Message messageToCheck3 = messageTextCreate(330, "LMAO");

		TEST_RESULT_IS(flag, conversationMostTextMessages(convoToCheck, &outPutUserID), CONVERSATION_NO_MESSAGES)

		convoResult = conversationAddMessage(convoToCheck, messageToCheck1);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck1);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck3);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck1);

		TEST_RESULT_IS(flag, conversationMostTextMessages(convoToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		
		convoResult = conversationAddMessage(convoToCheck, messageToCheck1);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);

		TEST_RESULT_IS(flag, conversationMostTextMessages(convoToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		TEST_RESULT_IS(flag, outPutUserID, 419) //id of most pop user

		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);
		convoResult = conversationAddMessage(convoToCheck, messageToCheck2);


		TEST_RESULT_IS(flag, conversationMostTextMessages(convoToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		TEST_RESULT_IS(flag, outPutUserID, 228)
		//this should change now

		messageDestroy(messageToCheck1);
		messageDestroy(messageToCheck2);
		messageDestroy(messageToCheck3);

		conversationDestroy(convoToCheck);
	


//////////////////////////////////////////////////////////////////////////
	// conversationMostImages

	TEST_RESULT_IS(flag, conversationMostImages(NULL, &outPutUserID), CONVERSATION_NULL_ARGUMENT)

	{
		int resultUserID;
		Conversation conversationToCheck = conversationCreate(10);

		int outPutUserID;
		TEST_RESULT_IS(flag, conversationMostImages(conversationToCheck, &outPutUserID), CONVERSATION_NO_MESSAGES)

		result = conversationAddMessage(conversationToCheck, txt101);
		TEST_RESULT_IS(flag, conversationMostImages(conversationToCheck, &outPutUserID), CONVERSATION_NO_MESSAGES)


		// GENERATE AN IMAGE MESSAGE HERE
		// Message imgMsgToCheck = generateImageMessage(10, 20, false, 1, 0);// 
		// Message imgMsgToCheck = generateImageMessage(10, 20, false, 2, 0);



		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);

		TEST_RESULT_IS(flag, conversationMostImages(conversationToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		TEST_RESULT_IS(flag, outPutUserID, 1)
		
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);

		TEST_RESULT_IS(flag, conversationMostImages(conversationToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		TEST_RESULT_IS(flag, outPutUserID, 2)

		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);

		TEST_RESULT_IS(flag, conversationMostImages(conversationToCheck, &outPutUserID), CONVERSATION_SUCCESS)
		TEST_RESULT_IS(flag, outPutUserID, 1)

		messageDestroy(imgMsgToCheck);
		messageDestroy(imgMsgToCheck);

		conversationDestroy(conversationToCheck);
	}

	//////////////////////////////////////////////////////////////////////////
	// conversationLastMessage

	Message msgResult;
	TEST_RESULT_IS(flag, conversationLastMessage(NULL, 2000, &msgResult), CONVERSATION_NULL_ARGUMENT)
	TEST_RESULT_IS(flag, conversationLastMessage(convLarge, 1999, &msgResult), CONVERSATION_BAD_ID)
	TEST_RESULT_IS(flag, conversationLastMessage(convLarge, -1, &msgResult), CONVERSATION_BAD_ID)
	
	{
		Conversation conversationToCheck = conversationCreate(10);

		result = conversationAddMessage(conversationToCheck, img102);

		Message imgMsgToCheck = messageTextCreate(1, "user1");
		Message imgMsgToCheck1 = messageTextCreate(2, "user2msg1");
		Message imgMsgToCheck2 = messageTextCreate(2, "user2msg2");
		Message randomMessage;

		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck1);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck2);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck1);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck2);
		result = conversationAddMessage(conversationToCheck, imgMsgToCheck);

		{
			Conversation conversationToCheck2 = ConversationCopy(conversationToCheck);

			result = conversationLastMessage(conversationToCheck2, 2, &randomMessage);
			TEST_RESULT_IS(flag, result, CONVERSATION_SUCCESS)

			bool isIdentical = false;
			messageCompare(randomMessage, imgMsgToCheck2, &isIdentical);
			TEST_RESULT_IS(flag, isIdentical, true)

			messageDestroy(randomMessage);

			conversationDeleteMessage(conversationToCheck2, 2, 3);
			
			result = conversationLastMessage(conversationToCheck2, 2, &randomMessage);
			TEST_RESULT_IS(flag, result, CONVERSATION_SUCCESS)

			isIdentical = false;
			messageCompare(randomMessage, imgMsgToCheck1, &isIdentical);
			TEST_RESULT_IS(flag, isIdentical, true)
				
			messageDestroy(randomMessage);

			conversationDestroy(conversationToCheck2);
		}

		result = conversationLastMessage(conversationToCheck, 2, &randomMessage);
		TEST_RESULT_IS(flag, result, CONVERSATION_SUCCESS)

		conversationDestroy(conversationToCheck);

		bool isIdentical = false;
		messageCompare(randomMessage, imgMsgToCheck2, &isIdentical);
		TEST_RESULT_IS(flag, isIdentical, true)

		messageDestroy(randomMessage);

		result = conversationLastMessage(convSmall, 101, &randomMessage);
		TEST_RESULT_IS(flag, result, CONVERSATION_SUCCESS)
			
		isIdentical = false;
		messageCompare(randomMessage, img101, &isIdentical);
		TEST_RESULT_IS(flag, isIdentical, true)

		messageDestroy(imgMsgToCheck);
		messageDestroy(imgMsgToCheck1);
		messageDestroy(imgMsgToCheck2);
		messageDestroy(randomMessage);
	}

return flag;
}

