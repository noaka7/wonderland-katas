objects=card_game_war card_game_war_deck card_game_war_hand card_game_war_play \
card_game_war_print test

all: $(objects)

card_game_war: card_game_war.c card_game_war_deck.c card_game_war_hand.c \
	card_game_war_play.c card_game_war_print.c
	gcc -o $@ $^

card_game_war_deck: card_game_war_deck.c
	gcc -c -o $@ $<

card_game_war_hand: card_game_war_hand.c
	gcc -c -o $@ $<

card_game_war_play: card_game_war_play.c
	gcc -c -o $@ $<

card_game_war_print: card_game_war_print.c
	gcc -c -o $@ $<

test: card_game_war_deck.c card_game_war_hand.c card_game_war_play.c \
	card_game_war_print.c test.c
	gcc -o $@ $^

.PHONY: clean

clean:
	-rm $(objects)
