NAME		:=	libftprintf.a

SRCS		:=	ft_print_char_str.c \
			ft_print_hex_ptr.c \
        	ft_print_numbers.c \
        	ft_printf.c

OBJS		:= $(SRCS:.c=.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I.

RM			:= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re