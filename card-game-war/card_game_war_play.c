#include "card_game_war_play.h"
#include "card_game_war_deck.h"
#include "card_game_war_print.h"
#include <stdbool.h>
#include <stddef.h>

#define GAME_OVER -1

#if ENABLE_MAX_ROUND
#define ROUNDN_SMALLER_THAN_MAX_ROUND (roundn <= MAX_ROUND)
#else
#define ROUNDN_SMALLER_THAN_MAX_ROUND 1
#endif // ENABLE_MAX_ROUND

static bool add_card_from_heap(HAND *, HAND *);
static bool draw_card_to_heap(HAND *, HAND *, CARD *);
static int deal_cards(HAND *, HAND *);
static int determine_result(HAND, HAND);

void init_game(HAND *p1, HAND *p2) {
  init_player(p1, "Player 1");
  init_player(p2, "Player 2");
  init_deck();
  shuffle_deck();
  deal_cards(p1, p2);

  print_deck();
  print_player(*p1);
  print_player(*p2);
}

int play_round(HAND *p1, HAND *p2) {
  static HAND heap = {{{0, 0}}, 0, 0, 0, NULL};
  CARD card_a, card_b;
  int result;

  print_player(*p1);
  print_player(*p2);
  if (is_empty(*p1) || is_empty(*p2)) {
    result = GAME_OVER;
  } else {
    draw_card_to_heap(&heap, p1, &card_a);
    draw_card_to_heap(&heap, p2, &card_b);
    result = compare_cards(card_a, card_b);
  }

  switch (result) {
  case 0:
    for (int i = 0; i < 3; i++) {
      if (is_empty(*p1) || is_empty(*p2)) {
        result = GAME_OVER;
        break;
      }
      draw_card_to_heap(&heap, p1, &card_a);
      draw_card_to_heap(&heap, p2, &card_b);
    }
    print_heap(heap);
    break;
  case 1:
    print_heap(heap);
    while (add_card_from_heap(&heap, p1))
      ;
    break;
  case 2:
    print_heap(heap);
    while (add_card_from_heap(&heap, p2))
      ;
    break;
  default:
    break;
  }

  return result;
}

int play_game(HAND *p1, HAND *p2) {
  static int roundn = 1;
  int result;

  result = GAME_OVER;
  do {
    print_roundn(roundn++);
    result = play_round(p1, p2);
  } while ((GAME_OVER != result) && ROUNDN_SMALLER_THAN_MAX_ROUND);

  result = determine_result(*p1, *p2);
  switch (result) {
  case 0:
    print_draw();
    break;
  case 1:
    print_winner(*p1);
    break;
  case 2:
    print_winner(*p2);
    break;
  default:
    break;
  }
  return result;
}

static bool add_card_from_heap(HAND *heap, HAND *player) {
  CARD card;
  if (!draw_card(heap, &card)) {
    return false;
  }
  if (!add_card(player, card)) {
    return false;
  }
  return true;
}

static bool draw_card_to_heap(HAND *heap, HAND *player, CARD *card) {
  if (!draw_card(player, card)) {
    return false;
  }
  if (!add_card(heap, *card)) {
    return false;
  }
  return true;
}

static int deal_cards(HAND *p1, HAND *p2) {
  int i;
  HAND *p;
  for (i = 0; i < DEAL_NB_CARDS; i++) {
    p = i % 2 ? p2 : p1;
    if (!add_card(p, get_card(i)))
      break;
  }
  return i;
}

static int determine_result(HAND p1, HAND p2) {
  if ((!is_empty(p1) && !is_empty(p2)) || (is_empty(p1) && is_empty(p2))) {
    return 0;
  } else if (is_empty(p1)) {
    return 2;
  } else {
    return 1;
  }
}
