#include "card_game_war_deck.h"
#include "card_game_war_hand.h"
#include "card_game_war_play.h"
#include "minunit.h"
#include <stdio.h>

int tests_run = 0;

static char *test_play_round() {
  puts("testing: the highest rank wins the cards in the round");

  HAND p1, p2;
  CARD queen = {0, QUEEN}, jack = {0, JACK}, king = {0, KING}, ace = {0, ACE};

  init_player(&p1, "Player 1");
  init_player(&p2, "Player 2");
  add_card(&p1, queen);
  add_card(&p2, jack);
  mu_assert("error, queens are lower rank than jacks",
            1 == play_round(&p1, &p2));

  init_player(&p1, "Player 1");
  init_player(&p2, "Player 2");
  add_card(&p1, king);
  add_card(&p2, queen);
  mu_assert("error, kings are lower rank than queens",
            1 == play_round(&p1, &p2));

  init_player(&p1, "Player 1");
  init_player(&p2, "Player 2");
  add_card(&p1, ace);
  add_card(&p2, king);
  mu_assert("error, aces are lower rank than kings", 1 == play_round(&p1, &p2));

  return 0;
}

static char *test_play_game() {
  puts("testing: the player loses when they run out of cards");

  CARD card = {0, 0};
  int deal_nb_cards = 2;
  HAND p1, p2;

  init_player(&p1, "Player 1");
  init_player(&p2, "Player 2");
  for (int i = 0; i < deal_nb_cards; i++) {
    add_card(&p1, card);
  }
  for (int i = 0; i < (deal_nb_cards - 1); i++) {
    add_card(&p2, card);
  }

  mu_assert("error, the player does not loses when they run out of cards",
            1 == play_game(&p1, &p2));

  return 0;
}

static char *all_tests() {
  mu_run_test(test_play_round);
  mu_run_test(test_play_game);
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
