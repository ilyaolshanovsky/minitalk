# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byuri <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 17:48:50 by byuri             #+#    #+#              #
#    Updated: 2021/07/31 17:49:03 by byuri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minitalk

CL					=	client
CL_SRC_LST			=	utils.c client.c

SV					=	server
SV_SRC_LST			=	utils.c server.c

CL_SRC_LST_BONUS	=	utils_bonus.c client_bonus.c
SV_SRC_LST_BONUS	=	utils_bonus.c server_bonus.c

CC					=	gcc
FLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf

all: $(NAME)

$(NAME): $(CL) $(SV)

$(CL): $(CL_SRC_LST)
	$(CC) $(FLAGS) $(CL_SRC_LST) -o $(CL)

$(SV): $(SV_SRC_LST)
	$(CC) $(FLAGS) $(SV_SRC_LST) -o $(SV)

bonus: cl_bonus sv_bonus

cl_bonus: $(CL_SRC_LST_BONUS)
	$(CC) $(FLAGS) $(CL_SRC_LST_BONUS) -o $(CL)

sv_bonus: $(SV_SRC_LST_BONUS)
	$(CC) $(FLAGS) $(SV_SRC_LST_BONUS) -o $(SV)

cl: $(CL)

sv: $(SV)

clean:

fclean: clean
	@$(RM) $(SV) $(CL) $(SV_BONUS) $(CL_BONUS) 

re: fclean all

 .PHONY: all clean sv cl fclean re sv_bonus cl_bonus $(NAME)
