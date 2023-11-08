CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = 

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: run
run: $(NAME)
	./$(NAME)

.PHONY: test
test: $(NAME)
	@TARGET=$(NAME) ./tests.sh
