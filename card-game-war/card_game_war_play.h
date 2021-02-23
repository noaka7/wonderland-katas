#ifndef CARD_GAME_WAR_H
#define CARD_GAME_WAR_H

#include "card_game_war_hand.h"

#define DEAL_NB_CARDS 16
#define ENABLE_MAX_ROUND 1
#define MAX_ROUND 1000

void init_game(HAND *player1, HAND *player2);

/**
* @brief Play a round
*
* @param player1 Player 1
* @param player2 Player 2
* @return
*   -1 GAME OVER One or two players run out of cards
*    0 Draw
*    1 Player 1 wins
*    2 Player 2 wins
*/

int play_round(HAND *player1, HAND *player2);

/**
* @brief Play game
*
* @param player1 Player 1
* @param player2 Player 2
* @return
*    0 Draw
*    1 Player 1 wins
*    2 Player 2 wins
*/

int play_game(HAND *player1, HAND *player2);

#endif // CARD_GAME_WAR_H
