SRC = src/
HPP = hpp/
OBJ = obj/

SRCS = $(wildcard $(SRC)*.cpp)
OBJS = $(addprefix $(OBJ),$(notdir $(SRCS:.cpp=.o)))

FLAGS =
CC = g++ $(FLAGS)


all: main

main: $(OBJS)
	$(CC) -o $@ $^

$(OBJ)%.o: $(SRC)%.cpp
	$(CC) -c -o $@ $<

clean: clear
	rm main

clear:
	rm -rf $(OBJ)*.o $(SRC)*~
