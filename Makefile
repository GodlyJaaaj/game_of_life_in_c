##
## EPITECH PROJECT, 2023
## game_of_life_in_c
## File description:
## Makefile
##

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CC				:= gcc
CFLAGS 			:= -c -Wall
LDFLAGS 		:= -lncurses
DEBUG_FLAGS		:= -g -g3
INCLUDES 		:= -I./includes
EXECUTABLE		:= game_of_life

SOURCES_FILES 	:= $(call rwildcard,src/,*.c)
OBJECTS_FILES 	:= $(SOURCES_FILES:.c=.o)

SOURCES_LIB_FILES 	:= $(call rwildcard,lib/,*.c)
OBJECTS_LIB_FILES 	:= $(SOURCES_LIB_FILES:.c=.o)

GCNO_FILES 		:= $(call rwildcard,./,*.gcno)
GCDA_FILES 		:= $(call rwildcard,./,*.gcda)

all: $(SOURCES_FILES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS_FILES) $(OBJECTS_LIB_FILES)
	$(CC) $(LDFLAGS) $(OBJECTS_FILES) $(OBJECTS_LIB_FILES) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS_FILES)
	rm -f $(OBJECTS_LIB_FILES)

fclean: clean
	rm -f $(EXECUTABLE)
	rm -f test_$(EXECUTABLE)

debug: LDFLAGS += $(DEBUG_FLAGS)
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean debug re
