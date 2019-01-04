# Node Native XOR

This is not a true XOR function, but a demonstration of how to bring inline assembler code into nodejs.

This module does a few things.

1. Creats a C++ native module for nodejs
2. Upon passing it a string, the model will convert the string into a binary bitstream
3. The individual bits are passed to inline assembler which does an XOR function
4. The bits are reassembled and cast into a number
5. The number is forced into a valid character number using a round robin count
6. The valid number is cast a character
7. The character cast is appended to a string
8. The string is returned.

So you can see it goes through this flow

nodejs -> c++ -> asm -> c++ -> nodejs

The end result is a function `xor` that is called on the imported node module and passed a simple string.

---

## Running

`yarn install` && `yarn build` && `yarn start`

or

`yarn install` && `yarn scratch`