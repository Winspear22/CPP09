NAME= RPN
SRCS= main.cpp RPN.cpp
INCLUDE= . 

OBJS		=		$(SRCS:.cpp=.o)
DEPS		=		$(SRCS:.cpp=.d)

CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98 -g3

%.o:				%.cpp
	@$(CC) $(CFLAGS) -MMD -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32mCompilation du programme \033[1;37m$(NAME)\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "\033[1;31mSuppression du programme \033[1;37m$(NAME)\033[0m"
	rm -Rf $(OBJS) $(DEPS)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

-include $(DEPS)
.PHONY: all clean fclean re