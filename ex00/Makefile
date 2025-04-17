CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 $(INCLUDEDIR)
SRCS=./src/main.cpp src/BitcoinExchange.cpp src/ExchangeRate.cpp
NAME=btc
OBJS=$(SRCS:.cpp=.o)
INCLUDEDIR=-Iinclude

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
