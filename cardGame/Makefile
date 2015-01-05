SRC = src/
HPP = hpp/
OBJ = obj/

SRCS = $(wildcard $(SRC)*.cpp)
OBJS = $(addprefix $(OBJ),$(notdir $(SRCS:.cpp=.o)))

FLAGS = -I $(HPP) -std=c++11
CC = g++ $(FLAGS)


all: main

main: $(OBJS)
	$(CC) -o $@ $^

$(OBJ)%.o: $(SRC)%.cpp $(HPP)%.hpp
	$(CC) -c -o $@ $<

$(OBJ)SimpleCard.o: $(addprefix $(HPP), Card.hpp)
$(OBJ)Deck.o: $(addprefix $(HPP), SimpleCard.hpp FrenchCard.hpp)

clean: clear
	rm -f main

clear:
	rm -rf $(OBJ)*.o $(SRC)*~ $(HPP)*~
