#!/bin/bash
export SYSROOT="$(pwd)/sysroot"
(cd libc && make all)
(cd kernel && make all)
