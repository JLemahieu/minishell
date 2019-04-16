NAME = minishell

CC = gcc
FLAGS = -Wall -Werror -Wextra

INC = include/incshell.h
SRC_PATH = src
OBJ_PATH = obj
MYBI_PATH = src/mybuiltin
LIB_PATH = lib/libft.a

SOURCES = main.c \
		utils.c \
		ft_free.c \
		sh_exec.c \
		parsesh.c \
		ft_strsplitsh.c \
		varsh.c

MYBI = bi_echo.c \
			bi_env.c \
			bi_unsetenv.c \
			bi_exit.c \
			bi_setenv.c \
			bi_cd.c \
			usages.c


SRCS = $(addprefix $(SRC_PATH)/, $(SOURCES))
BIS = $(addprefix $(MYBI_PATH)/, $(MYBI))

OBJS = $(addprefix $(OBJ_PATH)/, $(SOURCES:.c=.o))
OBJB = $(addprefix $(OBJ_PATH)/, $(MYBI:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(OBJB)
	@make -C lib
	@$(CC) $(OBJS) $(OBJB) $(LIB_PATH) -o $(NAME)
	@echo "Compilation $(NAME) OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p obj
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(MYBI_PATH)/%.c $(INC)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C lib
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIB_PATH)

re: fclean all
