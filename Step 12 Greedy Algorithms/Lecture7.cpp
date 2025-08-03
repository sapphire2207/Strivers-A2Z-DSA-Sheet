// N meetings in one room

// Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.
// Example:
// Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
// Output: 1 2 4 5

// Initial Thought Process:-
// Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. Hence we should choose meetings that end early and utilize the remaining time for more meetings.
// Approach: 
// To proceed we need a vector of three quantities: the starting time, ending time, meeting number. Sort this data structure in ascending order of end time. 
// We need a variable to store the answer. Initially, the answer is 1 because the first meeting can always be performed. Make another variable, say limit that keeps track of the ending time of the meeting that was last performed. Initially set limit as the end time of the first meeting.
// Start iterating from the second meeting. At every position we have two possibilities:-
// If the start time of a meeting is  strictly greater than limit we can perform the meeting. Update the answer.Our new limit is the ending time of the current meeting  since it was last performed.Also update limit.  
//  If the start time is less than or equal to limit  ,skip and move ahead. 
// Let's have a dry run by taking the following example.
// N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
// Initially set answer =[1],limit = 2.
// For Position 2 - 
// Start time of meeting no. 2 = 3 > limit. Update answer and limit.
// Answer = [1, 2], limit = 4.
// For Position 3 -
// Start time of meeting no. 3 = 0 < limit.Nothing is changed.
// For Position 4 -
// Start time of meeting no. 4 = 5 > limit. Update answer and limit.
// Answer = [1,2,4], limit = 7.
// For Position 5 -
// Start time of meeting no. 5 = 8 > limit.Update answer and limit.
// Answer = [1,2,4,5], limit = 9.
// For Position 6 -
// Start time of meeting no. 6 = 8 < limit.Nothing is changed.
// Final answer  =  [1,2,4,5]

#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public:
      bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
   void maxMeetings(int s[], int e[], int n) {
      struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);

      vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }

   }

};
int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}

// Output:
// The order in which the meetings will be performed is
// 1 2 4 5
// Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.
// Overall : O(n) +O(n log n) + O(n) ~O(n log n)
// Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.