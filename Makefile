iCFLAGS := -std=c11 -Wall -Werror -ggdb -O0

SOURCES := $(wildcard *.c)
OBJS := $(SOURCES:%.c=%.o)

TARGET := elevator

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

#.PRECIOUS : qsort_lib.o

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJS)
