NAME = push_swap

SRCS = push_swap.c  input_validator.c stack_init.c \
	   utils_one.c utils_two.c utils_three.c utils_four.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔️$(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)✗ Destroying object files...$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)✗ Destroying object files and executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
