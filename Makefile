NAME = push_swap

NAME_CHECKER = checker

SRCS_PATH = ./srcs/

PUSH_SWAP_PATH = $(SRCS_PATH)push_swap/

CHECKER_PATH = $(SRCS_PATH)checker/

UTILS_PATH = $(SRCS_PATH)general_utils/

GNL_PATH = $(UTILS_PATH)GNL/

INCL_PATH = ./includes

CC = gcc

#TODO remove sanitise flag when submitting
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
# CFLAGS = -Wall -Wextra -Werror

#Source files
SRC_PUSH = $(PUSH_SWAP_PATH)push_swap_main.c \


SRC_CHECK = $(CHECKER_PATH)checker_main.c \
	$(CHECKER_PATH)checker_stack_manager.c \
	$(CHECKER_PATH)checker_stack_manager_indices.c \
	$(CHECKER_PATH)checker_visualiser.c \
	$(CHECKER_PATH)checker_validator.c \
	$(CHECKER_PATH)commands_pa-pb.c \
	$(CHECKER_PATH)commands_rr-ra-rb.c \
	$(CHECKER_PATH)commands_rrr-rra-rrb.c \
	$(CHECKER_PATH)commands_ss-sa-sb.c \


SRC_GENERAL = $(UTILS_PATH)general_utils_atoi.c \
	$(UTILS_PATH)general_utils_itoa.c \
	$(UTILS_PATH)general_utils_strcmp.c \
	$(GNL_PATH)get_next_line.c \
	$(GNL_PATH)get_next_line_utils.c \


#Object files
OBJ_PUSH := ${SRC_PUSH:%.c=%.o}

OBJ_CHECK := ${SRC_CHECK:%.c=%.o}

OBJ_GENERAL := ${SRC_GENERAL:%.c=%.o}


all: $(NAME)

$(NAME): $(OBJ_PUSH) $(OBJ_GENERAL)
	@$(CC) -o $(NAME) $(OBJ_PUSH) $(OBJ_GENERAL) $(CFLAGS)
	@echo "Push_swap compiled"

$(NAME_CHECKER): $(OBJ_CHECK) $(OBJ_GENERAL)
	@$(CC) -o $(NAME_CHECKER) $(OBJ_CHECK) $(OBJ_GENERAL) $(CFLAGS)
	@echo "Checker compiled"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -O3 -I $(INCL_PATH) 

bonus:
	@$(MAKE)
	@echo "...but done ✨fancy✨"

clean:
	@rm -f $(OBJ_PUSH) $(OBJ_CHECK) $(OBJ_GENERAL) 
	@echo $(NAME) "&" $(NAME_CHECKER) "object files cleaned"

fclean: clean
	@rm -f $(NAME) $(NAME_CHECKER)
	@echo $(NAME) "&" $(NAME_CHECKER) "fully cleaned"

re: fclean all $(NAME_CHECKER)

.PHONY: all bonus clean fclean re