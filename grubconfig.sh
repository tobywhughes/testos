#!/bin/bash

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "testos" {
	multiboot /boot/testos.bin
}
EOF
cp kernel/testos.bin isodir/boot/testos.bin
grub-mkrescue -o testos.iso isodir
