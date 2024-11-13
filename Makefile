CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -g -O0 -Wall
LDFLAGS = -nostartfiles -T linker.ld

SRC = startup.c bootloader.c uart.c system.c
OBJ = $(SRC:.c=.o)
TARGET = bootloader.elf

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(TARGET)

run: $(TARGET)
		qemu-system-arm -M lm3s6965evb -cpu cortex-m3 -nographic -kernel $(TARGET)