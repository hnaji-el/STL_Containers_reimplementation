 
NAME = vector
 
SRCS = main.cpp
 
HEADERS = vector.hpp vector.tpp
 
COMPILER = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror # -g -fsanitize=address

 
all: $(NAME)
 
$(NAME): $(SRCS) $(HEADERS)
	$(COMPILER) $(FLAGS) $(SRCS) -o $(NAME)
 
clean:
	rm -rf $(NAME)
 
fclean: clean
 
re: fclean all
 
.PHONY: all clean fclean re

