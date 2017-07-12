#!/bin/bash

(cd kernel && make clean)
rm -f *.iso
rm -r isodir
rm -r sysroot
