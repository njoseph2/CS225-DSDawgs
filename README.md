# Group Name: DSDawgs225
Contributors:
- Daniel Bezugliy (dbezu2)
- Faaris Shaik (faariss2)
- Nathan Joseph (njoseph4)
- Steven Isaac (sisaa2)

## Running Instructions

To get the project on your local machine:
- Navigate to desired location
- Type in terminal "git clone https://github.com/njoseph2/CS225-DSDawgs.git"

To make and run executables:
- Type in terminal "make"
- type in "bin/tests" or "bin/main" (depending on what you wish to execute)

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
  Our CSV reader has two function. First it contains **readCSV()**, which takes a CSV file of channel ids and returns 2D vector of chanel ids representing the the rows and columns of the CSV file. It also contains a **toGraph()** function which takes a 2D vector of channel ids and creates a Graph out of it, returning a pointer to the Graph.

## Pagerank pagerank.h/cpp

## BFS BFS.h/cpp
  Our BFS class traverses a given Graph, starting at a given Vertex. It contains two functions, **PrintTraversal()**, which prints out the entire traversal at once, and **NextVertex()**, which traverses one vertex at a time, returning the next vertex in the BFS traversal each time it is called. Each instance of the class can only do one of these traversals, so if you want to traverse a Graph both ways, you must create two instances of BFS.

## Force Directed FDG.h/cpp
1. 
