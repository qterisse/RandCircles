# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:09:53 by quteriss          #+#    #+#              #
#    Updated: 2024/01/12 18:27:47 by quteriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= randcircles.c \
		drawing_tools/draw_circle.c \
		drawing_tools/background.c \
		utils/math_utils.c \
		utils/minilibx_utils.c \
		utils/point_utils.c \
		utils/tclist_utils.c
	
OBJS	= $(SRCS:.c=.o)
CC		= cc
FLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
NAME	= fractol

MINILIBX_PATH		=	minilibx/
MINILIBX_INCLUDES	=	$(MINILIBX_PATH)
MINILIBX_L			=	-L $(MINILIBX_PATH) -l mlx
MINILIBX_A			=	$(MINILIBX_PATH)libmlx.a
MAKE_MINILIBX		=	$(MAKE) -C $(MINILIBX_PATH)

DIR_INCS	= includes/$(MINILIBX_INCLUDES)
INCLUDES	= $(addprefix -I , $(DIR_INCS))
LIBS		= -lm $(MINILIBX_L) -lXext -lX11

all:
	$(MAKE_MINILIBX)
	$(MAKE) $(NAME)

%.o:	%.c Makefile fractol.h
	$(CC) $(FLAGS) -I ./ $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -I ./ $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean
	$(MAKE) all

.PHONY:	all clean fclean re