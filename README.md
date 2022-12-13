# Group Name: DSDawgs225
CS225 Project group for the dawgs

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
4. Algorithm #2: Force-Directed Graph Drawing - "FDG.cpp" and "visualize.cpp"
5. Tests: "tests.cpp"

    
## Project Proposal

### Leading Question 

For our final project, we chose to look at the twitch-gamers dataset at http://snap.stanford.edu/data/twitch_gamers.html and investigate the viewerbase connection with streamers on the livestreaming platform. This dataset contains two CSV files, one of which contains viewer relations between two Twitch channels, and another which contains data on streamers such as their max view count, language, and channel id.

Our goal is to learn more about how the Twitch community interacts with one another by using the PageRank algorithm to find which streaming channel contained the most diverse/varied Twitch community and use the force-directed graph drawing algorithms in order to showcase the Twitch communities interactivity visually. More specifically, we want to see which twitch gamers are the most interconnected with other gamers based on sharing at least one common viewer. 

We plan to do this through the use of a Breadth-first search (BFS) traversal.

### Dataset Acquisition

### Data Format
We’re using the Twitch Gamer dataset from ​​Stanford’s Large Network Dataset Collection. It can be found at http://snap.stanford.edu/data/twitch_gamers.html. The dataset is split into two csv files, large_twitch_edges.csv and large_twitch_features.csv. The first file contains 2 columns of Twitch channel id’s with each row corresponding to an edge between two channels. The second file contains information about all the channels in the first file such as their language, affiliate status, total views, and account age, using the channel’s id as a unique identifier. The dataset contains information for 168,114 twitch channels and  contains 6797558 unique edges between them. We plan to use all the data within the dataset

### Data Correction

We will parse the input data by going through each row in the features csv file and creating a node for each channel, adding all the information about the channel specified in the file. Before adding information to each node,, we will check whether there are any errors in the data, such as a blank value or a negative value. If any information is incorrect we will insert a placeholder value like negative 1 into the node.

We will then go through our edges csv file, creating edges between specified nodes one line at time. Before creating an edge we will check whether the specified channel IDs are valid. If one isn’t valid, we will skip this line and move on to the next.


### Data Storage
We will store our data in Graph. We will implement this graph as an Adjaceny list as Adjacency lists have a space complexity of only O(m + n) where m is the number of edges and n is number of verticies. We will implement this Adjaceny List using an Array of Linked lists. Each entry in our Array will represent a vertex and the linked list of each entry will contain pointers to edges in our edge list. Our edge list will be linked list containing edges and the verticies they connect. We will also be using a stack data structure to implement our DFS. 



### Algorithm 
The data is stored in a CSV file outlining each major twitch gamer's ID and the ID of another user they are connected to. We plan to use the PageRank formula to determine what weights should be assigned to each user based on number of connections with other users. After determining these assigned weights, we will utilize the force directed graph drawing algorithm to visually display this information in the form of large circular points and interconnected edges, using the forces to closer group the streamers that have more viewers in common. The specific inputs and outputs for our specific project is still unclear, but will will know after implementing the algorithms.

The expected outcome is some sort of graphviz file that will clearly display the interconnectedness of twitch streamers. Ideally we want to be able to color code either based on different streaming genres or different users, but that can be determined in the visualization stage of the project.

Due to the high running time of force directed graph drawing algorithms, we estimate for quite a high running time of O(n^3). Since PageRank is O(n+m), we have an overall runtime of O(n^3) as the goal. Additionally, we aim for a space complexity of O(n^2), as we anticipate nested loops as part of the graph drawing algorithms. 

### Timeline

    Week 1- Implement DFS class 
    
    Week 2- Implement data reading for CSV file
    
    Week 3- Implement Page Rank
    
    Week 4- Finish implementing page rank, Implement Force Directed Graphs
    
    Week 5- Finish implementing force directed graphs, make outline for video
    
    Week 6- Create video presentation

