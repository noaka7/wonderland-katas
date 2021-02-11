#include "alphabet_cipher.h"
#include "minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tests_run = 0;

static char *test_encode() {
  puts("testing: can encode a message with a secret keyword");

  char *keyword;
  char *message;
  char *encoded_message;
  char *test_message;

  test_message = "hmkbxebpxpmyllyrxiiqtoltfgzzv";
  keyword = "vigilance";
  message = "meetmeontuesdayeveningatseven";
  encoded_message = (char *)malloc(strlen(message) * sizeof(char));
  encode_message(keyword, message, encoded_message);
  mu_assert("error cannot encode", 0 == strcmp(test_message, encoded_message));
  free(encoded_message);

  test_message = "egsgqwtahuiljgs";
  keyword = "scones";
  message = "meetmebythetree";
  encoded_message = (char *)malloc(strlen(message) * sizeof(char));
  encode_message(keyword, message, encoded_message);
  mu_assert("error cannot encode", 0 == strcmp(test_message, encoded_message));
  free(encoded_message);

  return 0;
}

static char *test_decode() {
  puts("testing: can decode a message given an encoded message and a secret "
       "keyword");

  char *keyword;
  char *message;
  char *decoded_message;
  char *test_message;

  test_message = "meetmeontuesdayeveningatseven";
  keyword = "vigilance";
  message = "hmkbxebpxpmyllyrxiiqtoltfgzzv";
  decoded_message = (char *)malloc(strlen(message) * sizeof(char));
  decode_message(keyword, message, decoded_message);
  mu_assert("error cannot decode", 0 == strcmp(test_message, decoded_message));
  free(decoded_message);

  test_message = "meetmebythetree";
  keyword = "scones";
  message = "egsgqwtahuiljgs";
  decoded_message = (char *)malloc(strlen(message) * sizeof(char));
  decode_message(keyword, message, decoded_message);
  mu_assert("error cannot decode", 0 == strcmp(test_message, decoded_message));
  free(decoded_message);

  return 0;
}

static char *test_decipher() {
  puts("testing: can extract the secret keyword given an encrypted message and "
       "the original message");

  char *keyword;
  char *message;
  char *encoded_message;
  char *test_keyword;

  test_keyword = "vigilance";
  message = "thequickbrownfoxjumpsoveralazydog";
  encoded_message = "opkyfipmfmwcvqoklyhxywgeecpvhelzg";
  keyword = (char *)malloc(strlen(message) * sizeof(char));
  decipher_message(keyword, message, encoded_message);
  mu_assert("error cannot decipher", 0 == strcmp(test_keyword, keyword));
  free(keyword);

  test_keyword = "scones";
  message = "packmyboxwithfivedozenliquorjugs";
  encoded_message = "hcqxqqtqljmlzhwiivgbsapaiwcenmyu";
  keyword = (char *)malloc(strlen(message) * sizeof(char));
  decipher_message(keyword, message, encoded_message);
  mu_assert("error cannot decipher", 0 == strcmp(test_keyword, keyword));
  free(keyword);

  test_keyword = "abcabcx";
  message = "hellofromrussia";
  encoded_message = "hfnlphoontutufa";
  keyword = (char *)malloc(strlen(message) * sizeof(char));
  decipher_message(keyword, message, encoded_message);
  mu_assert("error cannot decipher", 0 == strcmp(test_keyword, keyword));
  free(keyword);

  return 0;
}

static char *all_tests() {
  mu_run_test(test_encode);
  mu_run_test(test_decode);
  mu_run_test(test_decipher);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
