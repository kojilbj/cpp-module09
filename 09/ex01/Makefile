CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 $(INCLUDEDIR)
SRCS=./src/main.cpp ./src/RPN.cpp
NAME=RPN
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
