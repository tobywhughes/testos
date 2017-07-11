#!/bin/bash

cp testos.bin isodir/boot/myos.bin
grub-mkrescue -o testos.iso isodir
