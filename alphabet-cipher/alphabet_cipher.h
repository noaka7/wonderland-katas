#ifndef ALPHABET_CIPHER_H
#define ALPHABET_CIPHER_H

/**
*  @brief Decode a message given an encoded message and a secret keyword
*
*  @param keywd Keyword
*  @param msg Encoded message
*  @param dest Decoded message
*  @return Number of decoded characters
*/

int decode_message(char *keywd, char *msg, char *dest);
int encode_message(char *keywd, char *msg, char *dest);

/**
*  @brief Find keyword given message and encoded message
*
*  @param keywd Keyword
*  @param msg Plaintext message
*  @param dest Encoded message
*  @return Length of keyword
*/

int decipher_message(char *keywd, char *msg, char *dest);

#endif // ALPHABET_CIPHER_H
