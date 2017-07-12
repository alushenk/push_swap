PUSH_SWAP = push_swap

CHECKER = checker

GNLDIR = externals/get_next_line

SRCDIR = src

SRC_CHECKER =	checker.c \
        		errors.c \
        		parsing.c \
        		simple_sorting.c \
        		display.c \
        		instructions.c \
        		wrappers/wrappers.c \
        		wrappers/wrappers_a.c \
        		wrappers/wrappers_b.c \
        		stack_operations/stack_operations.c \
        		stack_operations/create_functions.c \
        		stack_operations/push_functions.c \
        		stack_operations/rotate_functions.c

SRC_PUSH_SWAP = algorithm.c \
        		cases.c \
        		display.c \
        		errors.c \
        		main.c \
        		parsing.c \
        		simple_sorting.c \
        		three_two_sortings.c \
        		split_functions.c \
        		instructions.c \
        		simultaneous_sort/simultaneous_sort.c \
        		simultaneous_sort/merge_functions.c \
        		simultaneous_sort/rename_functions.c \
        		wrappers/wrappers.c \
        		wrappers/wrappers_a.c \
        		wrappers/wrappers_b.c \
        		stack_operations/stack_operations.c \
        		stack_operations/create_functions.c \
        		stack_operations/push_functions.c \
        		stack_operations/rotate_functions.c

GNL =	get_next_line.c

OBJ_CHECKER = $(addprefix $(SRCDIR)/, $(SRC_CHECKER:.c=.o))

OBJ_PUSH_SWAP = $(addprefix $(SRCDIR)/, $(SRC_PUSH_SWAP:.c=.o))

OBJ_GNL = $(addprefix $(GNLDIR)/, $(GNL:.c=.o))

LIB_PATH = $(GNLDIR)/libft

all: $(OBJ_CHECKER) $(OBJ_PUSH_SWAP) $(OBJ_GNL)
	make -C $(LIB_PATH)
	gcc -g -Wall -Wextra -Werror -o $(CHECKER) $(OBJ_CHECKER) $(OBJ_GNL) $(LIB_PATH)/libft.a
	gcc -g -Wall -Wextra -Werror -o $(PUSH_SWAP) $(OBJ_PUSH_SWAP) $(OBJ_GNL) $(LIB_PATH)/libft.a

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSH_SWAP)
	rm -f $(OBJ_GNL)
	make clean -C $(LIB_PATH)

fclean:
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)
	rm -f $(OBJ_CHECKER)
	rm -f $(OBJ_PUSH_SWAP)
	rm -f $(OBJ_GNL)
	make fclean -C $(LIB_PATH)

re: fclean all
