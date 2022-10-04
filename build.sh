#!/bin/sh

if [[ $0 == '' ]];
    set outfile 'main.c.out';
else
    set outfile $0;
export outfile;

clang --std=c2x main.c -o $outfile;
