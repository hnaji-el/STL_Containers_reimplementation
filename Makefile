
VECTOR = vector
STACK = stack
MAP = map
SET = set

NAME = vector

SRC_VECTOR = ./vector/main.cpp
HEADERS_VECTOR = ./vector/vector.hpp \
				 ./vector/vector.tpp \
				 ./vector/vector_iterator.hpp \
				 ./vector/vector_iterator.tpp

SRC_STACK = ./stack/main.cpp
HEADERS_STACK = ./stack/stack.hpp

SRC_MAP = ./map/main.cpp
HEADERS_MAP = ./map/map.hpp ./map/map.tpp \
			  ./map/avl_tree.hpp ./map/avl_tree.tpp \
			  ./map/avl_node.hpp ./map/avl_node.tpp \
			  ./map/map_iterator.hpp ./map/map_iterator.tpp

SRC_SET = ./set/main.cpp
HEADERS_SET = ./set/set.hpp ./set/set.tpp \
			  ./set/rb_tree.hpp ./set/rb_tree.tpp \
			  ./set/node.hpp ./set/node.tpp \
			  ./set/set_iterator.hpp ./set/set_iterator.tpp

COMPILER = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME) $(STACK) $(MAP) $(SET)

$(NAME): $(SRC_VECTOR) $(HEADERS_VECTOR)
	$(COMPILER) $(FLAGS) $(SRC_VECTOR) -o $(NAME)

$(STACK): $(SRC_STACK) $(HEADERS_STACK)
	$(COMPILER) $(FLAGS) $(SRC_STACK) -o $(STACK)

$(MAP): $(SRC_MAP) $(HEADERS_MAP)
	$(COMPILER) $(FLAGS) $(SRC_MAP) -o $(MAP)

$(SET): $(SRC_SET) $(HEADERS_SET)
	$(COMPILER) $(FLAGS) $(SRC_SET) -o $(SET)

clean:
	rm -rf $(VECTOR)
	rm -rf $(STACK)
	rm -rf $(MAP)
	rm -rf $(SET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
