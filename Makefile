NAME = checker

SRCDIR = src

GNLDIR = externals/get_next_line

CHECKER_DIR = checker_files

SRC =   wrappers.c \
        stack_operations.c \
        errors.c \
        parsing.c \
        simple_sorting.c \
        display.c

GNL =	get_next_line.c

CHECKER = main.c

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o)) $(addprefix $(GNLDIR)/, $(GNL:.c=.o)) $(addprefix $(CHECKER_DIR)/, $(CHECKER:.c=.o))

LIB_PATH = $(GNLDIR)/libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB_PATH)/libft.a

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C $(LIB_PATH)

re: fclean all
