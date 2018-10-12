COMP 345 Assignment #1
Team #4

Group Members:
--------------
Christian Plourde I.D. 26572499
Jack Burns I.D. 40033754

This file contains information about running the test drivers for the different program components:
----------------------------------------------------------------------------------------------------
The subcomponents of the project are all tested using various drivers that test the functionality of the components under
different situations. All of the test drivers are found in various directories in the test drivers directory of the project.

Dice Testing:
--------------
The dice rolling mechanic is implemented using a random number generator that is tested in the Dice Test folder of the project.
In order to try the test, the executable file 'dicetest.exe', found within that folder, can be run from the command line. It will
roll the dice a large number of times and count the number of times that each dice face comes up. This tests the uniformity of the
random number generation. The results are then output to the console and we can see that the results are close.

Map Loader Testing:
--------------------
The map loading functionality is tested using some test drivers that attempt to load some badly formatted files, and finally, a good
map file. The drivers are found in the map loader test folder and the various executables found there can be run from the command line. The executables containing the word 'garbage' in their name attempt to open badly formatted files and return meaningful error
messages. There is an executable there called 'loadergoodmap.exe' which loads a well formatted map into a graph designed using an
adjacency list. The contents of that graph are then outputted to the console.

Player Testing:
----------------
The various important methods of the player class, such as dice rolling, moving, buying cards, and resolving dice are all tested
by different drivers in the player test directory. All of these tests are precompiled and can be run from the command line. For example, the 'playermovetest.exe', program tests the move method in the player class, while the 'playerrolltest.exe' tests the player dice rolling facility. All of these place the player in different scenarios and since many of these are dependent on the outcome of the dice roll, executing the driver multiple times will yield different results.

Deck Testing:
--------------
This tests the various decks and their methods. It includes generating, manipulating and printing all the decks and their objects.