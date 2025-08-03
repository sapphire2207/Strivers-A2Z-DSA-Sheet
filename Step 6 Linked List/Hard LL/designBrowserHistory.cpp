// Problem: DESIGN A BROWSER HISTORY

// Problem statement:
// Your task is to maintain a data structure that supports the following functions of a web browser.

// 1- Browser(homepage): Set homepage of the browser

// 2- Visit(url): Visit the url from the current page. It clears up all the forward history.

// 3- Back(steps): Move ‘steps’ backward in the browser history

// 4- Forward(steps): Move ‘steps’ forward in the browser history
// Note:
// If you can’t move steps forward or backward, just return the last website that can be reached.

// The Queries are in the given format-:
// The first line of each query contains the string representing the homepage of the web browser.

// (1, url): Visit the url from the current page. 

// (2, steps): Move ‘steps’ backward in the browser history.

// (3, steps): Move ‘steps’ forward in the browser history.
// For example:
// You are queries as  [[“homepage.com”], [1 , “facebook.com”], [1, “codingninjas.com”],[2, 1], [3, 1]]
// 1 query is the query that sets the homepage as “homepage.com”.
// 2 query is the query to visit “facebook.com”
// 3 query is the query to visit “codingninjas.com”
// 4 query is the query that moves back one step to “facebook.com”
// 5 query is the query that moves forward one step to “codingninjas.com”

// Hence the answer is [“facebook.com”, “codingninjas.com”]

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node(): data(0), next(nullptr), back(nullptr) {};
    Node(string x): data(x), next(nullptr), back(nullptr) {};
    Node(string x, Node* next, Node* random): data(x), next(next), back(random) {};
};

class Browser
{
    Node* currentPage;
    public:
    
    // O(1)
    Browser(string &homepage)
    {
        // Write you code here
        currentPage = new Node(homepage);
    }

    // O(1)
    void visit(string &url)
    {
        // Write you code here
        Node* newNode = new Node(url);
        currentPage -> next = newNode;
        newNode -> back = currentPage;
        currentPage = newNode;
    }

    // O(Steps)
    string back(int steps)
    {
        // Write you code here
        while(steps){
            if(currentPage -> back){
                currentPage = currentPage -> back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage -> data;
    }

    // O(Steps)
    string forward(int steps)
    {
        // Write you code here
        while(steps){
            if(currentPage -> next){
                currentPage = currentPage -> next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage -> data;
    }
};
