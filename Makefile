# Colors ----------------------------------------------------- #
# ------------------------------------------------------------ #
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
CIAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

# Final program ---------------------------------------------- #
# ------------------------------------------------------------ #
NAME = push_swap

# Source files ----------------------------------------------- #
# ------------------------------------------------------------ #
SRCS = $(SRC_FILES)

SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_CFILES))
SRC_CFILES = \
		push_swap.c \
		manage_errors.c \

LIBFT_DIR =$(SRC_DIR)/libft
PRINTF_DIR =$(SRC_DIR)/printf
GNL_DIR =$(SRC_DIR)/gnl

# Object files ----------------------------------------------- #
# ------------------------------------------------------------ #
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_DIR = build

# Compiler options ------------------------------------------- #
# ------------------------------------------------------------ #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LINKFLAGS = -L./$(LIBFT_DIR) -lft -L./$(PRINTF_DIR) -lprintf -L./$(GNL_DIR) -lgnl
INCL_DIR = includes

# Rules ------------------------------------------------------ #
# ------------------------------------------------------------ #
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(CC) $(CFLAGS) $(LINKFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)[+] $(NAME) compilado$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I./$(INCL_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)[+]$(END) Archivos objeto .o borrados"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)[+]$(END) libft borrado"
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@echo "$(GREEN)[+]$(END) printf borrado"
	@$(MAKE) fclean -C $(GNL_DIR)
	@echo "$(GREEN)[+]$(END) gnl borrado"
	@rm -f $(NAME)
	@echo "$(GREEN)[+]$(END) $(NAME) borrado"

re: fclean all

.PHONY: all clean fclean re