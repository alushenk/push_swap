NAME = checker

SRCDIR = src

SRC =   checker.c \
        wrappers.c \
        stack_operations.c \
        errors.c \
        parsing.c


OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

LIB_PATH = externals/libft

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
