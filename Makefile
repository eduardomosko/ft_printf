NAME :=	libftprintf.a

PRINTERS := ft_putchr.c \
			ft_puthex.c \
			ft_putint.c

SRCS :=	ft_printf.c \
		$(addprefix ./printers/,$(PRINTERS))

OBJS :=	$(SRCS:.c=.o)
HEADERS := ft_printf.h


all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERS)
	gcc $< -c -o $@


.PHONY: all clean fclean re
