BIN:=\
	logger \
	pipe1 \
	pipe2 \
	reader

CFLAGS	?= -Wall -Werror

.PHONY: all clean

all: $(BIN)
	sh ./test.sh

clean:
	rm -f $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@
