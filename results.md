# Traversal Discussion

Breadth First Search- We used BFS traversal by iniially reading the CSV file to find every Node and edge that connected to their respective Node. We then maintain the Traversal using a queue and a map to maintain visited Nodes, and this was our way of reading the CSV file and ensuring all Nodes were traversed for our future implementations using the algorithms discussed later. We use methods such as "maxVertex()" and "printTraversal()" to determine whether the traversal worked properly, and ultimately based on the test csaes conducted, working around edge cases, we successfully implemented BFS, a primary tool used for traversing the Graph.

# Algorithm Discussion

PageRank - Used to highlight most favored streamers based solely on mutual viewership with other users, where more popular streamers will land. In addition, this algorithm's intended use was to further simplify the way consumers could interact with our code, being able to better understand streamer relationships. We were able to successfully implement PageRank to the way the Leading Question where were able to implement it the way I want. We implemented test cases that iterated through one of the methods in PageRank, checked results with manually calculated math. Checked many iterations to see whether all the ranks add up to one (where ranks are valued as weight, and ranks range from zero to one). 

Force-directed Graph - Force-directed graph algorithm work in co-step with PageRank to allow users to visualize the Graph in a more interaction-based way. This algorithm used an attraction and repulsive force to tell itself how to graph. For example, if two nodes grew too near to eachother, the repulsion factor is used to distance them in a way that still displays the graph in a concise manner, while also highlighting relationships between different channels. Unlike PageRank, this algorithm is primarily focused on helping visualize the graph with their relationships being prominent in doing so. We implemented test cases that iterated through positions once, which only calculate forces once and compare to manually calculated forces. 

# Output of Algorithms:

![image](https://user-images.githubusercontent.com/87607418/207226870-2479699d-3942-4f9e-99d1-73f5da8d564c.png)

The image above displays the top two most important channels as determined by the two methods of PageRank. Although the ranks assigned may be considered small, since all ranks add up to one, these are the largest verticies of the entire graph (despite the seemingly low number). We would love to know what these channels are, but we are unable to as shown in the image below. We determined that this dataset is outdated and that Twitch has changed the way they deal with channel IDs (especially after Twitch faced a massive security breach in late 2021).

![image](https://user-images.githubusercontent.com/77647988/207232139-a65c319b-3fa3-45f9-a082-e60456275007.png)
