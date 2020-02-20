#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct Park{
    string parkname;
    string  state;
    int area;
};

Park parksList[100];

void addPark(Park parks[],string parkname, string state, int area, int length){
    parks[length].parkname = parkname;
    parks[length].state = state;
    parks[length].area = area;
}

void printList(const Park parks[], int length){
    for(int i=0; i<length-1; i++){
        cout << parks[i].parkname << "[" << parks[i].state << "]" << "Area: " << parks[i].area << endl;
    }
}

int main( int argc, char *argv[]){
    cout << "File is working";
    ifstream fin("park.csv");
    int length=0;

    if(fin.is_open()){
        int i = 0;
        string input;
        string parkname;
        string state;
        int area;
        cout << "file is open";
        cout << endl; 
        while(!fin.eof()){
            getline(fin, input, ',');
            parkname = input;
            
            getline(fin,input, ',');
            state = input;

            getline(fin, input);
            stringstream convert(input);
            convert >> area;
            
            addPark(parksList, parkname, state, area, length++);
            

        }
        fin.close();
        printList(parksList, length);
        cout << endl;
        cout << "PARKS WITH MORE THAN MINIMUM AREA:";
        cout << endl;

        ofstream out(argv[2]);
        if(out.is_open()){
            int minArea;
            stringstream area(argv[3]);
            area >> minArea; 

            for(int k=0; k < 100; k++ ){
                if(parksList[k].area >= minArea){
                    out << parksList[k].parkname << ' ' << parksList[k].state << ' ' << parksList[k].area << ' ';
                }
            }
        }
    }else{
        cout << " Failed to  open the file";
        cout << endl;

    }
    return 0;
}
