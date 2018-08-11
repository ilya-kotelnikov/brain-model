EXECUTABLE=lab
SOURCES=main.cc

CC=g++
CFLAGS=-c -Wall
LDFLAGS=

OBJECTS=$(SOURCES:%.cc=obj/%.o)

build: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE).exe
	rm -r -f obj

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJECTS): obj/%.o: %.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<
