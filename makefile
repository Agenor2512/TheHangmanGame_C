all: HangmanGame

HangmanGame: main.c
	gcc $^ -o $@
