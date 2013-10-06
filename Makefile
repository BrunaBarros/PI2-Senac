CC=gcc -std=c99
CFLAGS = -W -Wall
EXEC = main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
LIBS=-lallegro -lallegro_audio -lallegro_acodec -lallegro_image -lallegro_font -lallegro_main -lallegro_ttf -lallegro_primitives

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# $< está pegando a dependência mais recente.
%.o:%.c
	$(CC) -c $@ -o $< $(CFLAGS)

# .PHONY: clean

# clean:
# rm -rf *.o
 	