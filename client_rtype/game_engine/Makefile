TARGET   = libgame_engine.so

CC       = g++

SRC	 = 	window.cpp	\
		spacecraft.cpp	\
		spacecraftPlayer.cpp	\
		spacecraftEntities.cpp	\
		world.cpp	\
		particles.cpp	\
		time.cpp		\
		scroller.cpp	\
		music.cpp		\
		sound.cpp		\
		laser.cpp		\
		
CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude -std=c++11 -shared -fPIC

LDFLAGS	= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
	
SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm	 = rm -rf
mkdir	 = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compilated !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all	: $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean	: clean
	@$(rm) $(TARGET)
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re	: fclean all

.PHONY: all clean fclean re
