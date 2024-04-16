OBJS	= ajout.o deledu.o edumantui.o edusearch.o modedu.o sortedu.o fxport.o main.o searchone.o
SOURCE	= ajout.c deledu.c edumantui.c edusearch.c modedu.c sortedu.c fxport.c main.c searchone.c
HEADER	= filemanip.h srchfuncs.h ajoutfuncs.h delfuncs.h eduStruct.h modfuncs.h sortfuncs.h tui.h
SRCDIR	:= src
BUILDDIR := obj
TARGETDIR := bin
OUT	= eduman.out
FLAGS	= -g -c -Wall
LFLAGS	=
CC	= gcc

all:	eduman.out

directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

eduman.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

ajout.o: ajout.c
	$(CC) $(FLAGS) ajout.c

deledu.o: deledu.c
	$(CC) $(FLAGS) deledu.c

edumantui.o: edumantui.c
	$(CC) $(FLAGS) edumantui.c

edusearch.o: edusearch.c
	$(CC) $(FLAGS) edusearch.c

modedu.o: modedu.c
	$(CC) $(FLAGS) modedu.c

sortedu.o: sortedu.c
	$(CC) $(FLAGS) sortedu.c

fxport.o: fxport.c
	$(CC) $(FLAGS) fxport.c

main.o: main.c
	$(CC) $(FLAGS) main.c

searchone.o: searchone.c
	$(CC) $(FLAGS) searchone.c

clean:
	rm -f $(OBJS) $(OUT)
