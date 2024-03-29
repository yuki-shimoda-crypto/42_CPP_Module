CXX = c++

# 基本のコンパイルフラグ
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
#CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98

# デバッグビルド用のコンパイルフラグ
CXXFLAGS_DEBUG = $(CXXFLAGS) -g -fsanitize=address -fsanitize=leak -fsanitize=undefined

# リンカフラグ
#LDFLAGS =
#LDFLAGS_DEBUG = -g -fsanitize=address -fsanitize=leak -fsanitize=undefined

NAME =  btc
NAME_DEBUG = $(NAME)_debug

SRCS =  BitcoinExchange.cpp \
        main.cpp

OBJS = $(SRCS:.cpp=.o)
OBJS_DEBUG = $(SRCS:.cpp=.debug.o)

HEADERS = BitcoinExchange.hpp

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: $(NAME_DEBUG)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(NAME_DEBUG): $(OBJS_DEBUG)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $(OBJS_DEBUG) 

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.debug.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_DEBUG)

.PHONY: fclean
fclean: clean
	rm -f $(NAME) $(NAME_DEBUG)

.PHONY: re
re: fclean all

.PHONY: run
run: $(NAME)
	./$(NAME) input.txt

.PHONY: run_debug
run_debug: $(NAME_DEBUG)
	./$(NAME_DEBUG) input.txt

.PHONY: test
test: $(NAME)
	@TARGET=$(NAME) ./tests.sh

.PHONY: test_debug
test_debug: $(NAME_DEBUG)
	@TARGET=$(NAME_DEBUG) ./tests.sh
