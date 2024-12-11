
NAME		= cub3D

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
LMLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx
RM			= rm -rf
MLX			= mlx

SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)ft_check_one.c \
			$(SRC_DIR)ft_check_two.c \
			$(SRC_DIR)ft_errors_and_frees.c \
			$(SRC_DIR)ft_parshing.c \
			$(SRC_DIR)ft_cell_and_rgb.c \
			$(SRC_DIR)ft_split.c \
			$(SRC_DIR)ft_floor.c \
			$(SRC_DIR)ft_dual_split.c \
			$(SRC_DIR)ft_utils_one.c \
			$(SRC_DIR)ft_utils_two.c \
			$(SRC_DIR)ft_get_maps.c \
			$(SRC_DIR)ft_move_q1.c \
			$(SRC_DIR)ft_move_q2.c \
			$(SRC_DIR)ft_move_q3.c \
			$(SRC_DIR)ft_move_q4.c \
			$(SRC_DIR)ft_move.c \
			$(SRC_DIR)ft_screen.c \
			$(SRC_DIR)ft_walk.c \
			$(SRC_DIR)ft_toolbox.c \
			$(SRC_DIR)ft_rotate.c


			
SRC_DIR	=			src/
OBJS	= 	$(SRCS:.c=.o)

#.SILENT:

all:		$(NAME)

%.o: $(SRC_DIR)%.c
		$(CC) $(CFLAGS)  -c $< -o $@

$(NAME):	$(OBJS) 
			$(MAKE) -C mlx 2> logs
			make  -C $(MLX)
			$(CC) $(CFLAGS) $(LMLX) $(MLX)/libmlx.a -o $@ $^

clean:
			@make -C $(MLX) clean
			@$(RM) $(OBJS) 


fclean:		clean
			@$(RM) $(NAME)  logs

re:			fclean all

.PHONY:		all clean fclean re 

