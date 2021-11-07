TARGET := launcher
CC := g++

CSRCS := ${wildcard *.cpp}

OBJS := $(patsubst %.cpp, %.o, $(CSRCS))

INC := -I ./ -I ./include

LIBS := -L . -lpthread -lm

$(TARGET): $(OBJS)
	$(CC) $^ $(LIBS) -o $@
	rm -rf $(OBJS)

%.0:%.cpp
	$(CC) -c $< $(INC) -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(TARGET)