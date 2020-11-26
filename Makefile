all: install

sharedobj: linked_list.c linked_list.h
	gcc -c -fpic linked_list.c
	gcc -shared -o liblinked_list.so linked_list.o
	rm linked_list.o

install: sharedobj
	install -C liblinked_list.so ~/.local/lib
	install -C linked_list.h ~/.local/include

clean:
	rm -f liblinked_list.so
