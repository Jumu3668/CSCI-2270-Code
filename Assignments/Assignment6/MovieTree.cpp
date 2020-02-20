#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST

MovieTree::MovieTree(){
  // Initialize any member variables of the class to default
  root = NULL;
}

MovieTree::~MovieTree(){
  // Free all memory that was allocated
  // deleteTree(root);
  deleteTree(root);
}
void deleteTree(MovieNode *node){
    if (node == NULL){
        deleteTree(node -> left);
        deleteTree(node -> right);

        cout << "\n Deleting node:"<< node -> title;
        delete node;
    }
}

void printMovieInverntoryHelper(MovieNode *node){
    if(node){
        printMovieInverntoryHelper(node -> left);
        cout << "Movie: " << node -> title << " " << node -> rating << endl;
        printMovieInverntoryHelper(node -> right);
    }
}

void MovieTree::printMovieInventory(){
    if (!root){
        cout << "Tree is Empty. Cannot print" << endl;
    }else{
        printMovieInverntoryHelper(root);
    }
}


MovieNode* addMovieNodeHelper(MovieNode *node, int ranking, string title, int year, float rating){
    if(!node){
        MovieNode *newNode = new MovieNode(ranking, title, year, rating);
        return newNode;
    }
    else if (title > node -> title){
        //place to right
        node -> right = addMovieNodeHelper(node -> right, ranking, title, year, rating);
    }else if (title < node -> title){
        node -> left = addMovieNodeHelper(node -> left, ranking, title, year, rating);

    }
    return node;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
  root = addMovieNodeHelper(root, ranking, title, year, rating);
}

string toLower(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

MovieNode* findMovieHelper(MovieNode* currNode, string title){
    if (!currNode){
        return NULL;
    }

    if(toLower(currNode -> title) == toLower(title))
        return currNode;

    if (currNode -> title > title)
        return findMovieHelper(currNode -> left, title);
    return findMovieHelper(currNode -> right, title);
}

void MovieTree::findMovie(string title){
  // Find the movie with the given title, then print out its information
  // Traverse through binary tree

    MovieNode* node = findMovieHelper(root, title);

    if (node != NULL){
        cout << "\nMovie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << node->ranking << endl;
        cout << "Title :" << node->title << endl;
        cout << "Year :" << node->year << endl;
        cout << "rating :" << node->rating << endl << endl;
    }
    else
        cout << "Movie not found. Make sure you are using correct spelling or correct capitalization." << endl;
}

void queryMoviesHelper(MovieNode* node, float rating, int year){
        if(node){
            if (node -> rating > rating && node -> year > year){
                cout << node -> title << "(" << node -> year << ")" << " " << node -> rating << endl;
            }
            queryMoviesHelper(node -> left, rating, year);
            queryMoviesHelper(node -> right, rating, year);
        }
}

void MovieTree::queryMovies(float rating, int year){
    //if node -> rating > rating && node -> year > year, print
    if (!root){
        cout << "Tree is empty. Cannot Print." << endl;
    }else{
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        queryMoviesHelper(root, rating, year);
        cout << endl;
    }

}

int numberOfNodes(MovieNode* currNode){
    int count = 1;
    if (currNode->left != NULL) {
        count += numberOfNodes(currNode->left);
    }
    if (currNode->right != NULL) {
        count += numberOfNodes(currNode->right);
    }
    return count;
}

float totalRating(MovieNode* currNode) {
    float total = currNode->rating;
    if (currNode->left != NULL) {
        total += totalRating(currNode->left);
    }
    if (currNode->right != NULL) {
        total += totalRating(currNode->right);
    }
    return total;
}

void MovieTree::averageRating() {
    if (root == NULL) {
        cout << "Average rating:0.0" << endl;
    } else {
        int nodes = numberOfNodes(root);
        float ratings = totalRating(root);
        float avg = ratings/nodes;
        cout << "Average rating:" << avg << endl;
    }
}
