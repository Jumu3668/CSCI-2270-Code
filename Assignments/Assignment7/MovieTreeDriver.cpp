#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void mainMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Delete a movie" << endl;
    cout << "3. Quit" << endl;
}


int main(int argc, char *argv[])
{

    MovieTree mov;
    string input;
    string title;
    int year;
    float rating;
    int ranking;

    if(argc <2) return -1;

    ifstream movies(argv[1]);
    if(movies.is_open())
    {
        while(!movies.eof())
        {

            string previous = title;

            //rank
            getline(movies, input, ',');
            stringstream to(input);
            to >> ranking;

            //title
            getline(movies, title, ',');

            //year
            getline(movies, input, ',');
            stringstream to2(input);
            to2 >> year;

            //rating
            getline(movies, input);
            stringstream to3(input);
            to3 >> rating;

            if(previous.compare(title) == 0)
            {
            break;
            }

            mov.addMovie(ranking, title, year, rating);
        }
        movies.close();
    }



    mainMenu();
    getline(cin, input);
    while (input != "3")
    {
        switch(stoi(input))
        {
        case 1:
            mov.printMovieInventory();
            mainMenu();
            break;
        case 2:
            cout << "Enter a movie title:" << endl;
            getline(cin, input);
            mov.deleteMovie(input);
            mainMenu();
            break;
        case 3:
            break;
        }
        getline(cin, input);
    }
    cout << "Goodbye!" << endl;
    return 0;
}
