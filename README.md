# Word finder of Iliad
This program is a simplified searching engine for Homeric Epic Iliad. 
This program is inspired by one of my classics professor who works on a project digitalizing Roman and Greek literature
Type "make tests" and "make Iliad" to compile the codes
Type "./FuncsTest" and ./main to run the test function and the main function
It will show the first three occurances of the input word and its line number. If there are less than three occurances in the whole Iliad, the result will NA and the line number will be 0. If the input is "exit", the program will stop.
For example:

              -bash-4.1$ ./main
              Please enter a word (Type 'exit' to exit):
              countless
              countless 4
              countless 601
              countless 909
              Please enter a word (Type 'exit' to exit):
              Ulysses
              Ulysses 124
              Ulysses 263
              Ulysses 365
              Please enter a word (Type 'exit' to exit):
              Odysseus
              NA 0
              NA 0
              NA 0
              Please enter a word (Type 'exit' to exit):
              exit
              -bash-4.1$
