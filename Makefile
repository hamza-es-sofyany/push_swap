NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c \
	parsing/parse_number.c \
	parsing/parse_args.c \
	parsing/check_input.c \
	parsing/parse_options.c \
	stack/stack_init.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	operations/operation_output.c \
	benchmark/benchmark.c \
	benchmark/benchmark_options.c \
	benchmark/benchmark_report.c \
	benchmark/disorder.c \
	benchmark/operation_count.c \
	benchmark/strategy_select.c \
	sorting/simple_sort.c \
	sorting/medium_sort.c \
	sorting/complex_sort.c \
	sorting/strategy_execute.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_char.c \
	ft_printf/ft_printf_hex.c \
	ft_printf/ft_printf_number.c \
	ft_printf/ft_printf_pointer.c \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstclear.c \
	libft/ft_lstdelone.c \
	libft/ft_lstiter.c \
	libft/ft_lstlast.c \
	libft/ft_lstmap.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re