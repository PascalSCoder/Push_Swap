# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pspijkst <pspijkst@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/23 13:52:33 by pspijkst      #+#    #+#                  #
#    Updated: 2021/07/31 12:10:21 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CHECKER	=	checker

PS_DIR	=	src_push_swap/
PS_C	=	a_to_b_to_a.c\
			num_comparisons.c\
			push_swap.c\
			sort_back.c\
			sort_simple.c\
			contains_state.c
PS_SRC	=	$(addprefix $(PS_DIR), $(PS_C))
PS_OBJ	=	$(PS_SRC:%.c=%.o)

CK_DIR	=	src_checker/
CK_C	=	checker.c
CK_SRC	=	$(addprefix $(CK_DIR), $(CK_C))
CK_OBJ	=	$(CK_SRC:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

make_ps: libshared $(NAME)

make_ck: libshared $(CHECKER)

$(NAME): $(PS_SRC) $(PS_OBJ) shared/libshared.a
	$(CC) $(PS_OBJ) $(CFLAGS) -Lshared/ -lshared -o $(NAME)

$(CHECKER): $(CK_SRC) $(CK_OBJ) shared/libshared.a
	$(CC) $(CK_OBJ) $(CFLAGS) -Lshared/ -lshared -o $(CHECKER)

libshared:
	$(MAKE) -C shared/

all: make_ps make_ck

$(PS_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(CK_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C shared
	rm -f $(CK_OBJ)
	rm -f $(PS_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	$(MAKE) -C shared fclean

re: fclean $(NAME)

.PHONY: all clean fclean re libshared make_ps make_ck
