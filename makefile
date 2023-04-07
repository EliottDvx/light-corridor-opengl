CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lglfw -lGLU -lGL -lm

BINDIR	= bin/
INCDIR	= inc/
SRCDIR	= src/
OBJDIR	= obj/

# Fichiers TD 04
GLOB_OBJ_TD= $(OBJDIR)3D_tools.o

# Fichiers exercice 01
OBJ_TD04_EX01= $(GLOB_OBJ_TD) $(OBJDIR)ex01/draw_scene.o $(OBJDIR)ex01/td04_ex01.o
EXEC_TD04_EX01= td04_ex01.out

# Fichiers exercice 02
OBJ_TD04_EX02= $(GLOB_OBJ_TD) $(OBJDIR)ex02/draw_scene.o $(OBJDIR)ex02/td04_ex02.o
EXEC_TD04_EX02= td04_ex02.out

# Regles compilation TD 04

all : ex01, ex02

ex01 : $(OBJ_TD04_EX01)
	$(CC) $(CFLAGS) $(OBJ_TD04_EX01) -o $(BINDIR)$(EXEC_TD04_EX01) $(LDFLAGS)

ex02 : $(OBJ_TD04_EX02)
	$(CC) $(CFLAGS) $(OBJ_TD04_EX02) -o $(BINDIR)$(EXEC_TD04_EX02) $(LDFLAGS)

clean :
	rm -rf *~
	rm -rf $(SRCDIR)*/*~
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)*

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)*.h
	mkdir -p `dirname $@`
	$(CC) -o $@ -I $(INCDIR) -c $< $(CFLAGS)
