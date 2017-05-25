
all:
	gcc -shared src/alectrona.c -lncurses -o libalectrona.so
	gcc -L. -Iinclude test/main.c -o test_alectrona -lalectrona

clean:
	rm -f test_alectrona
	rm -f libalectrona.so

