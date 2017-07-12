#!/bin/bash

i686-elf-as kernel/arch/i386/boot.s -o boot.o
echo "Assembly Compiled"
i686-elf-gcc -c kernel/kernel/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
echo "Kernel Compiled"
i686-elf-gcc -T kernel/arch/i386/linker.ld -o testos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
