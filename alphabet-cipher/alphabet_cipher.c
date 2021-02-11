#include "alphabet_cipher.h"
#include <stdlib.h>
#include <string.h>

static char decode_letter(char, char);
static char encode_letter(char, char);

int decode_message(char *keywd, char *msg, char *dest) {
  char key, letter;
  int keywdlen = strlen(keywd);
  int msglen = strlen(msg);
  int i, j = 0;
  for (i = 0; i < msglen; i++) {
    letter = msg[i];
    key = keywd[j];
    dest[i] = decode_letter(key, letter);
    j = (j + 1) % keywdlen;
  }
  return i;
}

int decipher_message(char *keywd, char *msg, char *dest) {
  char letter_1, letter_2;
  int msglen = strlen(msg);
  int destlen = strlen(dest);
  char *buf = (char *)calloc(msglen, sizeof(char));
  memset(keywd, 0, msglen);

  int i;
  for (i = 0; i < msglen; i++) {
    letter_1 = msg[i];
    letter_2 = dest[i];
    keywd[i] = decode_letter(letter_1, letter_2);

    encode_message(keywd, msg, buf);
    if (0 == strcmp(buf, dest)) {
      break;
    }
  }

  free(buf);

  return i;
}

int encode_message(char *keywd, char *msg, char *dest) {
  char key, letter;
  int keywdlen = strlen(keywd);
  int msglen = strlen(msg);
  int i, j = 0;
  for (i = 0; i < msglen; i++) {
    letter = msg[i];
    key = keywd[j];
    dest[i] = encode_letter(key, letter);
    j = (j + 1) % keywdlen;
  }
  return i;
}

/*** STATIC FUNC ***/

static char decode_letter(char key, char letter) {
  int offset = letter - key;
  int nb_letters = 'z' - 'a' + 1;
  int positive_remainder = (offset % nb_letters + nb_letters) % nb_letters;
  return 'a' + positive_remainder;
}

static char encode_letter(char key, char letter) {
  int key_offset = key - 'a';
  int letter_offset = letter - 'a';
  return 'a' + (key_offset + letter_offset) % ('z' - 'a' + 1);
}
