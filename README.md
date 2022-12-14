# Group Name: DSDawgs225
Contributors:
- Daniel Bezugliy (dbezu2)
- Faaris Shaik (faariss2)
- Nathan Joseph (njoseph4)
- Steven Isaac (sisaa2)

Presentation: https://mediaspace.illinois.edu/media/t/1_jeknfhgx

## Running Instructions

To get the project on your local machine:
- Navigate to desired location
- Type in terminal "git clone https://github.com/njoseph2/CS225-DSDawgs.git"

To make and run executables:
- Type in terminal "make"
- type in "bin/tests" or "bin/main" (depending on what you wish to execute)
- (CURRENTLY, OUR PROGAM USES THE TESTING.CSV TO OUTPUT DATA. IF YOU WANT TO USE THE TWITCH DATASET, GO TO MAIN.CPP AND FOLLOW THE COMMENTED INSTRUCTIONS. NOTE THAT DOING THIS WILL RESULT IN A LONG RUN TIME SINCE THERE ARE SO MANY TWITCH CHANNELS)

To get remote changes on your local machine:
- git pull
- if you run into error with merging/stashing, do "git stash" then "git pull"

To push local changes to remote:
- git add . 
- git commit -m "<message>"
- git push

## GitHub Important Files 
1. Data Cleaning/Graph creation: "CSV.cpp"
2. Traversal: BFS - "BFS.cpp"
3. Algorithm #1: PageRank - "pagerank.cpp"
4. Algorithm #2: Force Directed Graph - "FDG.cpp", "visualize.cpp"
5. Tests: "tests.cpp"
  
## File io CSV.h/cpp
  Our CSV reader has two function. First it contains **readCSV()**, which takes a CSV file of channel ids and returns 2D vector of chanel ids representing the the rows and columns of the CSV file. It also contains a **toGraph()** function which takes a 2D vector of channel ids and creates a Graph out of it, returning a pointer to the Graph. An example of how this works can be seen in our test cases.

## Pagerank pagerank.h/cpp
  Two different methods were implemented for PageRank. In algorithms(int iter), a recursive method is used to calculate the rank. This is calculated by finding the sum of all the neighboring channels' rank divided by the number of edges they have. It is then performed iter number of times. The second method uses a Random Surfer Model to calculate the ranks. How the method essencially works is a invisible surfer visits connecting nodes/channels and stores a count. If the damping factor is triggered (15% chance), the surfer will teleoport to a random node. This simulates a user searching a compeletly different channel.

## BFS BFS.h/cpp
  Our BFS class traverses a given Graph, starting at a given Vertex. It contains two functions, **PrintTraversal()**, which prints out the entire traversal at once, and **NextVertex()**, which traverses one vertex at a time, returning the next vertex in the BFS traversal each time it is called. Each instance of the class can only do one of these traversals, so if you want to traverse a Graph both ways, you must create two instances of BFS. An example of how this works can be seen in our test cases.

## Force Directed FDG.h/cpp
  Our Force Directed Graph class (or FDG) "plots" nodes by assigning each an x and y coordinate, and then calculates attractive and repulsive forces between the nodes and their neighbors. It contains three main functions: **attractiveForce()** and **repulsiveForce()**, which each take in two const Node references and return the respective force between the two nodes. 
