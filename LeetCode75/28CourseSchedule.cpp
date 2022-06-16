/*
There are a total of numCourses courses you have to take, labeled from 0 
to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        if(p.size()==0) return true; //all courses independent
        
        //indegree counts the number of edges approaching a particular node
        vector<int> indegree(n, 0); 
        //adjacency matrix of the given graph
        vector<vector<int>> graph(n); 
        
        //iterate thru entire matrix of prerequisite courses
        for(auto &x : p){
            
            //x[0] is the course with a prerequsite. x[1] is the prerequisite.
            //graph matrix flips them all.
            graph[x[1]].push_back(x[0]);
          
            //index i of indegree is the course #. value at indegree[i] is how many inputs that node has
            indegree[x[0]]++;
        }
        
        //push courses into queue that have 0 indegree
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i), indegree[i]--;
        }
        //cycle exists if there is no node with indegree 0
        if(q.size()==0) return false; 
        
        int count = 0; //No. of nodes you're able to reach till the end
      
        while(!q.empty()){
            int size = q.size();
            
            //iterate thru queue (filled with the courses, p[0], that have 0 indegrees)
            for(int i=0; i<size; i++){
                int curr = q.front(); q.pop();
                count++;
                for(auto child : graph[curr]){
                    indegree[child]--;  //decrement the indegree of the nodes until you've reached all nodes
                    if(indegree[child]==0) q.push(child);
                }
            }   
        }
        if(count==n) return true;
        return false;
    }
};



/*
Runtime: 46 ms
Memory: 13.3 MB
*/
