#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void displayMenu(){
    cout << endl;
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit\n" << endl;
}

int main(int argc, char* argv[]){
    MovieTree mt;
    string filename = "";
    //Argument count checker
    if (argc < 2){
        cout << "Not enough arguments" << endl;
        system("pause");

    }else if (argc > 2){
        cout << "Too many arguments" << endl;
        system("pause");
    }else{

        filename = argv[1];
        //Opening the input file and generating tree data===========================
        ifstream fs;
        fs.open(filename);
        string line = "";
        string ranking, title, year, rating;

        if (fs.is_open()){
            while (!fs.eof()){
                while (getline(fs, line)){
                    istringstream ss(line);

                    getline(ss, ranking, ',');
                    int rank = stoi(ranking);

                    getline(ss, title, ',');

                    getline(ss, year, ',');
                    int yr = stoi(year);

                    getline(ss, rating, ',');
                    float rt = stof(rating);

                    mt.addMovieNode(rank, title, yr, rt);
                }
            }
        }
        int input = 0;

        // Menu Driver =============================================================
        while (input != 5){
            displayMenu();

            //Gets initial user input
            string choice = "";
            cin >> choice;
            if (is_number(choice)){
                input = stoi(choice);
            }
            else
                cout << "\nPlease enter a valid number" << endl;

            switch(input){
                    //Option 1: Find a movie given title
                    case 1:
                        cout << "Enter title:" << endl;
                        cin.ignore();
                        getline(cin, title);
                        mt.findMovie(title);
                        break;
                    //Option 2: Query Movies given year & rating
                    case 2:
                        float rating;
                        int year;
                        cout << "Enter minimum rating:" << endl;
                        cin >> rating;
                        cout << "Enter minimum year:" << endl;
                        cin >> year;
                        mt.queryMovies(rating, year);
                        break;
                    //Option 3: Print Movie inventory
                    case 3:
                        mt.printMovieInventory();
                        break;
                    //Option 4: Print average rating of all movies combined
                    case 4:
                        mt.averageRating();
                        break;
                    //Option 5: Quit program
                    case 5:
                        cout << "Goodbye!" << endl;
                        break;
            }
        }
    }
    return 0;
}
