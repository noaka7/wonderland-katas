#include "card_game_war_hand.h"
#include "card_game_war_play.h"

int main(int argc, char **argv) {
  HAND p1, p2;
  init_game(&p1, &p2);
  play_game(&p1, &p2);
  return 0;
}
