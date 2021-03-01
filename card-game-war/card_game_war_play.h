#ifndef CARD_GAME_WAR_H
#define CARD_GAME_WAR_H

#include "card_game_war_hand.h"

#define DEAL_NB_CARDS 16
#define ENABLE_MAX_ROUND 1
#define MAX_ROUND 1000

void init_game(HAND *player1, HAND *player2);
int play_round(HAND *player1, HAND *player2);
int play_game(HAND *player1, HAND *player2);

#endif // CARD_GAME_WAR_H
