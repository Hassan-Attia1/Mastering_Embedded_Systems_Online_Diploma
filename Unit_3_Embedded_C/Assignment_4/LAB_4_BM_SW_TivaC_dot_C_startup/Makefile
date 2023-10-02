#Author: Hassan Attia

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name=learn-in-depth_cortex_M4

all: $(Project_Name).bin
	@echo "*******Build is Done********"
	
	
%.o: %.c
	$(CC)gcc.exe  -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project_Name).bin: $(Project_Name).elf

	$(CC)objcopy.exe -O binary $< $@
	
$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker-script.ld $(LIBS) -Map=Map_file.txt $(OBJ) $(AsOBJ) -o $@

	cp $(Project_Name).elf $(Project_Name).axf

	


	
clean:
	rm *.o

clean_all:
	rm *.o *.elf *.bin *.txt
	