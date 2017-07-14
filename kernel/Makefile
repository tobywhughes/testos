PROJDIRS := include/kernel kernel arch/i386
SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
ASMFILES := $(shell find $(PROJDIRS) -type f -name "*.s")
LNKFILES := $(shell find $(PROJDIRS) -type f -name "*.ld")
OBJFILES := $(patsubst %.c,%.o, $(SRCFILES))
AOBFILES := $(patsubst %.s,%.o, $(ASMFILES))
OCDFILES := $(patsubst %.o,%.d, $(OBJFILES))
OADFILES := $(patsubst %.o,%.d, $(AOBFILES))
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align\
	    -Wwrite-strings \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
	    -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS := -g -std=c99 -ffreestanding $(WARNINGS)
CC := i686-elf
.PHONY: all clean headers

all: $(OBJFILES) $(AOBFILES)
	$(CC)-gcc -T arch/i386/linker.ld -o testos.bin -ffreestanding -O2 -nostdlib $(OBJFILES) $(AOBFILES)

%.o: %.c	
	$(CC)-gcc -MD --sysroot=$(SYSROOT) -isystem=/usr/include  $(CFLAGS) -c $< -o $@
%.o: %.s
	$(CC)-as -c $< -o $@

clean: 
	rm -f $(OBJFILES)
	rm -f $(AOBFILES)
	rm -f $(OCDFILES)
	rm -f $(OADFILES)
	
headers:
	cp -R include/. $(SYSROOT)/usr/include/.
-include $(OBJFILES:.o=.d)
