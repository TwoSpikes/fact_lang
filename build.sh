#!/bin/sh

cmake ./build -B ./build
cmake --build ./build $@
mv ./build/fact_lang $PREFIX/bin/
