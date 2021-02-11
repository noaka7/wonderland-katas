objects=alphabet_cipher test

all: $(objects)

alphabet_cipher: alphabet_cipher.c
	gcc -c -o $@ $<

test: alphabet_cipher.c test.c
	gcc -o $@ $^

.PHONY: clean

clean:
	-rm $(objects)
