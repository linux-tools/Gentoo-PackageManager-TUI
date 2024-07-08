CC=gcc
OBJS=main.o package.o
CFLAGS=-c -Wall -g
BINDIR=/usr/bin
gentoo-packagemanager:$(OBJS)
	$(CC) $(OBJS) -o gentoo-packagemanager

main.o:main.c
	$(CC) main.c $(CFLAGS) -o main.o
package.o:package.c
	$(CC) package.c $(CFLAGS) -o package.o

clean:
	$(RM) *.o gentoo-packagemanager -r
install:
	install -d $(BINDIR)
	install -m 0755 gentoo-packagemanager $(BINDIR)
	env-update
	. /etc/profile
clean_excess_files:
	$(RM) *.o
uninstall:
	rm $(BINDIR)/gentoo-packagemanager
	env-update
	. /etc/profile
