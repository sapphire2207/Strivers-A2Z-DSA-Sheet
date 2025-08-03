// Trapping Rainwater Problem

// Problem Statement
// You are given an array of non-negative integers where each integer represents the height of a building. The width of each building is assumed to be 1 unit. When it rains, water gets trapped between the buildings. Your task is to determine the total amount of water that can be stored between the buildings.
// Water can only be stored between two taller buildings.
// If there is a flat surface, water will simply flow off the buildings.

// Brute Force:
// Water can be trapped only if a building has a taller building on both its left and right sides.
// The amount of water stored above a building depends on:
// The tallest building to the left of the current building.
// The tallest building to the right of the current building.
// The maximum water level at any building is determined by the minimum of:
// The tallest building to the left.
// The tallest building to the right.
// The amount of water stored at a building = (Minimum of left max and right max) - Current height
// For each building, determine:
// Left Max: The tallest building height to the left of the current building.
// Right Max: The tallest building height to the right of the current building.
// Use the formula:
// Water Stored=min(LeftMax,RightMax) - Height of Current Building
// Sum up the water stored at each building to get the total trapped water.
// Prefix and Suffix Arrays
// Instead of calculating Left Max and Right Max for every building separately (which would be slow), we use two arrays:
// Prefix Max Array (Left Max)
// Stores the maximum height encountered so far from the left side.
// Suffix Max Array (Right Max)
// Stores the maximum height encountered so far from the right side.
// Time Complexity: 
// Computing Prefix Max → O(N)
// Computing Suffix Max → O(N)
// Computing Total Water → O(N)
// Total Complexity → O(3N) => O(N) (linear time)
// Space Complexity: 
// Using Extra Arrays: O(N) for Prefix Max + O(N) for Suffix Max → O(2N)

#include<bits/stdc++.h>
using namespace std;

int trapRainwater(vector<int>& height){
    int n = height.size();
    int totalHeight = 0;

    int prefixMax[n] = {0};
    prefixMax[0] = height[0];
    for(int i = 1; i < n; i++){
        prefixMax[i] = max(prefixMax[i-1], height[i]);
    }

    int suffixMax[n] = {0};
    suffixMax[n-1] = height[n-1];
    for(int i = n-2; i > 0; i--){
        suffixMax[i] = max(suffixMax[i+1], height[i]);
    }

    for(int i = 0; i < n; i++){
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(height[i] < leftMax && height[i] < rightMax){
            totalHeight += min(leftMax, rightMax) - height[i];
        }
    }
    return totalHeight;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total trapped water: " << trapRainwater(height) << endl;
    return 0;
}

// Optimal Approach:
// Use two pointers: left (starting from the left) and right (starting from the right).
// Maintain two variables: leftMax and rightMax to track the highest buildings from both sides.
// Move the pointer that has the smaller height, update leftMax or rightMax, and calculate the water trapped at that position.
// O(N) time complexity and O(1) space complexity:
#include<bits/stdc++.h>
using namespace std;

int trapRainwater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0; // Edge case: No buildings, no water trapped

    int left = 0, right = n - 1; // Two pointers
    int leftMax = 0, rightMax = 0; // Track max height from left and right
    int totalWater = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (leftMax > height[left]) {
                totalWater += (leftMax - height[left]); 
            } else {
                leftMax = height[left];
            }
            left++; // Move left pointer
        } else {
            if (rightMax > height[right]) {
                totalWater += (rightMax - height[right]);
            } else {
                rightMax = height[right];
            }
            right--; // Move right pointer
        }
    }

    return totalWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total trapped water: " << trapRainwater(height) << endl;
    return 0;
}
