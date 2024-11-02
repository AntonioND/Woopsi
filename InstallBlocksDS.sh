#!/bin/sh

cd Woopsi/libwoopsi
make -f Makefile.blocksds -j`nproc` install
