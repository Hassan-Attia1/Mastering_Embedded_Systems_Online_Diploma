#Author: Hassan Attia

CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name=learn-in-depth

all: $(Project_Name).bin
	@echo "*******Build is Done********"
	
$(Project_Name).bin: $(Project_Name).elf

	$(CC)objcopy.exe -O binary $< $@
	
$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker-script.ld $(LIBS) -Map=Map_file.txt $(OBJ) $(AsOBJ) -o $@

	
%.o: %.c
	$(CC)gcc.exe $(FLAGS) -c $(INCS) $< -o $@
	

startup.o: startup.s
	$(CC)as.exe $(FLAGS)  $< -o $@ 
	
clean:
	rm *.o

clean_all:
	rm *.o *.elf *.bin *.txt
	