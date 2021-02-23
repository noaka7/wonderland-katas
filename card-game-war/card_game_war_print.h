#ifndef CARD_GAME_WAR_PRINT_H
#define CARD_GAME_WAR_PRINT_H

#include "card_game_war_deck.h"
#include "card_game_war_hand.h"

void print_card(CARD card);
void print_deck();

/**
* @brief Print hand of heap
*
* @param heap Heap
*/

void print_heap(HAND heap);

/**
* @brief Print hand of player
*
* @param player Player
*/

void print_player(HAND player);

/**
* @brief Print round numero
*
* @param roundn Numero of round
*/

void print_roundn(int roundn);

/**
* @brief Print draw game result
*/

void print_draw();
void print_winner(HAND player);

#endif // CARD_GAME_WAR_PRINT_H
