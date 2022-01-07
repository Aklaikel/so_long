NAME = so_long
CC = gcc
FRAME = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
INC = so_long.h
CFILES = gameplay/move_derection.c \
		gameplay/player_position.c \
		needness/ft_strncmp.c \
		rendring/load_img.c \
		rendring/destroy.c \
		rendring/rendring.c \
		parsing/check_map.c \
		parsing/parse_map.c \
		parsing/invalid.c \
		parsing/free_all.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		so_long.c

MOBJS = ${CFILES:.c=.o}

all: $(NAME)

$(NAME): $(MOBJS) $(INC)
	@ echo "Compiling Mandatory...."
	$(CC) $(FLAGS) $(FRAME) $(MOBJS) -o $(NAME)

bonus : $(BOBJS) $(INCB)
	@ echo "Compiling Bonus...."
	$(CC) $(FLAGS) $(FRAME) $(BOBJS) -o $(NAME)
clean :
	@ echo "Cleaning..."
	@ rm -rf $(MOBJS)
	@ rm -rf $(BOBJS)
fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re bonus