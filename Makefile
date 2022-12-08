CC=gcc -Wall -o 
SRC=$(wildcard $(srcdir)*.c)
OBJ=$(subst $(srcdir), $(bindir),$(SRC:.c =.o))
Head=$(SRC:.c=.h)
Exec=prog
sauv=sauvegarde
		

		
all : $(Exec)

$(Exec) : $(OBJ)
		$(CC)  $(Exec) $(OBJ) 
		
main.o :main.c 
		$(CC)  $@ -c $< 
		

%.o: %.c %.h
		$(CC)  $@ -c $< 


clean :
	rm -rf *.o *.bak

mrproper :clean
	rm -rf $(Exec)

save: 
	rm -rf $(sauv)
	mkdir -p $(sauv)
	cp *.c $(sauv)/

cible:
restore:


