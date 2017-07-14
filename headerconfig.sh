#!/bin/bash
mkdir -p sysroot/usr/include
mkdir -p sysroot/usr/lib
export SYSROOT="$(pwd)/sysroot"
(cd libc && make headers && make install-lib)
(cd kernel && make headers)
