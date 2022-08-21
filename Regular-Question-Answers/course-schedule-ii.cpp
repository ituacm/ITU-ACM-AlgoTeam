// Author: Ceren Yaşar
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/course-schedule-ii/

/* 
 * This solution uses depth-first search approach in order to traverse a possible topological
 * sorting by visualizing prerequisites as edges in a directed graph. An edge points to a
 * course which the source is a prerequisite for.
 *
 *
 * Time complexity: O(v+e) 
 * Memory complexity: O(v+e)
 * (v=nodes, e=edges)
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjList[n] gives a vector of courses which course n is a prerequisite for
        vector<vector<int>> adjList(numCourses, vector<int>());
        
        // in-degrees represent the number of prerequisites per course
        // initialize all in-degrees with 0
        vector<int> inDegrees(numCourses, 0);
        
        // by iterating over the list of prerequisites, we count the number of prerequisites for
        // each course and save this info in adjList
        for (auto i : prerequisites) { 
            inDegrees[i[0]]++;
            adjList[i[1]].push_back(i[0]);
        }
        
        // we need to use "first in-first out" principle when ordering the courses because as we
        // decrement in-degrees for each course, we assume that one prerequisite is taken care
        // of, which means that the required course is to be taken and added to the result
        // array.
        queue<int> order;
        for (int i = 0; i < numCourses; i++) {

            // if a course has an in-degree 0, it has no prerequisites, therefore can be taken
            if (inDegrees[i] == 0) {
                order.push(i);

                // this decrement operation prevents multiple additions of course i
                inDegrees[i]--;
            }
        }
        
        int current;
        vector<int> result;
        
        // while there are still courses to take
        while (!order.empty()) { 

            current = order.front(); 
            order.pop();
            result.push_back(current);

            for (auto nextCourse : adjList[current]) { 

                // since the current course is already taken, one prerequisite of every course in
                // adjList[current] is satisfied, which means there is one less in-degree for each
                // to take into account
                inDegrees[nextCourse]--;

                // if any of the courses we iterate over satisfy all prerequisites, we are ready
                // to take that course
                if (inDegrees[nextCourse] == 0)
                    order.push(nextCourse);
            }
        }
        
        // if the result array didn't end up including all courses, it means there was no
        // possible topological order to take all courses so we return an empty array
        if (result.size() == numCourses)
            return result;
            
        return {};
    }
}; 
