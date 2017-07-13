#!/bin/bash
export SYSROOT="$(pwd)/sysroot"
(cd kernel && make all)
