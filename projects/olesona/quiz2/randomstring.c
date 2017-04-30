/************************************************
 * File: randomstring.c
 * Author: Alannah Oleson
 * CS 362, Quiz 2
 * *********************************************/

First run: 5855263 iterations til error
Second run: 361459 iterations til error
Third run: 5988144 iterations til error

   When I began developing my solution, I started with the source code
of testme.c. For the state change calculations, I needed to generate a 
series of characters that would cover brackets, spaces, and lowercase
letters. For the final "error" calculations, I needed to generate a
string that spelled out "reset" with a null terminator at the end. 
When this string was generated, and the program was in the 9th state, 
the error message would appear.

   To generate random characters in inputChar(), I based my generation
off the ASCII table. Calling the rand() function mod 96 and adding 32
to the result gave me a random number in the range [32, 127]. This 
corresponds to any character on the table other than the special
control codes at the beginning. I excluded those codes because they
don't really fit the context of the problem.

   To generate random strings in inputString(), I again based my method
off the ASCII table. I called rand() mod 26 this time and added 96 to
the result. This gives us a number in the range [96, 121]. I decided to
constrain this string to containing only lowercase characters, since we
only needed to generate "reset" - I figured that including all the
charaters on the table would lead to prohibitive test running times and 
would not give us any more information than if only lowercase letters
were generated.

   Overall, this random tester implementation seems to work well. It
does take a large number of iterations before printing "error", as seen 
at the top of this file, but it does terminate eventually. In fact, none
of the runs took longer than a minute (and run 2 was actually very
short). The number of iterations it takes to generate the error message
seems to depend largely on the contents of the random string, and not the
state changes - the state moved up to 9 very early on in the test
iterations. This means that the random character generated really doesn't
have much of an effect on the running time of the test, since it only 
affects the very early calculations.

