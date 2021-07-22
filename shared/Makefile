# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pspijkst <pspijkst@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/26 17:28:20 by pspijkst      #+#    #+#                  #
#    Updated: 2021/05/19 11:48:13 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libshared.a
FILES	=	$(shell find *.c)
OBJS	=	$(FILES:%.c=obj/%.o)
CFLAGS	=	-Wall -Wextra

all: libft $(NAME)

libft:
	$(MAKE) -C ../../libft/

$(NAME): $(OBJS)
	cp ../../libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJS)

obj/%.o: %.c
	@mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f obj/*.o

#rm -f $(OBJS)

fclean: clean
	rm -f libshared.a

re: fclean all

.PHONY: all clean fclean re
