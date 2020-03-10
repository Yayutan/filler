NAME = mchuang.filler
SRC_PATH = ./srcs/
LFT_PATH = ./libft/
PFT_PATH = ./ft_printf/
INC_PATH = ./includes/

LFT = libft.a
PFT = libftprintf.a

FILLER_INC = -I $(INC_PATH)
LFT_INC = -I $(LFT_PATH)
PFT_INC = -I $(addprefix $(PFT_PATH), includes/)

LFT_LINK = -L $(LFT_PATH) -l ft
PFT_LINK = -L $(PFT_PATH) -l ftprintf

FLAGS = -Wall -Werror -Wextra
TEST_FLAGS = -g

RED  = "\033[0;31m"
GREEN  = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"
CLEAR = "\033[0m"

SRC_NAME =	main.c read_input.c put_piece.c stats.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

.PHONY: all clean fclean re

all: $(LFT) $(NAME)

$(LFT):
	@make -C $(LFT_PATH)
	@make -C $(PFT_PATH)

$(NAME): $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(FILLER_INC) $(LFT_INC) $(PFT_INC) $(LFT_LINK) $(PFT_LINK) $(SRC)
	@echo $(GREEN)"filler compiled" $(CLEAR)

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(PFT_PATH) clean
	@/bin/rm -f $(OBJ)
	@echo $(RED)"Deleted object files" $(CLEAR)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@make -C $(PFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM
	@echo $(RED)"Deleted executable files" $(CLEAR)

re: fclean all


test: fclean $(LFT)
	@gcc $(TEST_FLAGS) -o $(NAME) $(FILLER_INC) $(LFT_INC) $(PFT_INC) $(LFT_LINK) $(PFT_LINK) $(SRC)
	@echo $(CYAN)"filler test compiled" $(CLEAR)