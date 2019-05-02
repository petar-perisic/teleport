PROGRAM = TelePort
CC      = gcc
CFLAGS  = -c -std=c99 -Wall -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

SRC = src/main.c src/controls.c src/display.c src/robot.c src/map.c src/materials.c src/collisions.c
OBJ = main.o display.o controls.o robot.o map.o materials.o collisions.o

$(PROGRAM): $(OBJ)
	$(CC) $(OBJ) -o $(PROGRAM) $(LDLIBS)

main.o: $(SRC)
	$(CC) $(LDFLAGS) $(CFLAGS) $(SRC) $(LDLIBS)

display.o: src/display.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/display.c $(LDLIBS)

controls.o: src/controls.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/controls.c $(LDLIBS)

robot.o: src/robot.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/robot.c $(LDLIBS)

map.o: src/map.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/map.c $(LDLIBS)

src/materials.o: src/materials.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/materials.c $(LDLIBS)

src/collisions.o: src/collisions.c
	$(CC) $(LDFLAGS) $(CFLAGS) src/collisions.c $(LDLIBS)

.PHONY: clean

clean:
	rm -rf *.o $(PROGRAM)
