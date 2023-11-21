# Programming Paradimgs CW2
Toby Tatsuya Watkinson
(sczh26)

## `./ant` inputs
- with no inputs, the standard ant will run, press a key to advance one step, press q to exit
- with input 'i', the standard ant will run infinitely, quit this by pressing `ctrl+c`
- with input of a rule (e.g. LLRLRRLRL) the generalised ant will run with this rule using ascii values of 32+ to represent the states
- with input of a rule, plus input 'i', the generalised ant will run infinitely, quit this by pressing `ctrl+c`

## `Makefile` options
### all
Will create an executable called `ant`
### library
Will create a dynamically linked libaray in the current directory called libant.so
### clean
Will remove any object files, executable files, and library files created
### run
Will run the standard verion of the ant in an infinite loop.

Exit this with `crtl+c`
### test
Will run the cpplint command indicated in a forum to test the code quality and formatting is good.
