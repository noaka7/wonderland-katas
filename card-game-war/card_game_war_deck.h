#ifndef CARD_GAME_WAR_DECK_H
#define CARD_GAME_WAR_DECK_H

typedef enum SUIT { CLUBS, DIAMONDS, HEARTS, SPADES, NB_SUITS } SUIT;

typedef enum RANK {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE,
  NB_RANKS
} RANK;

typedef struct CARD {
  SUIT suit;
  RANK rank;
} CARD;

#define NB_CARDS (NB_SUITS * NB_RANKS)

CARD get_card(int index);

int init_deck();
int shuffle_deck();
int compare_cards(CARD card_a, CARD card_b);

#endif // CARD_GAME_WAR_DECK_H
