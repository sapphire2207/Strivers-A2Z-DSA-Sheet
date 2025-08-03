// Asteroid Collision

// In this problem, we are dealing with a simulation of asteroids moving in a row, represented by an array called asteroids. Each integer in the array represents an asteroid's size (absolute value) and direction (sign of the integer). Positive numbers mean the asteroid is moving to the right, while negative numbers mean the asteroid is moving to the left. All asteroids move at the same constant speed.
// The task is to simulate the collisions that may happen when asteroids meet as they move. When two asteroids collide, the following rules apply:
// If one asteroid is larger than the other, the smaller asteroid is destroyed.
// If both asteroids are the same size, they both are destroyed.
// Asteroids moving in the same direction do not collide.
// The goal is to determine the final state of the asteroids after all possible collisions have occurred.

// Optimal Approach:
// To solve this problem, we use a stack data structure that will help us manage the asteroid collisions efficiently. The stack is chosen because collisions affect the asteroids in a last-in, first-out manner: the most recently moving right asteroid can collide with the newly encountered left-moving one.
// Here's the intuition for the solution approach:
// If we encounter an asteroid moving to the right (x > 0), it won't collide with any of the previous asteroids. We add (push) this asteroid to the stack, as it could collide with a future left-moving asteroid.
// When an asteroid moving to the left (x < 0) is found, we need to check if it will collide with any of the right-moving asteroids already in the stack.
// If a collision is possible (the stack is not empty and the top asteroid in the stack is a positive number, meaning it is moving right), and the top asteroid in the stack is smaller than the current one (absolute size comparison), the top asteroid will explode (be removed by pop from the stack).
// If the top asteroid in the stack has the same size (but opposite direction) as the current one, they both explode (we pop the top of the stack without adding the current one).
// If the stack is empty or contains only asteroids moving to the left, it means there will be no collision for the current asteroid; therefore, we can safely add (push) the current asteroid to the stack.
// TC: O(2N) 
// SC: O(N)
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> stack;
            int n = asteroids.size(); // Get the size of the asteroids array
    
            // Loop through all asteroids using a traditional for loop
            for (int i = 0; i < n; i++) {
                int asteroid = asteroids[i];
    
                // If asteroid is moving to the right (positive), add it to the stack.
                if (asteroid > 0) {
                    stack.push_back(asteroid);
                } else {
                    // Handle collisions with asteroids in the stack moving to the right
                    while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroid) {
                        stack.pop_back(); // Pop the smaller asteroid as it is destroyed
                    }
                    
                    // If the top asteroid on the stack is the same size (opposite direction),
                    // both asteroids destroy each other.
                    if (!stack.empty() && stack.back() == -asteroid) {
                        stack.pop_back();
                    } 
                    // If the stack is empty or the top asteroid is also negative, add the current asteroid.
                    else if (stack.empty() || stack.back() < 0) {
                        stack.push_back(asteroid);
                    } 
                    // If none of the above conditions are met, the current asteroid is destroyed.
                }
            }
            return stack; // Return the state of the stack after all collisions
        }
    };
    