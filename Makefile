NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
FRAME = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
INC = so_long.h
INCB = so_long_bonus.h
CFILES = gameplay/move_derection.c \
		gameplay/player_position.c \
		needness/ft_strncmp.c \
		needness/free_all.c \
		rendring/load_img.c \
		rendring/destroy.c \
		rendring/rendring.c \
		parsing/check_map.c \
		parsing/parse_map.c \
		parsing/invalid.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		so_long.c
BFILES_x = gameplay/move_derection.c \
		gameplay/player_position.c \
		gameplay/win_lose.c \
		needness/ft_strncmp.c \
		needness/free_all.c \
		needness/ft_itoa.c \
		needness/ft_strjoin2.c \
		rendring/load_img.c \
		rendring/destroy.c \
		rendring/rendring.c \
		parsing/check_map.c \
		parsing/parse_map.c \
		parsing/invalid.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		so_long.c
	
BFILES = $(addprefix bonus/, $(BFILES_x))

MOBJS = ${CFILES:.c=.o}
BOBJS = ${BFILES:.c=.o}

all: $(NAME)

$(NAME): $(MOBJS) $(INC)
	@ echo "Compiling Mandatory...."
	$(CC) $(FLAGS) $(FRAME) $(MOBJS) -o $(NAME)

bonus : $(BOBJS)
	@ echo "Compiling Bonus...."
	$(CC) $(FLAGS) $(FRAME) $(BOBJS) -o $(BONUS_NAME)
%.o:%.c $(INC) $(INCB)
	cc $(CFLAGS) -c $< -o $@
clean :
	@ echo "Cleaning..."
	@ rm -rf $(MOBJS)
	@ rm -rf $(BOBJS)
fclean : clean
	@ echo "Cleaning all..."
	@ rm -rf $(NAME) $(BONUS_NAME)
re : fclean all
.PHONY : all clean fclean re bonus