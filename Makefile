# VARIABLES==============================
NAME =minishell
CFLAGS =-Wall -Wextra -Werror
PROGLIB =-lreadline

# FILES==================================
SRC =minishell.c builtin_echo.c
OBJ =$(SRC:%.c=%.o)

# COLORS=================================
BLACK =\033[1;30m
RED =\033[1;31m
GREEN =\033[1;32m
YELLOW =\033[1;33m
BLUE =\033[1;34m
PURPLE =\033[1;35m
CYAN =\033[1;36m
WHITE =\033[1;37m
RESET =\033[0m

# RULES==================================
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@make -C libft
	@cc $(CFLAGS) $(PROGLIB) $(OBJ) libft/libft.a -o $(NAME)

$(OBJ):
	@cc $(CFLAGS) -I . -c $(@:%.o=%.c)

fclean: clean
	@echo "$(RED)Full Cleaning...$(RESET)"
	@make -C libft fclean
	@rm -rf $(NAME)

clean:
	@echo "$(RED)Cleaning all objects...$(RESET)"
	@make -C libft clean
	@rm -rf $(OBJ)

re: fclean all
	@echo "$(YELLOW)Recompiled$(RESET)"

norm:
	@norminette . | grep -B 1 "Error"
	@echo "$(PURPLE) "

.PHONY: all clean fclean re