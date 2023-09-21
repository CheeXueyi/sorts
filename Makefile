CC = clang
CFLAGS = -Wall -Werror -g

asan: CFLAGS += -fsanitize=address,undefined,leak
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

all: merge quick bubble insertion selection

merge: merge.c
	$(CC) $(CFLAGS) -o merge merge.c

quick: quick.c
	$(CC) $(CFLAGS) -o quick quick.c

bubble: bubble.c
	$(CC) $(CFLAGS) -o bubble bubble.c

insertion: insertion.c
	$(CC) $(CFLAGS) -o insertion insertion.c

selection: selection.c
	$(CC) $(CFLAGS) -o selection selection.c

clean:
	rm -f merge quick bubble insertion selection