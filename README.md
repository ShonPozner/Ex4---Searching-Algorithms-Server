
# Ex4---Searching-Algorithms-Server

**Searching-Algorithms-Server - Ex4 -** Advanced Programming at Bar Ilan created by **Shon Pozner**

* **gethub** [Linke](https://github.com/ShonPozner/Ex4---Searching-Algorithms-Server)

## The project's aim:

* **-Searching-Algorithms** Acceptance a matrix from the **client** and returning a solution - **short way** from the start point to the end pointsr.
* Compare the number of cells evolved using different **search algorithm** implementations

## Technologies:

* The project articles in language **C++ ver14**

## Launch - how to run the project:

#### First compile:
* **compile** all file with commands:
    ```sh
    $ g++‬‬ ‫‪-std=c++14‬‬ */*.cpp ‫‪*.cpp‬‬ ‫‪-Wall‬‬ ‫‪-Wextra‬‬ ‫‪-Wshadow‬‬ ‫‪-Wnon-virtual-dtor‬‬ ‫‪-ped antic‬‬ ‫ ‪-o‬‬a.out-pthread
    
#### Run this project:
* Using this comint **compile** command is -
    ```sh
    $ g++‬‬ ‫‪-std=c++14‬‬ */*.cpp ‫‪*.cpp‬‬ ‫‪-Wall‬‬ ‫‪-Wextra‬‬ ‫‪-Wshadow‬‬ ‫‪-Wnon-virtual-dtor‬‬ ‫‪-ped antic‬‬ ‫ ‪-o‬‬a.out-pthread
    ````
##Now you can do 3 different type of command:
* Use this command to preparing a text file containing **algorithm comparison** result:
    ```sh
    $ ./a.out testAlgo
    ````
* To run a standard - **solves matrix** using the paraller server listener a number of servers:
    ```sh
    $ ./a.out 5600 //can use another port
    ````
* The following command will read the client strings and return the opposite string:
    ```sh
    $ ./a.out 5600 part2 //can use another port
##To use the program after it is started: 
* To connect as a client to a server, use the following command:
    ```sh
    $ telnet 127.0.0.1 5600
    
 * Now send a mtrix like this:
     ```sh
    > 1,3,4
      3,4,8
      2,1,9
      0,0
      2,2
      end
      ```
  this matrix is 3X3, start point (0,0) and end (2,2) 
  the command end strting the solver prosess.
 ## General explanation of the program:


## General explanation of the program:
### Program order:
* Create a **parallel server** that waits for clients and handles them in parallel -
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
