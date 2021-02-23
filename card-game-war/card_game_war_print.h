#ifndef CARD_GAME_WAR_PRINT_H
#define CARD_GAME_WAR_PRINT_H

#include "card_game_war_deck.h"
#include "card_game_war_hand.h"

void print_card(CARD card);
void print_deck();
void print_heap(HAND heap);
void print_player(HAND player);
void print_roundn(int roundn);
void print_draw();
void print_winner(HAND player);

#endif // CARD_GAME_WAR_PRINT_H
