# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pascal <pascal@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/02 15:18:24 by pascal        #+#    #+#                  #
#    Updated: 2021/11/19 14:45:58 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libshared.a
LIBFT_C		=	ft_abs.c\
				ft_atof.c\
				ft_atoi_strict.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_charcmpset.c\
				ft_decitohex.c\
				ft_dtoa.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_iswhitespace.c\
				ft_itoa.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdup.c\
				ft_memmove.c\
				ft_memset.c\
				ft_power.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_realloc.c\
				ft_realloc_double.c\
				ft_split.c\
				ft_split_free.c\
				ft_split_set.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnjoin.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtolower.c\
				ft_strtoupper.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_ulltoa.c\
				ft_numlen.c\
				ft_unumlen.c\
				get_next_line.c\
				get_next_line_utils.c
LIBFT_O		=	$(LIBFT_C:%.c=%.o)

SHARED_C	=	error.c\
				get_lowest_num.c\
				instruct.c\
				ints_to_nodes.c\
				is_sorted.c\
				node_functions.c\
				parse_stack.c\
				print_stack.c\
				stack_push.c\
				stack_rotate_down.c\
				stack_rotate_up.c\
				stack_swap.c
SHARED_O	=	$(SHARED_C:%.c=%.o)

CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -I ../includes/
CC			=	gcc

all: $(NAME)

$(NAME): $(LIBFT_C) $(SHARED_C) $(LIBFT_O) $(SHARED_O)
	ar -crs $(NAME) $(LIBFT_O) $(SHARED_O)

%.o: %.c libft.h
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIBFT_O) $(SHARED_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
