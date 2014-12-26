SRC = src/
HPP = hpp/
OBJ = obj/

SRCS = $(wildcard $(SRC)*.cpp)
OBJS = $(addprefix $(OBJ),$(notdir $(SRCS:.cpp=.o)))

FLAGS = -I $(HPP)
CC = g++ $(FLAGS)


all: main

main: $(OBJS)
	$(CC) -o $@ $^

$(OBJ)%.o: $(SRC)%.cpp $(HPP)%.hpp
	$(CC) -c -o $@ $<

$(OBJ)SimpleCard.o: $(HPP)Card.hpp

clean: clear
	rm main

clear:
	rm -rf $(OBJ)*.o $(SRC)*~ $(HPP)*~
