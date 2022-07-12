##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile the lib
##

SRC	=	my_put_nbr.c	\
		my_put_nbr2.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_put_nbr2.c	\
		my_putstr2.c	\
		my_put_nbr_base.c	\
		my_put_nbr_binary.c	\
		my_put_nbr_hex.c	\
		my_printf.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_atoi.c	\
		my_getnbr.c	\
		str_to_word_array.c	\
		is_word_in_str.c	\
		nbr_to_str.c	\
		my_compute_power_rec.c

RM	= rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp my.h ../../includes
	@cp $(NAME) ../../

clean:
	@$(RM) $(OBJ)

my_clean:
	@$(RM) *~
	@$(RM) *#
	@$(RM) *.#

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../../libmy.a
	@$(RM) ../../includes/my.h

re:	fclean all
