#!/bin/bash

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "myos" {
	multiboot /boot/myos.kernel
}
EOF
cp testos.bin isodir/boot/myos.bin
grub-mkrescue -o testos.iso isodir
