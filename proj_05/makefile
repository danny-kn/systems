CC=gcc
CFLAGS=-g -Wall -Wextra
LDFLAGS=-pthread
PROJ=proj_05
SOURCES=bounded_buf.c bounded_buf_utils.c
OBJECTS=$(SOURCES:.c=.o)
TARGET=bounded_buf
all: $(PROJ).zip $(TARGET)
$(PROJ).zip: readme.md makefile $(SOURCES) *.h
	zip $@ $^
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(PROJ).zip $(TARGET) $(OBJECTS)
