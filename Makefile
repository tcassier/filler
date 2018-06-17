# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 03:34:08 by tcassier          #+#    #+#              #
#    Updated: 2018/06/17 19:22:14 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = tcassier.filler

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH) -I$(LFT_INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = main.c    \
	  fr_getstdin.c   \
	  fr_parser.c   \
	  fr_check.c    \
	  fr_solver.c  	\
	  fr_get_pos.c \
	  fr_outputs.c \
	  fr_pos_link.c  \
	  fr_choose.c  

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = filler.h

LFT_INC_PATH = $(LFT_PATH)includes/
LFT_PATH = ./libft/
LFT_FLAGS = -L $(LFT_PATH) -lft

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@make -C $(LFT_PATH) all
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFT_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
