# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/14 19:15:23 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 19:33:42 by jmonneri    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_OBJ = ./objs/
PATH_SRC = ./srcs/
PATH_INC = ./incs/
INC = $(addprefix $(PATH_INC), libft.h fdf.h )

#******************************************************************************#
#                                    MLX                                       #
#******************************************************************************#

NAME_MLX = mlx
PATH_MLX = ./minilibx/
PATH_INC_MLX = ./minilibx/
FRAMEWORKS = -framework OpenGL -framework AppKit
MINILIBX = $(PATH_MLX)lib$(NAME_MLX).a

#******************************************************************************#
#                                    FDF                                       #
#******************************************************************************#

PATH_SRC_FDF = $(PATH_SRC)Fdf/
PATH_OBJ_FDF = $(PATH_OBJ)Fdf/
FILES_FDF = ft_bresenham ft_fdf_draw ft_fdf_engine ft_fdf_parse\
			ft_fdf_put_in_tab perspective main ft_fdf_test_file keys
OBJ_FDF = $(addprefix $(PATH_OBJ_FDF), $(addsuffix .o, $(FILES_FDF)))
SRC_FDF = $(addprefix $(PATH_SRC_FDF), $(addsuffix .c, $(FILES_FDF)))

#******************************************************************************#
#                                   LIBFT                                      #
#******************************************************************************#

PATH_SRC_LIBFT = $(PATH_SRC)Libft/
PATH_OBJ_LIBFT = $(PATH_OBJ)Libft/
FILES_LIBFT = ft_atoi ft_bzero ft_chartostr ft_freestr2d ft_gswap ft_int_swap\
			  ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_lintlen\
			  ft_litoa ft_litoa_base ft_lstadd ft_lstdel ft_lstdelone\
			  ft_lstiter ft_lstmap ft_lstnew ft_memalloc ft_memccpy ft_memchr\
			  ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset\
			  ft_print_strlst ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd\
			  ft_putnbr ft_putnbr_fd ft_putstr ft_putstr2d ft_putstr_fd\
			  ft_putwchar ft_putwstr ft_strcat ft_strchr ft_strclr ft_strcmp\
			  ft_strcnew ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter\
			  ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi\
			  ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr\
			  ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtolower\
			  ft_strtoupper ft_strtrim ft_tolower ft_toupper ft_ulintlen\
			  ft_ulitoa ft_ulitoa_base ft_wchartowstr ft_wstrdup ft_wstrlen\
			  get_next_line ft_str2dlen
OBJ_LIBFT = $(addprefix $(PATH_OBJ_LIBFT), $(addsuffix .o, $(FILES_LIBFT)))
SRC_LIBFT = $(addprefix $(PATH_SRC_LIBFT), $(addsuffix .c, $(FILES_LIBFT)))

#******************************************************************************#
#                                     ALL                                      #
#******************************************************************************#

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_FDF) $(PATH_OBJ_LIBFT)
OBJ = $(OBJ_FDF) $(OBJ_LIBFT)
SRC = $(SRC_FDF) $(SRC_LIBFT)
FILES = $(FILES_FDF) $(FILES_LIBFT)

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(NAME)

clean:
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DES OBJETS🦄 🦄 🦄 🦄\033[0m\n"
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_MLX)

test: all
	@./$(NAME) tests/42.fdf

fclean: clean
	@printf "\n\033[1m🦄 🦄 🦄 🦄 SUPPRESSION DE $(NAME)🦄 🦄 🦄 🦄\033[0m\n"
	@rm -rf $(NAME)
	@make clean -C $(PATH_MLX)

re: fclean all

#******************************************************************************#
#                                  Comp FDF                                    #
#******************************************************************************#


$(NAME): $(MINILIBX) $(PATHS_OBJ) $(OBJ)
	@printf "\n\033[1m🦄 🦄 🦄 🦄 CREATION DE FDF🦄 🦄 🦄 🦄\033[0m\n"
	@$(CC) $(CC_FLAGS) $(OBJ) -I $(PATH_INC) -I $(PATH_INC_MLX) -L $(PATH_MLX)\
		-l$(NAME_MLX) $(FRAMEWORKS) -o $(NAME)
	@printf "  👍  👍  👍 \033[1mEXECUTABLE CREE\033[0m👍  👍  👍\n\n"

$(MINILIBX):
	@printf "Creating libmlx.a..."
	@make -C $(PATH_MLX)
	@printf "   \033[0;32m[OK]\033[0m\n"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INC)
	@printf "0️⃣  Compilation of \033[1m$<\033[0m to \033[1m$@\033[0m..."
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC)
	@printf "   \033[0;32m[OK]\033[0m\n"

$(PATHS_OBJ):
	@mkdir $@
