
# Ex4---Searching-Algorithms-Server

**Searching-Algorithms-Server - Ex4 -** Advanced Programming at Bar Ilan created by **Shon Pozner**

* **gethub** [Linke](https://github.com/ShonPozner/Ex4---Searching-Algorithms-Server)

## The project's aim:

* **-Searching-Algorithms** Acceptance a matrix from the **client** and returning a solution - **short way** from the start point to the end pointsr.
* Compare the number of cells evolved using different **search algorithm** implementations
s.

## Technologies:

* The project articles in language **C++ ver14**
* The project is optimized for working with the flight simulator- **FlightGear**
 [link to downoad](http://home.flightgear.org)

## Launch - how to run the project:

#### Creat the simulator:
* The simulator must first be **downloaded** (again [link](http://home.flightgear.org)).
* Than you need to add from **setting command**, request to open a server and Client.
* copy this **commands** to the setting command:
    ```sh
     --telnet=socket,in,10,127.0.0.1,5402,tcp
     --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small

#### Now is the time to run this project:
* The **compile** command is -
    ```sh
    $ g++‬‬ ‫‪-std=c++14‬‬ */*.cpp ‫‪*.cpp‬‬ ‫‪-Wall‬‬ ‫‪-Wextra‬‬ ‫‪-Wshadow‬‬ ‫‪-Wnon-virtual-dtor‬‬ ‫‪-ped antic‬‬ ‫ ‪-o‬‬a.out-pthread
    ````
* To **run** the code -
    ```sh
    $ ./a.out fly.txt  //(you can Choose a different txt file)
    ````
* Now you see that the program is **waiting** for a cline
* And this is the right time to **start the simulator**
* Click on the start and **let the fun begin** 

## General explanation of the program:
### Program order:
* The project start run the main which first defines **DATA** -
   * Data contains all maps that saved the differnet valyes at tun time
* Than **LEXER** go on -
   * Lexer read a line by line and save evrey exprision at cell in the arry
* Now **PARSER** time - 
   * Parser read command after command and execute the commad 
   
### Program commands:
The program recognizes the following commands:
* **Print** - 
   * Prints expressions or variables.
* **Sleep** -
   * Stops the program activity for several milliseconds as the input you receive
* **Define a variable**
   * Define a variable initializes the value of the variable to 0 
   * Checking the variable's relevance
* **Open Data Server** -
   * Open a server 
   * And waiting for connection to the simulator
* **Connect Control Client** -
   * Creat a Client
   * Sending commands to simulator
* **While** -
   * Checks whether the condition is met
   * If so then execute a command sequence in the loop
* **If** -
   * Checks whether the condition is met
   * If so then execute a command sequence one time



## Archdiocesan class

![Archdiocesan](https://user-images.githubusercontent.com/59409570/71785674-14cd6500-300b-11ea-8736-43fe69dbe9b1.JPG)


‬
