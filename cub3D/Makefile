NAME = Cub3D

SRCS = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memccpy.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	parsing/check.c \
	parsing/check1.c \
	parsing/check_updwn.c \
	parsing/inisialisation.c \
	parsing/parse_f.c \
	parsing/parse_f1.c \
	parsing/parse_map.c \
	parsing/parse_resolution.c \
	parsing/parse_ceilfloor.c \
	parsing/parse_textures.c \
	parsing/sup_espace.c \
	parsing/table_utils.c \
	texture/load_texture.c \
	bitmap.c \
	dda.c \
	game_loop.c \
	cast_sprite.c \
	cast_wall.c \
	get_dir.c \
	player.c \
	sprite.c \
	hook_ply.c \
	hook_ply1.c \
	main.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I libft/ \
		-I get_next_line/ \
		-I cub.h \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(FRAMEWORKS) -o $(NAME)

clean : 
	/bin/rm -f $(OBJS)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

bonus : $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

