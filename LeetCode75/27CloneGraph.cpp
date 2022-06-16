/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and 
so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite 
graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the 
copy of the given node as a reference to the cloned graph.
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;
    Node* cloneGraph(Node* node) {
        
        //for recursion, check whether node is valid
        if (!node) {
            return NULL;
        }
        //map.find() returns iterator. if the iterator == last iterator of map. no such node has already been seen
        if (copies.find(node) == copies.end()) {
            
            //add a new node to the map, where its value is simply copied from the current node
            copies[node] = new Node(node -> val, {});
            
            //declare new Node* called neighbor, which iterates thru every neighbor current node has
            for (Node* neighbor : node -> neighbors) {
                
                //for each neighbor of current node, create identical link in map btwn node and its neighbors
                //to get value of actual neighbor of current node, function must be called recursively 
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};







/*
Runtime: 
Memory: 
*/
