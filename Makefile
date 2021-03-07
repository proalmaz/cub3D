.PHONY: all clean bonus fclean re

NAME = cub3D

HEADER = cub3d.h

LIBFT_DIR = libraries/libft/

LIBFT = $(LIBFT_DIR)libft.a

LIBMLX_DIR = libraries/minilibx_mms/

LIBMLX = $(LIBMLX_DIR)libmlx.dylib

MAKE = make

CLEAN = clean

FCLEAN = fclean

SRC = main.c\
	cub3d.c\
	cub2d.c\
	parser/parser.c\
	parser/parser_for_map.c\
	check_errors/error_1.c\
	check_errors/error_2.c\
	check_errors/error_3.c\
	srcs/cub2d_helpers.c\
	srcs/cub3d_utils_1.c\
	srcs/cub3d_utils_2.c\
	srcs/cub3d_utils_3.c\
	srcs/floor_ceiling.c\
	srcs/key_hook.c\
	srcs/sprite_helpers.c\
	srcs/sprite_text.c\
	srcs/set_direction.c\
	srcs/screenshot.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -g -O0

FLAGMLX = -framework OpenGL -framework AppKit

OPTION = -c -D GL_SILENCE_DEPRECATION

OPTIONOBJ = -o

DEL = rm -rf

GREEN ='\033[1;32m'

WHITE ='\033[0;37m'

YELLOW ='\033[1;33m'

CYAN ='\033[1;36m'

MAGENTA ='\033[1;35m'

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@cd $(LIBFT_DIR) && mv ./libft.a ../../
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../../
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGSMLX) $(OPTIONOBJ) $(NAME)
	@echo ${YELLOW}"Все готово!"
	@echo $(GREEN)"Поехали!"${WHITE}

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo ${MAGENTA}"Начало положено!"

$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)
	@echo ${CYAN}"Почти закончил!"

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	@echo $(GREEN)"Все чисто."

fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)
	@echo $(GREEN)"Все библиотеки удалены."

re: fclean all