CC=gcc
CFLAGS=-g -Wall -Wextra
PROJ=proj_06
SOURCES=signal_handling.c signal_handling_utils.c
OBJECTS=$(SOURCES:.c=.o)
TARGET=signal_handling
all: $(PROJ).zip $(TARGET)
$(PROJ).zip: readme.md makefile $(SOURCES) *.h
	zip $@ $^
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(PROJ).zip $(TARGET) $(OBJECTS)
