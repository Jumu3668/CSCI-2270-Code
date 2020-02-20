#include <iostream>
#include <string>
#include "MovieTree.hpp"

using namespace std;


MovieTree::MovieTree()
{
    this -> root = NULL;
}

void deleteTree(TreeNode *del)
{
    if(del == NULL) return;

    else
    {
        deleteTree(del -> leftChild);
        deleteTree(del -> rightChild);
        LLMovieNode *done = del ->head;
        while(done -> next != NULL)
        {
            LLMovieNode *temp = done;
            done = done -> next;
            delete temp;
        }
        delete done;
        delete del;
    }
}

MovieTree::~MovieTree()
{
    TreeNode *del = root;
    deleteTree(root);
    root = NULL;
}


void traverseTree(TreeNode *temp){
    if(temp == NULL) return;
    else{
        LLMovieNode *llTemp = NULL;
            traverseTree(temp -> leftChild);
            llTemp = temp -> head;
            cout << "Movies starting with letter: " << temp->titleChar << endl;
            while(llTemp != NULL){
                cout << " >> " << llTemp->title << " " << llTemp->rating << endl;
                llTemp = llTemp -> next;
            }
            traverseTree(temp -> rightChild);

        return;
    }

}


void MovieTree::printMovieInventory(){
    traverseTree(root);

}


TreeNode *addHelper(TreeNode * temp, int ranking, string title, int year,float rating)
{
    char titleCharacter = title[0];

    if( temp == NULL)
    {
        LLMovieNode *newMovie = new LLMovieNode(ranking, title, year, rating);

        TreeNode *newNode = new TreeNode;
        newNode -> head = newMovie;
        newNode -> titleChar = titleCharacter;
        newNode -> parent = NULL;
        newNode -> rightChild = NULL;
        newNode -> leftChild = NULL;
        return newNode;
    }
    else if(temp -> titleChar > titleCharacter)
    {
        temp -> leftChild = addHelper(temp -> leftChild, ranking, title, year, rating);
    }
    else if(temp -> titleChar < titleCharacter)
    {
        temp -> rightChild = addHelper(temp -> rightChild, ranking, title, year, rating);
    }
    else
    {
        LLMovieNode *newMovie = new LLMovieNode(ranking, title, year, rating);
        LLMovieNode *search = temp -> head;
        if(search == NULL)
        {
            temp -> head = newMovie;
        }
        else if( search -> title > newMovie -> title)
        {
            newMovie -> next = search;
            temp -> head = newMovie;
        }
        else
        {
            while(search -> next && search -> next -> title < newMovie -> title)
            {
                search = search -> next;
            }
            newMovie -> next = search -> next;
            search -> next = newMovie;
        }

    }
    return temp;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{

    root = addHelper(root, ranking, title, year, rating);
}

TreeNode *deleteNode(TreeNode *current, char val)
{
    if(current == NULL)
    {
        return NULL;
    }
    else if(val < current -> titleChar)
    {
        current -> leftChild =deleteNode(current -> leftChild, val);
    }
    else if(val > current -> titleChar)
    {
        current -> rightChild = deleteNode(current -> rightChild, val);
    }
    else
    // CASE 1: NO CHILD NODES
    {
        if(current -> leftChild == NULL && current -> rightChild == NULL)
        {
            while(current -> head != NULL)
            {
                LLMovieNode *del = current -> head;
                current -> head = current -> head -> next;
                delete del;
            }
            delete current;
            current = NULL;
        }
    //CASE 2: RIGHT CHILD ONLY
        else if(current -> leftChild == NULL)
        {
            TreeNode *del = current;
            delete del;
            current = current -> rightChild;
        }
    //CASE 3: LEFT CHILD ONLY
        else if(current -> rightChild == NULL)
        {
            TreeNode *del = current;
            delete del;
            current = current ->leftChild;
        }
        else
        // FIND MINIMUM FROM RIGHT SUB TREE
        {
            TreeNode *temp = current -> rightChild;
            while (temp -> leftChild != NULL)
            {
                temp = temp -> leftChild;
            }
            current -> titleChar = temp -> titleChar;
            current -> head = temp -> head;
            current -> rightChild = deleteNode(current -> rightChild, temp -> titleChar);
        }

    }
    return current;
}


void MovieTree::deleteMovie(string title)
{
    TreeNode *temp = root;
    while(temp != NULL && temp->titleChar != title.front())
    {
        if(title.front() < temp -> titleChar)
        {
            temp = temp -> leftChild;
        }
        else
        {
            temp = temp -> rightChild;
        }
    }
    if( temp == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
    }
    else
    {
        LLMovieNode *LLtemp = temp -> head;
        if(LLtemp -> title.compare(title) == 0)
        {
            LLMovieNode *prev = LLtemp -> next;
            delete LLtemp;
            temp -> head = prev;
        }
        else
        {
            while(LLtemp != NULL)
            {
                LLMovieNode *prev;
                if(LLtemp->title.compare(title) == 0)
                {
                    LLMovieNode *del = LLtemp;
                    prev -> next = LLtemp -> next;
                    delete del;
                    del -> next = NULL;
                    break;
                }
                prev = LLtemp;
                LLtemp = LLtemp -> next;
            }
            if(LLtemp == NULL)
            {
                cout << "Movie: " << title << " not found, cannot delete." << endl;
            }

        }
        if(temp -> head == NULL)
        {
            root = deleteNode(root, temp -> titleChar);
        }
    }
}
