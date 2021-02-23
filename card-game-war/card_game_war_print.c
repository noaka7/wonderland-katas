#include "card_game_war_print.h"
#include <stdio.h>

static char *suit_to_string(SUIT suit) {
  char *str;
  switch (suit) {
  case CLUBS:
    str = "C";
    break;
  case DIAMONDS:
    str = "D";
    break;
  case HEARTS:
    str = "H";
    break;
  case SPADES:
    str = "S";
    break;
  default:
    str = "";
    break;
  }
  return str;
}

static char *rank_to_string(RANK rank) {
  char *str;
  switch (rank) {
  case TWO:
    str = "2";
    break;
  case THREE:
    str = "3";
    break;
  case FOUR:
    str = "4";
    break;
  case FIVE:
    str = "5";
    break;
  case SIX:
    str = "6";
    break;
  case SEVEN:
    str = "7";
    break;
  case EIGHT:
    str = "8";
    break;
  case NINE:
    str = "9";
    break;
  case TEN:
    str = "X";
    break;
  case JACK:
    str = "J";
    break;
  case QUEEN:
    str = "Q";
    break;
  case KING:
    str = "K";
    break;
  case ACE:
    str = "A";
    break;
  default:
    str = "";
    break;
  }
  return str;
}

static char *card_to_string(CARD card, char *buf) {
  sprintf(buf, "[%s%s]", suit_to_string(card.suit), rank_to_string(card.rank));
  return buf;
}

void print_card(CARD card) {
  char buf[100];
  printf("Card: %s\n", card_to_string(card, buf));
}

void print_deck() {
  char buf[100];
  printf("Deck: ");
  for (int i = 0; i < NB_CARDS; i++) {
    printf("%s", card_to_string(get_card(i), buf));
  }
  puts("");
}

static void print_hand(HAND player) {
  char buf[100];
  for (int i = 0; i < player.nb_cards; i++) {
    printf("%s", card_to_string(player.card[(player.top + i) % NB_CARDS], buf));
  }
  puts("");
}

void print_heap(HAND heap) {
  printf("Heap: ");
  print_hand(heap);
}

void print_player(HAND player) {
  printf("%s: ", player.name);
  print_hand(player);
}

inline void print_roundn(int numero) { printf("Round %d\n", numero); }

inline void print_draw() { puts("Draw"); }

inline void print_winner(HAND player) { printf("%s wins\n", player.name); }
