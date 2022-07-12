##
## EPITECH PROJECT, 2022
## makefile
## File description:
## make
##

NAME	=	tetris

CC	=	gcc

RM	=	rm -f

PARAMETERS	=	sources/parameters/print_help.c	\
			sources/parameters/display_debug.c	\
			sources/parameters/count_files.c	\
			sources/parameters/deleted_space.c	\
			sources/parameters/allowed_key.c	\

INIT_GAME	=	sources/init_game/is_tetriminos.c	\
			sources/init_game/init_tetris.c	\
			sources/init_game/open_tetriminos.c	\
			sources/init_game/keep_data.c	\

GAME_RENDERING	=	sources/game_rendering/game.c	\
			sources/game_rendering/rendering_tetriminos.c	\
			sources/game_rendering/falling_rules.c	\
			sources/game_rendering/game_next.c	\

GAME_UPDATING	=	sources/game_updating/rotate_matrix.c	\
			sources/game_updating/game_move_tetriminos.c	\
			sources/game_updating/can_go_there.c	\
			sources/game_updating/win_condition.c	\
			sources/game_updating/game_drop_tetrimino.c	\
			sources/game_updating/game_turn_tetrimino.c	\

SRC	=	sources/main.c	\
		$(PARAMETERS)	\
		$(INIT_GAME)	\
		$(GAME_RENDERING)	\
		$(GAME_UPDATING)	\
		sources/free_all.c

CPPFLAGS	=	-I./includes -lncurses

LDFLAGS	=	-L./ -lmy

CFLAGS	=	-Wall -Wextra

VFLAGS	=	-g3

all: $(NAME)

$(NAME):
	@make -C lib/my
	@$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) $(VFLAGS)
	@touch high_score.legend

clean:
	@make clean -C lib/my

fclean: clean
	@make fclean -C lib/my
	@$(RM) $(NAME)

my_clean: fclean
	@make my_clean -C lib/my
	@$(RM) *~
	@$(RM) *.gcno
	@$(RM) *.gcda
	@$(RM) includes/*~
	@$(RM) sources/*~
	@$(RM) tests/*~
	@$(RM) vgcore*

re: fclean all

valgrind: fclean all
	@valgrind ./$(NAME)

.PHONY: all clean fclean my_clean re valgrind tests_run
