#ifndef _CONVERSATION_H
#define _CONVERSATION_H

#include "message.h"

/**
 * The message structure
 */
typedef struct conversation_t* Conversation;
struct conversation_t {
	// TODO: Add fields here
};

/**
 * Results and error codes
 */
typedef enum {
	CONVERSATION_SUCCESS,
	CONVERSATION_OUT_OF_MEMORY,
	CONVERSATION_NULL_ARGUMENT,
	CONVERSATION_FULL,
	CONVERSATION_BAD_ID,
	CONVERSATION_OUT_OF_BOUNDS,
	CONVERSATION_NO_MESSAGES
} ConversationResult;

/**
 * Creates a new empty conversation - the number of the messages in the
 * conversation will be limited by NumOfMessages
 *
 * @return
 * 	A new allocated conversation.
 *  In case of memory allocation failure,
 *  or if  maxNumOfMessages is 0 - returns NULL
 **/
Conversation conversationCreate( unsigned int maxNumOfMessages);

/**
 * Adds a new copy of the give message to the conversation if it is not full
 * The message will be added at the end of the conversation
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	CONVERSATION_NULL_ARGUMENT if conversation or message is NULL
 * 	CONVERSATION_FULL if there is no room for new messages
 * 	CONVERSATION_SUCCESS otherwise
 *
 */
ConversationResult conversationAddMessage(Conversation conversation,
		const Message message);

/**
 * calculates the number of distinct senderIDs in the whole conversation
 *
 * @return
 * 	-1 if conversation is NULL or in case of memory allocation failure.
 * 	The number of different users otherwise
 */
int conversationNumberOfUsers(Conversation conversation);

/**
 * calculates the senderID who wrote the highest number of text messages
 * during the conversation.
 * In case there is more than a single user with maximal number of text
 * messages, the returned ID should be of the user (with maximal number of
 * text messages) whose last text message is the earliest.
 * result should be stored in outUserID
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	CONVERSATION_NULL_ARGUMENT if conversation is NULL
 * 	CONVERSATION_NO_MESSAGES if there are no text messages
 * 	CONVERSATION_SUCCESS otherwise
 *
 */
ConversationResult conversationMostTextMessages(Conversation conversation,
		int* outUserID);

/**
 * calculates the senderID who contributed the highest number of images
 * to the conversation
 * In case there is more than a single user with maximal number of images,
 * the returned ID should be of the user (with maximal number of images)
 * whose last image is the earliest.
 * result should be stored in outUserID
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	CONVERSATION_NULL_ARGUMENT if conversation is NULL
 * 	CONVERSATION_NO_MESSAGES if there are no images
 * 	CONVERSATION_SUCCESS otherwise
 *
 */
ConversationResult conversationMostImages(Conversation conversation,
		int* outUserID);

/**
 * returns a newly allocated copy of the last message of a the user
 * whose ID is userID
 * result should be stored in outMessage
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	CONVERSATION_NULL_ARGUMENT if conversation is NULL
 * 	CONVERSATION_BAD_ID if such user does not exist
 * 	CONVERSATION_SUCCESS otherwise
 *
 */
ConversationResult conversationLastMessage(Conversation conversation,
		int userID, Message* outMessage);

/**
 * deletes a message of a specified user with a specified index.
 * The index is zero based, where message 0 is the earliest message of the user
 * in the conversation (previously deleted messages are ignored)
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	CONVERSATION_NULL_ARGUMENT if conversation is NULL
 * 	CONVERSATION_BAD_ID if such user does not exist
 * 	CONVERSATION_OUT_OF_BOUNDS if the index is greater or equal to the number
 * 	of total messages by the specified user, or negative
 * 	CONVERSATION_SUCCESS otherwise
 *
 */
ConversationResult conversationDeleteMessage(Conversation conversation,
		int userID, int index);

/**
 * returns the total number of messages currently in the conversation
 *
 * @return
 * 	-1 if conversation is NULL
 * 	The number of messages, otherwise
 *
 */
int conversationLength(const Conversation conversation);

/**
 * creates a new copy of a given conversation
 *
 * @return
 * A newly allocated copy of the original conversation
 * NULL if the conversation is NULL or in any case of memory allocation failure
 */
Conversation ConversationCopy(Conversation conversation);

// frees all memory allocated for the the given conversation
void conversationDestroy(Conversation conversation);

#endif
