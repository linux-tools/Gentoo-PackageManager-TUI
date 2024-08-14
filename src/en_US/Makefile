CC=gcc
OBJS=main.o portage_package_function.o main_function.o portage_manage.o main_menu.c
CFLAGS=-c -Wall -g
BINDIR=/usr/bin
genpkg-en:$(OBJS)
	$(CC) $(OBJS) -o genpkg-en

main.o:main.c
	$(CC) main.c $(CFLAGS) -o main.o
portage_package_function.o:portage_package_function.c
	$(CC) portage_package_function.c $(CFLAGS) -o portage_package_function.o
main_function.o:main_function.c
	$(CC) main_function.c $(CFLAGS) -o main_function.o
main_menu.o:main_menu.c
	$(CC) main_menu.c $(CFLAGS) -o main_menu.o
portage_manage.o:portage_manage.c
	$(CC) portage_manage.c $(CFLAGS) -o portage_manage.o

clean:
	$(RM) *.o genpkg-en -r
install:
	@install -d $(BINDIR)
	@install -m 0755 genpkg-en $(BINDIR)
	@. /etc/profile
clean_excess_files:
	$(RM) *.o
uninstall:
	@rm $(BINDIR)/genpkg-en
	@. /etc/profile
