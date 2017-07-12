PROJDIRS := include/kernel kernel arch/i386
SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
ASMFILES := $(shell find $(PROJDIRS) -type f -name "*.s")
LNKFILES := $(shell find $(PROJDIRS) -type f -name "*.ld")
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES))
AOBFILES := $(patsubst %.s,%.o, $(ASMFILES))
WARNINGS := -Wall -Wextra
CFLAGS := -g -std=c99 -ffreestanding $(WARNINGS)
CC := i686-elf
.PHONY: all clean headers

all: $(SRCFILES)
	$(CC)-gcc $(CFLAGS) -c $(SRCFILES) -o $(OBJFILES)
	$(CC)-as -c $(ASMFILES) -o $(AOBFILES)
	$(CC)-gcc -T arch/i386/linker.ld -o testos.bin -ffreestanding -O2 -nostdlib $(OBJFILES) $(AOBFILES)

clean: 
	rm -f $(OBJFILES)
	rm -f $(AOBFILES)
	rm -f testos.bin
	
headers:
	cp -R include/. $(SYSROOT)/usr/include/.

