TARGET   = r_type

CC       = g++

SRC	 =	main.cpp	\
	   Game.cpp \
	   Select.cpp \
	   Action.cpp \
	   MsgHandler.cpp \
	   EntityContainer.cpp \
		../../common/network/Packet.cpp	\
		../../common/network/UnixSocket.cpp	\
		../../common/network/WindowsSocket.cpp

CFLAGS   = -Iinclude -I../common/network/include -I./game_engine/include -I../common/tools -L. -std=c++11 
#-W -Wall -Werror -ansi -pedantic 
SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm	 = rm -rf
mkdir	 = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) -lgame_engine -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lpthread -g
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compilated !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all	: $(TARGET)

game_engine	:
	(cd game_engine; make re)
	(mv game_engine/libgame_engine.so .)

client: $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean	: clean
	@$(rm) $(TARGET)
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re	: fclean all

.PHONY: all clean fclean re
