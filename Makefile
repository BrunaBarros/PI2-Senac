CC=gcc -std=c99
CFLAGS = -W -Wall
EXEC = main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
FILE_O = $(SRC:.c=.o)
LIBS=-lallegro -lallegro_image -lallegro_font -lallegro_main -lallegro_ttf -lallegro_primitives -lallegro_audio -lallegro_acodec

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS); rm -rf $(FILE_O)

%.o: %.c
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	rm -rf $(OBJ)