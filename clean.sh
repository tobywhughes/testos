#!/bin/bash

(cd kernel && make clean)
rm -f kernel/*.bin
rm -f *.iso
rm -r isodir
rm -r sysroot
