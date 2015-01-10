SRC = src/
HPP = hpp/
OBJ = obj/

SRCS = $(wildcard $(SRC)*.cpp)
OBJS = $(addprefix $(OBJ),$(notdir $(SRCS:.cpp=.o)))

FLAGS = -I $(HPP) -Wall
CC = g++ $(FLAGS)


all: main

main: $(OBJS)
	$(CC) -o $@ $^

$(OBJ)%.o: $(SRC)%.cpp $(HPP)%.hpp
	$(CC) -c -o $@ $<

$(OBJ)CanRemovePile.o:	  $(addprefix $(HPP), CardContainer.hpp Movement.hpp)
$(OBJ)FrenchCard.o:	  $(addprefix $(HPP), SimpleCard.hpp)
$(OBJ)SimpleCard.o:	  $(addprefix $(HPP), Card.hpp)
$(OBJ)Pioche.o:		  $(addprefix $(HPP), CardContainer.hpp)
$(OBJ)CardContainer.o:	  $(addprefix $(HPP), Card.hpp )
$(OBJ)Action.o:		  $(addprefix $(HPP), CardContainer.hpp CanAddRemovePile.hpp CanAddPile.hpp Movement.hpp)
$(OBJ)Game.o:		  $(addprefix $(HPP), Deck.hpp Players.hpp DiscardPile.hpp)
$(OBJ)Melange.o:	  $(addprefix $(HPP), Card.hpp)
$(OBJ)CanAddPile.o:	  $(addprefix $(HPP), CardContainer.hpp)
$(OBJ)DiscardPile.o:	  $(addprefix $(HPP), Card.hpp CardContainer.hpp CanAddPile.hpp)
$(OBJ)Hand.o:		  $(addprefix $(HPP), CanAddRemovePile.hpp CardContainer.hpp Card.hpp Movement.hpp)
$(OBJ)CanAddRemovePile.o: $(addprefix $(HPP), CanAddPile.hpp CanRemovePile.hpp)
$(OBJ)Bataille.o:	  $(addprefix $(HPP), Game.hpp)
$(OBJ)Players.o:	  $(addprefix $(HPP), Deck.hpp Player.hpp Action.hpp)
$(OBJ)Deck.o:		  $(addprefix $(HPP), Melange.hpp Card.hpp)
$(OBJ)Human.o:		  $(addprefix $(HPP), Player.hpp Action.hpp)
$(OBJ)Player.o:		  $(addprefix $(HPP), Card.hpp Hand.hpp Action.hpp)

clean: clear
	rm -f main

clear:
	rm -rf $(OBJ)*.o $(SRC)*~ $(HPP)*~
