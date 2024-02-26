# Hamming-Codes

- [Building](#building)
- [Execution](#execution)
- [Sample Ouput](#sample-output)

This is a small project I did to demonstrate the principles I found in 3Blue1Brown's video on [Hamming Codes](https://www.youtube.com/watch?v=X8jsijhllIA).

The code shows how given a section of byte data, provided a few randomized errors, can be corrected using the principles of Hamming Codes. It's pretty short but perhaps it could be expanded to explore more modern error correction algorithms that build off of Hamming's initial ideas, along with other improvements that I can immediately think of.


## Building

Simply run make:

```
> make
gcc -o hamming hamming.c
```

## Execution

For now, running this program requires passing a single argument: the size of the sample byte data ( treated in the code as a byte array ).

> Note: The technique I use in this project is limited to using byte arrays whose size is a square number or whose root is an integer. The exact reason for this lies in the error correction method, which I will furhter elaborate in the sample output.

```
> ./hamming {byte array size}
```

## Sample Output

For now, I'll upload this readme with just the output, but a full explaination of what the output demonstrates should be added. If you are familiar with Hamming Codes already ( if not, watch 3Blue1Brown's video series on the topic ), then the output should probably be understandable.

Specifying a byte array of 16 ( _Remember, the byte array must have a whole number as a root_ ):
```
> ./hamming 16
size: 16 bits
parity: 4 + 1 = 5 bits
message: 13 bits ~ 1 bytes
1 0 1 0
1 1 1 1
1 0 0 0
1 0 0 0
error = 6
1 0 0 0
0 1 1 1
1 0 0 0
1 0 0 0
error = 0
```

Another, this time specifying a byte array of 25:
```
> ./hamming 25
size: 25 bits
parity: 5 + 1 = 6 bits
message: 21 bits ~ 2 bytes
1 0 0 0 0
1 1 0 0 1
1 1 0 1 0
0 1 1 0 1
0 1 1 0 0
error = 23
1 1 0 1 0
1 0 0 0 1
1 1 1 1 0
0 1 1 0 1
0 1 1 0 0
error = 31
>
```

