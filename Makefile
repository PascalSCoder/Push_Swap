# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pspijkst <pspijkst@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/23 13:52:33 by pspijkst      #+#    #+#                  #
#    Updated: 2021/07/15 11:04:36 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	checker push_swap
PS_DIR	=	src_push_swap/
PS_SRC	=	$(shell find $(PS_DIR)*.c)
PS_SRCS	=	$(PS_SRC)#$(addprefix $(PS_DIR), $(PS_SRC))
PS_OBJ	=	$(PS_SRC:%.c=%.o)

CK_DIR	=	src_checker/
CK_SRC	=	$(shell find $(CK_DIR)*.c)# -exec basename {} \;
CK_SRCS	=	$(CK_SRC)#$(addprefix $(CK_DIR), $(CK_SRC))
CK_OBJ	=	$(CK_SRC:%.c=%.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra

all: push_swap

push_swap: $(PS_OBJ)
	$(MAKE) -C shared/
	$(CC) $(PS_OBJ) -Lshared/ -lshared -o push_swap

checker: $(CK_OBJ)
	$(MAKE) -C shared/
	$(CC) $(CK_SRCS) -Lshared/ -lshared -o checker

src_push_swap/%.o: %.c
	@echo "compiling push_swap..."
	@mkdir -p obj
	@mkdir -p obj/src_push_swap
	$(CC) -c $(CFLAGS) -o $@ $<

src_checker/%.o: %.c
	@mkdir -p obj
	@mkdir -p obj/src_checker
	$(CC) -c $(CFLAGS) -o obj/$@ $<

clean:
	$(MAKE) clean -C shared
	rm -f $(CK_OBJ)
	rm -f $(PS_OBJ)

fclean: clean
	$(MAKE) -C shared fclean

re: fclean all

.PHONY: all clean fclean re
