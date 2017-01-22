##
## Makefile for cpp_gkrellm in /home/wluc/Epitech/GGJ/cpp_gkrellm
## 
## Made by William LUC
## Login   <luc_w@epitech.net>
## 
## Started on  Sun Jan 22 13:09:25 2017 William LUC
## Last update Sun Jan 22 14:49:25 2017 Jean Francois Durand
##

CC = g++

CFLAGS = -W -Wall -Werror

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME = RabBitches

SRCS =  Bunny.cpp  \
	Game_Information.cpp  \
	IButton.cpp  \
	main.cpp  \
	menu.cpp  \
	Mine.cpp  \
	Start.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

