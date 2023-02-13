#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.
// Follow up:
// Can you solve it using O(1) (i.e. constant) memory?
// Thought process:
// 1. Use two pointers, one moves one step at a time, the other moves two steps at a time.
// 2. If there is a cycle, the two pointers will meet at some point.
// 3. Move one of the pointers to the head of the list, and move both pointers one step at a time.
// 4. The point where the two pointers meet is the start of the cycle.
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    // Find the point where the two pointers meet.
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {       // Find the meeting point.

            // Move one of the pointers to the head of the list.
            // Move both pointers one step at a time.
            // The point where the two pointers meet is the start of the cycle.
            ListNode *slow2 = head;
            
            while (slow2 != slow)
            {
                slow2 = slow2->next;
                slow = slow->next;
            }
            
            return slow;
        }
    }
    
    return NULL;
}

