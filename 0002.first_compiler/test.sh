#!/bin/bash

try() {
        expected="$1"
        input="$2"

        ./yocc.out "$input" > tmp.s
        gcc -o tmp.out tmp.s
        ./tmp.out
        actual="$?"

        if [ "$actual" = "$expected" ]; then
            echo "$input => $actual"
        else
            echo "$input => $expected expected, but got $actual"
            exit 1
        fi
}

try 0 0
try 42 42

echo OK
