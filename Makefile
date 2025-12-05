NAME = cub3D

FLAGS = -Wall -Wextra -Werror

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

CC = gcc

SRC = main.c raycast.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX)
		$(CC) $(OBJ) $(FLAGS) $(MINILIBX) -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) -C $(MINILIBX_PATH) clean

fclean: clean
		rm -f $(NAME)

re: fclean all

%.o: %.c
		$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MINILIBX):
		$(MAKE) -C $(MINILIBX_PATH)
