#include "card_game_war_hand.h"

HAND *init_player(HAND *player, char *name) {
  player->nb_cards = 0;
  player->top = 0;
  player->bottom = 0;
  player->name = name;
  return player;
}

HAND *init_heap(HAND *heap) {
  heap->nb_cards = 0;
  heap->top = 0;
  heap->bottom = 0;
  return heap;
}

inline bool is_full(HAND hand) { return NB_CARDS <= hand.nb_cards; }

inline bool is_empty(HAND hand) { return 0 >= hand.nb_cards; }

bool add_card(HAND *hand, CARD new_card) {
  if (is_full(*hand)) {
    return false;
  }
  hand->card[hand->bottom] = new_card;
  hand->bottom = (hand->bottom + 1) % NB_CARDS;
  hand->nb_cards++;
  return true;
}

bool draw_card(HAND *hand, CARD *top_card) {
  if (is_empty(*hand)) {
    return false;
  }
  *top_card = hand->card[hand->top];
  hand->top = (hand->top + 1) % NB_CARDS;
  hand->nb_cards--;
  return true;
}
