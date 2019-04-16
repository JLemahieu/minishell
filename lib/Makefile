NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_PATH = src
LIB_PATH = lib
PRINT_PATH = src/print
OBJ_PATH = obj

SOURCES = ft_exec.c ft_parse.c ft_printf.c utils.c

LIB = ft_atoi.c ft_memalloc.c ft_putchar.c ft_putstr_fd.c ft_striter.c \
ft_strndup.c ft_toupper.c ft_bzero.c ft_memccpy.c ft_putchar_fd.c \
ft_putwchar.c ft_striteri.c ft_strnequ.c ft_wcharlen.c ft_debug.c ft_memchr.c \
ft_putendl.c ft_strcat.c ft_strjoin.c ft_strnew.c ft_wstrlen.c \
ft_isalnum.c ft_memcmp.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strnstr.c \
get_next_line.c ft_isalpha.c ft_memcpy.c ft_putinbuffer.c ft_strclr.c \
ft_strlen.c ft_strrchr.c ft_isascii.c ft_memdel.c ft_putnbr.c ft_strcmp.c \
ft_strmap.c ft_strsplit.c ft_isdigit.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c \
ft_strmapi.c ft_strstr.c ft_isprint.c ft_memset.c ft_putnstr.c ft_strdel.c \
ft_strncat.c ft_strsub.c ft_itoa.c ft_nbrlen.c ft_putnwstr.c ft_strdup.c \
ft_strncmp.c ft_strtrim.c ft_mallocheck.c ft_putbuffer.c ft_putstr.c \
ft_strequ.c ft_strncpy.c ft_tolower.c ft_filltab.c ft_strjoinsep.c \
ft_strtronc.c

PRINT = ft_print_char.c \
	ft_print_string.c \
	ft_print_hex.c \
	ft_print_oct.c \
	ft_print_int.c \
	ft_print_uint.c \
	ft_print_uo.c \
	ft_print_ptr.c \
	ft_print_inv.c

SRCS = $(addprefix $(SRC_PATH)/, $(SOURCES))
LIBS = $(addprefix $(LIB_PATH)/, $(LIB))
PNT = $(addprefix $(PRINT_PATH)/, $(PRINT))

OBJS = $(addprefix $(OBJ_PATH)/, $(SOURCES:.c=.o))
OBJL = $(addprefix $(OBJ_PATH)/, $(LIB:.c=.o))
OBJP = $(addprefix $(OBJ_PATH)/, $(PRINT:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(OBJL) $(OBJP)
	@ar rc $(NAME) $(OBJS) $(OBJL) $(OBJP)
	@ranlib $(NAME)
	@echo "Compilation libft.a OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(LIB_PATH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(PRINT_PATH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
