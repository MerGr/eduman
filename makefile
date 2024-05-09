OBJS	= obj/ajout.o obj/deledu.o obj/edumantui.o obj/edusearch.o obj/modedu.o obj/sortedu.o obj/fxport.o obj/main.o obj/searchone.o
SOURCE	= src/ajout.c src/deledu.c src/edumantui.c src/edusearch.c src/modedu.c src/sortedu.c src/fxport.c src/main.c src/searchone.c
HEADER	= src/filemanip.h src/srchfuncs.h src/ajoutfuncs.h src/delfuncs.h src/eduStruct.h src/modfuncs.h src/sortfuncs.h src/tui.h
SRCDIR	:= src
OBJDIR := obj
BUILDDIR := bin
OUT	= ./$(BUILDDIR)/eduman
FLAGS	= -g -c -Wall
LFLAGS	=
CC	= gcc

all: directories $(OUT)

directories:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(OBJDIR)

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

obj/ajout.o: src/ajout.c
	$(CC) $(FLAGS) src/ajout.c -o obj/ajout.o

obj/deledu.o: src/deledu.c
	$(CC) $(FLAGS) src/deledu.c -o obj/deledu.o

obj/edumantui.o: src/edumantui.c
	$(CC) $(FLAGS) src/edumantui.c -o obj/edumantui.o

obj/edusearch.o: src/edusearch.c
	$(CC) $(FLAGS) src/edusearch.c -o obj/edusearch.o

obj/modedu.o: src/modedu.c
	$(CC) $(FLAGS) src/modedu.c -o obj/modedu.o

obj/sortedu.o: src/sortedu.c
	$(CC) $(FLAGS) src/sortedu.c -o obj/sortedu.o

obj/fxport.o: src/fxport.c
	$(CC) $(FLAGS) src/fxport.c -o obj/fxport.o

obj/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -o obj/main.o

obj/searchone.o: src/searchone.c
	$(CC) $(FLAGS) src/searchone.c -o obj/searchone.o

clean:
	rm -rf $(OBJDIR) $(BUILDDIR)

uninstall:
	rm -rf $(BUILDDIR)