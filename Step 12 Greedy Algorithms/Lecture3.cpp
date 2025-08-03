// Shortest Job First (or SJF) CPU Scheduling

// Problem Statement: Given a list of job durations representing the time it takes to complete each job. Implement the Shortest Job First algorithm to find the average waiting time for these jobs.

// Example 1:
// Input:jobs = [3, 1, 4, 2, 5]   
// Output: 4
// Explanation: 
// The first job that will be executed is of duration 1 and the waiting time for it will be 0.
// After the first job, the next shortest job with a duration of 2 will be executed with a waiting time of 1.
// Following the completion of the first two jobs, the next shortest job with a duration of 3 will be executed with a waiting time of 3 (1 + 2).
// Then, the job with a duration of 4 will be executed with a waiting time of 6 (1 + 2 + 3).
// Finally, the job with the longest duration of 5 will be executed with a waiting time of 10 (1 + 2 + 3 + 4).
// Hence, the average waiting time is calculated as (0 + 1 + 3 + 6 + 10) / 5 = 20 / 5 = 4.

// Optimal Approach
// We implement the Shortest Job Duration First algorithm using the Greedy technique by selecting the shortest job from the array. To always select the shortest job first we sort the job duration array in ascending order based on their duration.
// Once the jobs are sorted, we iterate through each job in the sorted list. For each iteration the waiting time is the sum of the total time taken by all previous jobs. We calculate the waiting time for each job and update the total time taken by adding the duration of the current job to the total waiting time.
// TC: O(nlogn + n)                            
// SC: O(1)
#include<bits/stdc++.h>
using namespace std;

// Function to calculate average
// waiting time using Shortest
// Job First algorithm
float shortestJobFirst(vector<int> jobs) {
    // Sort the jobs in ascending order
    sort(jobs.begin(), jobs.end()); 

    // Initialize total waiting time
    float waitTime = 0; 
    // Initialize total time taken
    int totalTime = 0; 
    // Get the number of jobs
    int n = jobs.size(); 

    // Iterate through each job
    // to calculate waiting time
    for(int i = 0; i < n; ++i) {
        
        // Add current total
        // time to waiting time
        waitTime += totalTime; 
        
        // Add current job's
        // time to total time
        totalTime += jobs[i]; 
    }
    
    // Return the average waiting time
    return waitTime / n; 
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}
                            
                        