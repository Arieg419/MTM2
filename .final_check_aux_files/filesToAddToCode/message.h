#ifndef _MESSAGE_H
#define _MESSAGE_H

#include <stdbool.h>

typedef enum {MESSAGE_TEXT, MESSAGE_IMAGE} MessageType;

typedef union {
	char* text;
	struct {
		unsigned char** data;
		unsigned int width;
		unsigned int height;
	} image;
} Content;

/**
 * The message structure
 */
typedef struct message_t* Message;
struct message_t {
	int senderID;
	Content content;
	MessageType type;
};

/**
 * Results and error codes
 */
typedef enum {
	MESSAGE_SUCCESS,
	MESSAGE_OUT_OF_MEMORY,
	MESSAGE_NULL_ARGUMENT,
	MESSAGE_WRONG_TYPE,
	MESSAGE_DIFFERENT_SENDER,
	MESSAGE_OUT_OF_BOUNDS
} MessageResult;

/**
 * Creates a new message of type image:
 * image contains the content of the image, width/height are the dimensions
 *
 * @return
 * 	A new allocated message of type image
 * 	if width or height is 0 or image == NULL,
 * 	or in case of memory allocation failure - return NULL
 **/
Message messageImageCreate( int senderID, const unsigned char* const* image,
		unsigned width, unsigned height);

/**
 * Creates a new message of type text:
 * text contains the message itself, assuming the text is null terminated.
 *
 * @return
 * 	A new allocated message of type text
 * 	if text == NULL or in case of memory allocation failure -  returns NULL
 **/
Message messageTextCreate( int senderID, const char* text);

/**
 * checks whether the message is a palindrome
 * valid only for text messages
 * A message is considered a palindrome if each line in the message is a palindrome
 * result should be stored in outIsPalindrome
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is an image
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageIsPalindrome(const Message message, bool* outIsPalindrome);

/**
 * checks how many lines are in the message
 * valid only for text messages
 * lines are separated by the LF character (0x0A, \n)
 * lines may be empty
 *
 * @return
 * 	-1 if message is NULL or message is an image
 * 	the number of lines otherwise
 *
 */
int messageNumberOfLines(const Message message);

/**
 * appends the content of message2 to message1
 * valid only if both are text messages from the same sender
 * message2 left unchanged,
 * messgae1 will hold the joined text from both messages
 * (message2 will be appended at the end, starting in a new line)
 * lines are separated by the LF character (0x0A, \n)
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if one of the messages is NULL
 * 	MESSAGE_WRONG_TYPE if one of the messages is an image
 * 	MESSAGE_DIFFERENT_SENDER if the message have a different senderID
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageConcat(Message message1, const Message message2);

/**
 * checks how many characters are in the message, including lines separators,
 * not including the string termination character
 * valid only for text messages
 *
 * @return
* 	-1 if message is NULL or message is of image type
 * 	the length of the message otherwise
 *
 */
int messageLength(const Message message);

/**
 * gets the character at place index (0-based) of the given line (also 0-based)
 * valid only for text messages
 * the LF character is considered out of bounds
 * result should be stored in outValue
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is an image
 * 	MESSAGE_OUT_OF_BOUNDS if the line parameter is greater or equal the number of lines,
 * 	or the index parameters is greater of equal to the number of characters in the given line
 * 	(not including LF)
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageGetCharacter(const Message message, int line,
		int index, char* outValue);

/**
 * changes the color of every cell in the picture with the opposite colors:
 * (x <- 255 - x)
 * valid only for image messages
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is a text message
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageInvertColors(Message message);

/**
 * rotates the message clockwise by 90 degrees:
 * [1,2,3]     [4,1]
 * [4,5,6] ->  [5,2]
 *             [6,3]
 * valid only for image messages
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is a text message
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageRotateClockwise(Message message);

/**
 * rotates the message clockwise by 90 degrees:
 * [1,2,3]     [3,6]
 * [4,5,6] ->  [2,5]
 *             [1,4]
 * valid only for image messages
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is a text message
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageRotateAntiClockwise(Message message);

/**
 * gets the color of a specific cell, given by a row and columns indices  (0-based)
 * valid only for images
 * result should be stored in outColor
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if message is NULL
 * 	MESSAGE_WRONG_TYPE if message is a text message
 * 	MESSAGE_OUT_OF_BOUNDS if the row or column are greater or equal than the height and width (respectively)
 * 	MESSAGE_SUCCESS otherwise
 *
 */
MessageResult messageGetColor(const Message message, unsigned row,
		unsigned column, unsigned char* outColor);

/**
 * Checks whether two messages are identical
 * result should be stored in outIdentical
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT if one of the messages is NULL
 * 	MESSAGE_SUCCESS otherwise
 */
MessageResult messageCompare(const Message message1,
		const Message message2, bool* outIdentical);

/**
 * creates a new copy of a given message
 *
 * @return
 * A newly allocated copy of the original message
 * NULL if the message is NULL or in any case of memory allocation failure
 */
Message messageCopy(const Message message);

// frees all memory allocated for the the given message
void messageDestroy(Message message);

/**
 * gets the ID of the sender of the message
 * result should be stored in outSenderID
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT the messages is NULL
 * 	MESSAGE_SUCCESS otherwise
 */
MessageResult messageGetSenderID(const Message message, int* outSenderID);

/**
 * gets the type of the message (text or image)
 * result should be stored in outSenderID
 *
 * @return
 * 	error code implying whether the operation was successful
 * 	MESSAGE_NULL_ARGUMENT the messages is NULL
 * 	MESSAGE_SUCCESS otherwise
 */
MessageResult messageGetType(const Message message, MessageType* outType);

#endif
