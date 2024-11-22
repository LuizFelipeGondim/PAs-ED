OBJDIR = obj
BINDIR = bin
SRCDIR = src

OBJS = $(OBJDIR)/matop.o $(OBJDIR)/mat.o

$(BINDIR)/matop: $(OBJS)
	gcc -Wall -Iinclude -o $@ $^

$(OBJDIR)/matop.o: $(SRCDIR)/matop.c $(SRCDIR)/mat.c
	gcc -Wall -Iinclude -c $(SRCDIR)/matop.c -o $(OBJDIR)/matop.o

$(OBJDIR)/mat.o: $(SRCDIR)/mat.c
	gcc -Wall -Iinclude -c $(SRCDIR)/mat.c -o $(OBJDIR)/mat.o

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/matop

run: $(BINDIR)/matop
	./$(BINDIR)/matop -s -x 5 -y 5
	./$(BINDIR)/matop -m -x 5 -y 5
	./$(BINDIR)/matop -t -x 5 -y 5

