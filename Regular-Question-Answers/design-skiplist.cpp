// Author: Ali Emre Kaya
// Reviewer: 

// Time Complexity = O(log(n))
// Space Complexity = O(hegiht * n)
// Question Link = https://leetcode.com/problems/design-skiplist/

/*
A skip list is a data structure that allows for efficient search, insertion and deletion of elements in a sorted list. 
It is a probabilistic data structure, meaning that its average time complexity is determined through a probabilistic analysis.

In this question, we will design a doubly skiplist structure

See more about Skiplist: 
https://www.youtube.com/watch?v=b3dGuADK8Es&ab_channel=TolgaOvatman
https://www.geeksforgeeks.org/skip-list
*/

// the node structure we need for creating skiplist structure, it has 2 pointer, next and below
class DoublySkipList_Node {
public:
    int data;
    DoublySkipList_Node* next;
    DoublySkipList_Node* below;
    DoublySkipList_Node(int data, DoublySkipList_Node* next, DoublySkipList_Node* below) : data(data), next(next), below(below) {}
};

class Skiplist {     
public: 
    DoublySkipList_Node* head;

    // arranging default height, initial height
    /*
    Hint: If the height is 𝑘, then the search complexity should be 𝑂(𝑘𝑛^(1/𝑘))
    [so the best choice is 𝑘=log(𝑛), giving logarithmic time].
    */
    int height = 5;
    
    Skiplist() { // Time Complexity = O(height), Space Complexity = O(height)
        // arranging the first and last nodes
        // all the other nodes will be inside these two columns
        int first = INT_MIN;
        int last = INT_MAX;

        // firstly, create the top 2 node
        head = new DoublySkipList_Node(first, nullptr, nullptr);
        head->next = new DoublySkipList_Node(last, nullptr, nullptr); 

        DoublySkipList_Node* ptr = head;
        DoublySkipList_Node* temp = nullptr;

        // after creating top 2 node, continue downwards, depend on height
        for (int i = 0; i < height - 1; i++) {
            ptr->below = new DoublySkipList_Node(first, nullptr, nullptr);
            ptr->below->next = new DoublySkipList_Node(last, nullptr, nullptr);
            ptr = ptr->below;
        }
    }

    // function will give a random height between 1 and 5, because my initial height is 5
    int get_level(){
        int res = rand() % height + 1;
        return res;
    }
    
    // function will show the target is inside the skiplist or not
    bool search(int target) { // Time Complexity = O(log(n)), Space Complexity = O(1)
        DoublySkipList_Node* ptr = head;

        // skiplist will traversed, and if there is a number which we search, function will return true
        while(ptr){
            // row searching
            while(ptr->next && ptr->next->data < target){
                ptr = ptr->next;
            }
            if(ptr->next != nullptr && ptr->next->data == target) return true;
            // if target did not found in the row, ptr will move down one time
            ptr = ptr->below;
        }

        return false;
    }
    
    // function will add the num to the certain place with hegiht which comes from get_height
    void add(int num) { // Time Complexity = O(log(n)), Space Complexity = O(1)
        int random_height = get_level();
        DoublySkipList_Node* ptr = head;

        // ptr's height will arranged respect to the searching height
        // in searching_height new node addition will start, until below != nullptr 
        int searching_height = height - random_height;
        for(int i = 0; i < searching_height; i++){
            ptr = ptr->below;
        }

        // that will use one time
        DoublySkipList_Node* above_temp = nullptr;

        while(ptr){
            // ptr will show the node just before the the place which the new node will come
            while (ptr->next != nullptr && ptr->next->data < num) {
                ptr = ptr->next;
            }

            // that new_num node will add to the skiplist
            DoublySkipList_Node* new_num = new DoublySkipList_Node(num, nullptr, nullptr);

            // above_temp only used there. if above is nullptr, that mean the first addition, only add the node, dont connect with the above
            // if it is not nullptr, connect with above node, so skiplist structure will be protected
            if(above_temp != nullptr){
                above_temp->below = new_num;
            }
            above_temp = new_num;

            // new node's next will point the ptr's next node, after that ptr's next will point the new_num
            new_num->next = ptr->next;
            ptr->next = new_num;

            ptr = ptr->below;
        }   
    }
    
    // function will delete the selected node, and return the node (num) was existed or not before the deletion
    bool erase(int num) { // Time Complexity = O(log(n)), Space Complexity = O(1)
        DoublySkipList_Node* ptr = head;
        bool is_valid = false;

        // ptr will traverse the skiplist until find the num
        while(ptr){
            while(ptr->next && ptr->next->data < num){
                ptr = ptr->next;
            }

            //if num is equal to the num, that meain skiplist has this node, it should delete
            if(ptr->next && ptr->next->data == num){
                // that is classic linkedlist deletion
                DoublySkipList_Node* temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
                is_valid = true;
            } 
            // deletion should continue until ptr->below == nullptr, becuase that number has a height, all of that should delete
            ptr = ptr->below;    
        }
        return is_valid;
    }
};