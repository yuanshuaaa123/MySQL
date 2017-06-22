CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi addsc.cgi delsc.cgi modsc.cgi selsc.cgi adds.cgi dels.cgi mods.cgi sels.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi
install:
	cp *.cgi /usr/lib/cgi-bin/sx
	sudo cp index.html /var/www/html
	sudo cp info.html /var/www/html
	sudo cp score.html /var/www/html
	sudo cp school.html /var/www/html
	cp head.html foot.html /usr/lib/cgi-bin/sx
