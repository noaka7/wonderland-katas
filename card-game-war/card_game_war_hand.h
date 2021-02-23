#ifndef CARD_GAME_WAR_HAND_H
#define CARD_GAME_WAR_HAND_H

#include "card_game_war_deck.h"
#include <stdbool.h>

typedef struct HAND {
  CARD card[NB_CARDS];
  int nb_cards;
  int top;
  int bottom;
  char *name;
} HAND;

HAND *init_player(HAND *player, char *name);
HAND *init_heap(HAND *heap);
bool is_full(HAND hand);
bool is_empty(HAND hand);
bool add_card(HAND *hand, CARD new_card);
bool draw_card(HAND *hand, CARD *top_card);

#endif // CARD_GAME_WAR_HAND_H
