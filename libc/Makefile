PROJDIRS := include string
SRCFILES := $(shell find $(PROJDIRS) -type f -name "*.c")
OBJFILES := $(patsubst %.c,%.o, $(SRCFILES))
OCDFILES := $(patsubst %.o,%.d, $(OBJFILES))
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align\
	    -Wwrite-strings \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
	    -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS := -g -std=c99 -ffreestanding $(WARNINGS)
CC := i686-elf
.PHONY: all clean headers

BINARIES := libk.a

LIBKOBJS := $(OBJFILES:.o=.libk.o)

all: $(OBJFILES)

%.o: %.c	
	$(CC)-gcc -MD --sysroot=$(SYSROOT) -isystem=/usr/include  $(CFLAGS) -c $< -o $@

libk.a: $(LIBKOBJS)
	$(CC)-ar rcs $@ $(LIBKOBJS)

%.libk.o: %.c
	$(CC)-gcc -MD --sysroot=$(SYSROOT) -isystem=/usr/include -c $< -o $@

clean: 
	rm -f $(OBJFILES)
	rm -f $(AOBFILES)
	rm -f $(OCDFILES)
	rm -f $(OADFILES)
	
headers:
	cp -R include/. $(SYSROOT)/usr/include/.

install-lib: $(BINARIES)
	cp -R $(BINARIES) $(SYSROOT)/usr/lib

-include $(OBJFILES:.o=.d)
-include $(LIBKOBJS:.o=.d )
