// Novruz Amirov
// Question Link: https://leetcode.com/problems/keys-and-rooms/

/*
    Problem Description:
        There are keys and rooms either open or closed.
        Each room is closed except the 0th one. It means
        it is the starting point. In each room there is 
        the keys that opens another room. The room might 
        contain a key, keys or even nothing. The aim is 
        to return if we can open all rooms or not.
        
    Solution Method:
        If in room A, there exists the key of room B, it
        does not mean there is key of room A in room B.
        This means it is directed Graph question.
        Briefly, in order to know if we can open all rooms
        or not, we need to find if the Graph is connected
        or not. If Directed Graph is connected it means we
        can open all rooms. The best way to check if Graph
        is connected or not is DFS(Depth First Search).
        
        We will use Adjacency List to represent the Graph.
        Then we will declare o boolean array to store if
        each nodes is visited or not. Initially all nodes of 
        visited array are false. 
        Starting from node 0, we will use DFS to check if we
        can reach all nodes or not. The reason why we start 
        from node 0, because it is only node we know is open.
        After DFS of node 0, we will check visited array, if
        there is some node that is not visited, then this Graph
        is not connected, meanin the answer is false, otherwise
        is connected, meaning the answer is true.
*/

class Solution {
public:
    // Depth-First Search function, to chech if the Graph 
    // is connected by changing visited array of bools.
    void DFS(int x, vector<bool>& visited, vector<vector<int>>& adjacencyList){
        if (visited[x]) // if the node is visited skip it.
            return;
        
        visited[x] = true; // make this node's visited true.
        
        // check all nodes that this node has an edge, 
        // and do DFS to all of them.
        for (int node = 0; node < adjacencyList[x].size(); node++){
            DFS(adjacencyList[x][node], visited, adjacencyList);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // intializing Adjacency List to represent Graph.
        vector<vector<int>> adjacencyList(rooms.size(), vector<int>(0));
        
        // bool vector to represent the node is visited or not.
        vector<bool> visited(rooms.size(), false);
        
        // because it is DIRECTED Graph, we will add ending nodes to starting node.
        for (int startingRoom = 0; startingRoom < rooms.size(); startingRoom++){
            for (int endingRoom = 0; endingRoom < rooms[startingRoom].size(); endingRoom++){
                adjacencyList[startingRoom].push_back(rooms[startingRoom][endingRoom]);
            }
        }

        DFS(0, visited, adjacencyList); // DFS to 0, because it is only one that is open.
        
        for (int node = 0; node < visited.size(); node++){
    
            // if node in visited arrat is false, it means
            // that node can not reached from node 0. Then
            // this is not connected Graph.
            if (visited[node] == false)
                return false;
        }
        
        // if program comes here, it means all
        // nodes are reachable, then answer is true.
        return true;
        
        /*
            The time complexity of the program is O(V).
            The space complexity of the program is O(V^2).
            V -> the number of nodes in Graph
        */
    }
};
