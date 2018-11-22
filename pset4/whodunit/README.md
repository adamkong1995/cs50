# Questions

## What's `stdint.h`?

This is a header file that includes pre-declared function to share to different c source code.

'stdint.h' declared integer type that had specified width

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

By using the above data types, we can initiates a integer with certain size among different development environment

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

byte = 1
dword = 4
long = 4
word = 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize indicates the size of entire BMP file.
biSize only indicates the size of `info header` of a BMP file

## What does it mean if `biHeight` is negative?

It is because the biHeight measure a BMP file from the top to the bottom

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

when the open file action is failed

## Why is the third argument to `fread` always `1` in our code?

It is because the we knew the size of each part of a BMP, so we can read it in once time

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

'fseek' perform setting the file pointer to certain position according the offset number provided

## What is `SEEK_CUR`?

Indicate the pointer to point at current position

## Whodunit?

Professor Plum
