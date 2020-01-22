
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
## Now you can do 3 different type of command:
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
## To use the program after it is started: 
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
  the command **end** strting the solver prosess.
  
 ## Features of the program:
 **Within the fold - "TestAlgorithms" Attached are several features for working with the program:**
* Go into "pythonScript" -
#### First one - creat matrix:
* Use this command to start the Script -
     ```sh
    $ python2.7 creat_matr.py
And now we get 11 matrix with name **Matrix_X** (x is a aize of the matrix)

#### Second - creat client:
* Use this commad to creat a client -
     ```sh
    $ python2.7 auto_client.py
    
#### Last one - Test parllel server:
* Into **/pythonScript/test_Parller_tester** wite this command
    ```sh
    $ python2.7 parallel_tester.py
And now **automatic** the tester will solve 10 matrix (that in the folder)

## General explanation of the program:
#### Program uses different interfaces -
##### Server -
* The program create a server of either type or a parallel or serial server
* Listens to the received port as an argument
##### Client Handler -
* Reads the information that is transmitted from the client and from them creat "problem"
* Use Cache Manager and Solver to solve this problem and back a solution
##### Cache Manager -
* Saves the answers to the problems we have solved in the past and knows how to find old issues
##### Solver -
* Realized with the help of successor departments who solve a problem according to a defined exercise
##### Search -
* Define a searchable object and know how to solve a search world problem - for example, we search the matrix Using various algorithms
##### Algorithms -
The following algorithms were realized:
* Breadth First Search
* Best First Search
* Dfs
* **A star**
##### String revers
* Heir of Solution - know how to revers the string he received

## Archdiocesan class

![dd](https://user-images.githubusercontent.com/59409570/72936042-26cf3780-3d6f-11ea-9649-bd3cb203a95b.jpg)



‬
