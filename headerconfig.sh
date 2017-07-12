#!/bin/bash
mkdir -p sysroot/usr/include
export SYSROOT="$(pwd)/sysroot"

(cd kernel && make headers)
