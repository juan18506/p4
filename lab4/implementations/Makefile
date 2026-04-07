.PHONY: all clean

CC := g++
CFLAGS := -Wall

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(OBJS)
	$(MAKE) -C controladores
	$(MAKE) -C manejadores
	$(MAKE) -C datatypes
	rm -f implementations.o
	ld -r -o implementations.o controladores/controladores.o manejadores/manejadores.o datatypes/datatypes.o *.o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o
	$(MAKE) -C controladores clean
	$(MAKE) -C manejadores clean
	$(MAKE) -C datatypes clean
