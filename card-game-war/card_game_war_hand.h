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

/**
* @brief Initialize player
*
* @param player Player
* @param name Name for player
* @return Pointer to player
*/

HAND *init_player(HAND *player, char *name);

/**
* @brief Initialize heap
*
* @param heap Heap
* @return Pointer to heap
*/

HAND *init_heap(HAND *heap);

/**
* @brief Check if hand is full
*
* @param hand Hand
* @return
*   false Hand is not full
*   true Hand is full
*/

bool is_full(HAND hand);

/**
* @brief Check if hand is empty
*
* @param hand Hand
* @return
*   false Hand is not empty
*   true Hand is empty
*/

bool is_empty(HAND hand);

/**
* @brief Add a card to bottom of hand
*
* @param hand Hand
* @param new_card New card
* @return
*   false Failure (hand is full)
*   true Success
*/

bool add_card(HAND *hand, CARD new_card);

/**
* @brief Draw a card from top of hand
*
* @param hand Hand
* @param top_card Placeholder
* @return
*   false Failure (hand is empty)
*   true Success
*/

bool draw_card(HAND *hand, CARD *top_card);

#endif // CARD_GAME_WAR_HAND_H
