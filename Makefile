OBJ_DIR	 = ./obj
OBJ_DIRC = ./objc
LIB_DIR	 = ./libft

NAME	 = push_swap
NAMEC    = checker
LIBFT 	 = $(LIB_DIR)/libft.a

SRC 	 = push_swap.c operations.c validation.c init.c sort.c chosenumber.c
SRCC     = checker.c init.c validation.c operations.c

OBJ 	 = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJC	 = $(addprefix $(OBJ_DIRC)/,$(SRCC:.c=.o))

CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
LIB_INC  = -I $(LIB_DIR)/includes
LIB_LINK = -L $(LIB_DIR) -lft

all: $(NAME) $(NAMEC)

$(LIBFT):
	@make -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@
$(OBJ_DIRC):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_INC) $(LIB_LINK) -o $(NAME)
	@echo push_swap Executable created.
$(NAMEC): $(LIBFT) $(OBJC)
	make -C libft
	$(CC) $(CFLAGS) $(OBJC) $(LIB_INC) $(LIB_LINK) -o $(NAMEC)
	@echo checker Executable created.

$(addprefix $(OBJ_DIR)/, %.o):%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@
$(addprefix $(OBJ_DIRC)/, %.o):%.c | $(OBJ_DIRC)
	$(CC) $(CFLAGS) $(LIB_INC) -c $< -o $@

clean:
	@make -C $(LIB_DIR) clean --no-print-directory
	rm -rf $(OBJ_DIR)
	@echo push_swap Object files deleted.
	rm -rf $(OBJ_DIRC)
	@echo checker Object files deleted.

fclean: clean
	@make -C $(LIB_DIR) fclean --no-print-directory
	rm -f $(NAME)
	@echo push_swap Executable deleted.
	rm -f $(NAMEC)
	@echo checker Executable deleted.

re: fclean all

