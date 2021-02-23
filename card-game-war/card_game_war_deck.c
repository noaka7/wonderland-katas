#include "card_game_war_deck.h"
#include <stdlib.h>
#include <time.h>

static CARD _card[NB_CARDS];

inline CARD get_card(int i) { return _card[i % NB_CARDS]; }

int init_deck() {
  int i;
  for (i = 0; i < NB_CARDS; i++) {
    _card[i].suit = i / NB_RANKS;
    _card[i].rank = i % NB_RANKS;
  }
  return i;
}

static void swap_cards(CARD *card_a, CARD *card_b) {
  CARD tmp = {card_a->suit, card_a->rank};
  card_a->suit = card_b->suit;
  card_a->rank = card_b->rank;
  card_b->suit = tmp.suit;
  card_b->rank = tmp.rank;
}

int shuffle_deck() {
  int i, j;
  time_t t;

  srand((unsigned)time(&t));

  for (i = 0; i < NB_CARDS; i++) {
    j = rand() % NB_CARDS;
    swap_cards(_card + i, _card + j);
  }

  return i;
}

int compare_cards(CARD card_a, CARD card_b) {
  if (card_a.rank == card_b.rank) {
    return 0;
  } else if (card_a.rank > card_b.rank) {
    return 1;
  } else if (card_a.rank < card_b.rank) {
    return 2;
  }
}
