NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
PFT			=	ft_printf/libftprintf.a
INC			=	-I ./include/so_long.h -I ./ft_printf -I ./mlx
LIB			=	-lmlx -framework OpenGL -framework AppKit
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
HEADER		= 	./include/so_long.h
SRC 		= main.c map_filler.c map_valid.c map.c player.c draw.c get_next_line.c get_next_line_utils.c enemy.c enemy_spawn.c validation_utils.c draw_utils.c draw_open.c
all:		$(MLX) $(PFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(PFT)  -o $@ $^ $(LIB)

$(MLX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -s -C mlx
	@echo " [ OK ] | Minilibx ready!"

$(PFT):
	@echo " [ .. ] | Compiling printf.."
	@make -s -C ft_printf
	@echo " [ OK ] | printf ready!"

obj:
			@mkdir -p obj

%.o:	%.c ./include/so_long.h
			$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
			@make -s $@ -C ft_printf
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C ft_printf
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re