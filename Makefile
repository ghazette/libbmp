# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/19 13:50:37 by ghazette     #+#   ##    ##    #+#        #
#    Updated: 2018/10/19 13:50:53 by ghazette    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libbmp.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3

RM = rm -f

SRCS = srcs/decode/decode.c srcs/decode/header.c srcs/decode/rgb_decode.c\
		srcs/encode/encode.c srcs/encode/header.c srcs/encode/rgb_encode.c\
		srcs/shared/bitmap.c srcs/shared/check.c srcs/shared/utils.c

HEADER = includes/libbmp.h includes/bmp.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean