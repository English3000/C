# [CS61C Spring 2015 UC Berkeley HW 0](http://inst.eecs.berkeley.edu/~cs61c/sp15/hw/00/hw0.html)

## [Number representation](https://www.mathsisfun.com/binary-decimal-hexadecimal-converter.html)

### Unsigned

DECIMAL | BINARY      | HEXADECIMAL
------- | ----------- | -----------
  10    | 0b0000 1010 | 0x0A
  16    | 0b0001 0000 | 0x10
  15    | 0b0000 1111 | 0x0F
 161    | 0b0000 1111 | 0xA1
 250    | 0b1111 1010 | 0xFA
 255    | 0b1111 1111 | 0xFF
 128    | 0b1000 0000 | 0x80
 105    | 0b0110 1001 | 0x69

### Signed

DECIMAL | BINARY      | HEXADECIMAL
------- | ----------- | -----------
 -10    | 0b1111 0110 | 0x0A
 -16    | 0b1111 0000 | 0xF0
  15    | 0b0000 1111 | 0x0F
 -95    | 0b1010 0001 | 0xA1 **(-80 + -14 + -1)**
 250    |             |
  60    | 0b0011 1100 | 0x3C
 -35    | 0b1101 1101 | 0xDD
 128    |             |
 105    | 0b0110 1001 | 0x69

## Picking Representations

1. Use SIGNED for Celsius because temperatures drop below 0.

2. Use SIGNED to maximize range representations that include negative numbers. Otherwise, use UNSIGNED.

3. Use UNSIGNED to represent how many boxes a factory has shipped (it will never ship a negative amount).

## Counting

a. 4^n

b. 2^(n-1)

c. n *?*

d. 2^n - 1

## Overflow

a. 64 + 64 = OVERFLOW

b. -127 + 30 = 0b1000 0001
              +0b0001 1110 = -97

c. -127 - 1 = OVERFLOW b/c negative bits collide

d. 38 - 40 = 0b0010 0110
            +0b1101 0111
           = 0b0000 1001 = OVERFlOW
