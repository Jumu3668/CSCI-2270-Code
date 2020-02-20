#include <iostream>
#include <vector>
#include <cmath>    //for the floor function

using namespace std;

// Heap sort uses the binary tree but not binary search tree to sort
// will suffer from worst case searching than a binary search tree
// minheapify
class Heap {
    private:
        vector<int> h;
        // vector maintains numElements via .size();
        int parent(int i);
        int left(int i);
        int right(int i);
    public:
        Heap();
        int getSize();
        int insert(int k);
        int minheapify(int i);
        void printHeap();
        int minValue();
        int deleteMin();
        int Heapify(int i);
};

Heap::Heap() {
    cout << "New Heap!!" << endl;
}

int Heap::insert(int k) {
    int i = h.size();
    h.push_back(k);
    return minheapify(i);
}

int Heap::left(int i) {
    return 2*i +1;
}

int Heap::right(int i) {
    return 2*i+2;
}

int Heap::minValue() {  // If you want the value
    return h[0];
}

int Heap::Heapify(int i) {  // Better! Bottum-up sorts for us!
    int smol = i;
    int l = left(i);
    int r = right(i);

    if ((l < h.size()) && (h[l] < h[i]))   smol = l; // swap the two values. first comparison checks for segfault
    if ((r < h.size()) && (h[r] < h[i]))   smol = r;

    if (smol != i) {
        int tmp = h[i];
        h[i] = h[smol];
        h[smol] = tmp;
        Heapify(i);
    }
    return 0;

}

int Heap::deleteMin() { // If you want to update the minHeap for the next min value
    // Create a hole and fill it with the smallest child.
    h[0] = h[h.size()-1];
    h.pop_back();

    Heapify(0);
}

void Heap::printHeap() {
    for (int i = 0; i < h.size(); i++) {
        cout << h[i];
        if (i == h.size() -1)
            cout << ", ";
    }
    cout << endl;
}

int Heap::parent(int i) {
    // return ceil(i/2) -1;        both of these should return the same thing
    return floor((i-1)/2);
}

int Heap::minheapify(int i) {
    //base case index is 0 aka at root
    if (i == 0) return 0;

    int p = parent(i);
    if (h[i] < h[p]) {
        //perform swap
        int temp = h[i];
        h[i] = h[p];
        h[p] = temp;
        return minheapify(p);

    } else return 0;

}

int Heap::getSize() {
    return h.size();
}
int main() {

    Heap myHeap;    //Calls constructor and prints helpful message
    myHeap.insert(5);
    myHeap.insert(7);
    myHeap.insert(4);
    myHeap.insert(9);
    cout << "before entering the 6..." << endl;
    myHeap.printHeap();
    myHeap.insert(6);   //should be our first minheapify
    cout << "after inserting the 6..." << endl;
    myHeap.printHeap();


    int size = myHeap.getSize();    //gets original size of the vector before elements are being deleted.
    for (int i = 0; i < size; i++) {
        cout << "Min element is " << myHeap.minValue() << endl;
        myHeap.deleteMin();
    }

    return 0;
}
