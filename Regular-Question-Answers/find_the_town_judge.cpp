// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/find-the-town-judge/

/* 
    Problem Description:
        It is DIRECTED graph algorithm question. 
        Briefly, we need to find the node (if exists),
        which has no edge with anyone else, but everyone 
        has an edge with it.
        
        Example:
            (1) ---> (3)
            (2) ---> (3)
        
        The answer in this graph is 3, because as you can see,
        node 3 has not an edge with any other node.
        Additionally, every other node in the graph has relation with node 3.
        
        Moreover, if there is not any node satisfying the conditions
        above, we will return -1.
        
        Code Explanation:
            The data structures used in this question is vector.
            The reason for using vector is that, as given in Constraints 
            section of question, there is not any duplicate pairs.
            
            If there would be duplicates, we would use set as a data
            structure to eliminate duplicates.
            
            We will use 2 vectors. First one is for knowing the number 
            of nodes that each node trusts. This vector is used
            for the condition 1 given in question, which is judge must
            not trust anyone. We initialize trust number of every node 
            as 0. 
            The second vector will be used as a same way, but for the number
            of nodes which trust this node. For example: if the node 1 trusts
            the node 2, then we will increment the number of nodes that trusts
            node 2 by 1.
    
            Finally after we will add all edges, we check these 2
            vectors, and if the trust number of node is 0 and if 
            the numbers of nodes that trusts this node is n - 1,
            this means the node satisfied all conditions.
*/


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // initializing the first vector to hold number of nodes the node trusts.
        vector<int> whoTrusts(n + 1, 0); // n + 1 is for 1-index array.
        
        // initializing the second vector to hold number of nodes the node is trusted.
        vector<int> whoIsTrusted(n + 1, 0); // n + 1 is for 1-index array.
        
        /* 
            The reason why we are using 1-index array is because, 
            we are given the nodes starting from 1, and as
            a result we need to return it when we find the judge.
            0-index can also be used, but do not forget to return 
            i+1 when judge is founded.
        */
        
        // because the first is the one who trusts the second node
        // the 0 th node will be used for whoTrusts vector
        for (int edge = 0; edge < trust.size(); edge++){
            whoTrusts[trust[edge][0]]++;
            whoIsTrusted[trust[edge][1]]++;
        }
        
        // starting from node 1, check for if the node is judge or not.
        for (int node = 1; node < n+1; node++){
            
            // checking first and second conditions.
            if(!whoTrusts[node] && whoIsTrusted[node] == n-1){ 
                return node; // if judge found, do not look at other nodes.
            }
        }
        
        return -1; // the program comes here only if there is no judge.
        
        /* The time complexity of this program is O(n + m).
           n -> number of nodes, m -> number of edges
           
           the space complexity of this program is O(n)
           n -> number of nodes
        */ 
    }
};
