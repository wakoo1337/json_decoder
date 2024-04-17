.PHONY: all clean
CFLAGS=-c -Wall -g -O0
all: bin/json_decoder
bin/json_decoder: bin/liboj.a bin/avl.o bin/json_decoder.o bin/json_push.o bin/json_pop.o bin/compareElements.o bin/state_start.o bin/state_noninteresting.o bin/state_array.o bin/state_packet.o bin/state_source.o bin/state_layers.o bin/state_protocol.o bin/myItoA.o
	$(CC) -o bin/json_decoder bin/json_decoder.o bin/json_push.o bin/json_pop.o bin/avl.o bin/liboj.a bin/compareElements.o bin/state_start.o bin/state_noninteresting.o bin/state_array.o bin/state_packet.o bin/state_source.o bin/state_layers.o bin/state_protocol.o bin/myItoA.o
bin/json_decoder.o: src/json_decoder.c src/contrib/oj/oj.h src/contrib/avl.h src/json_push.h src/json_pop.h src/Element.h src/Context.h src/compareElements.h src/state_start.h
	$(CC) $(CFLAGS) -o bin/json_decoder.o src/json_decoder.c
bin/json_push.o: src/json_push.c src/json_push.h src/contrib/oj/oj.h src/Context.h
	$(CC) $(CFLAGS) -o bin/json_push.o src/json_push.c
bin/json_pop.o: src/json_pop.c src/json_pop.h src/contrib/oj/oj.h src/Context.h src/state_packet.h
	$(CC) $(CFLAGS) -o bin/json_pop.o src/json_pop.c
bin/avl.o: src/contrib/avl.c src/contrib/avl.h
	$(CC) $(CFLAGS) -o bin/avl.o src/contrib/avl.c
bin/compareElements.o: src/compareElements.c src/compareElements.h src/Element.h
	$(CC) $(CFLAGS) -o bin/compareElements.o src/compareElements.c
bin/state_start.o: src/state_start.c src/state_start.h src/Context.h src/state_noninteresting.h src/state_array.h
	$(CC) $(CFLAGS) -o bin/state_start.o src/state_start.c
bin/state_noninteresting.o: src/state_noninteresting.c src/Context.h src/state_noninteresting.h src/state_noninteresting.h
	$(CC) $(CFLAGS) -o bin/state_noninteresting.o src/state_noninteresting.c
bin/state_array.o: src/state_array.c src/state_array.h src/Context.h src/state_packet.h src/state_noninteresting.h
	$(CC) $(CFLAGS) -o bin/state_array.o src/state_array.c
bin/state_packet.o: src/state_packet.c src/state_packet.h src/Context.h src/state_source.h src/state_noninteresting.h
	$(CC) $(CFLAGS) -o bin/state_packet.o src/state_packet.c
bin/state_source.o: src/state_source.c src/state_source.h src/Context.h
	$(CC) $(CFLAGS) -o bin/state_source.o src/state_source.c
bin/state_layers.o: src/state_layers.c src/state_layers.h src/Context.h src/state_protocol.h src/state_noninteresting.h
	$(CC) $(CFLAGS) -o bin/state_layers.o src/state_layers.c
bin/state_protocol.o: src/state_protocol.c src/state_protocol.h src/contrib/avl.h src/Context.h src/state_noninteresting.h src/Element.h src/myItoA.h
	$(CC) $(CFLAGS) -o bin/state_protocol.o src/state_protocol.c
bin/myItoA.o: src/myItoA.c src/myItoA.h
	$(CC) $(CFLAGS) -o bin/myItoA.o src/myItoA.c
clean:
	rm -rvf bin/*
