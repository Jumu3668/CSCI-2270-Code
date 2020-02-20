void Graph::addEdge(string v1, string v2, int num) {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] -> name == v1) {
            for (int j = 0; j < vertices.size(); j++) {
                if (vertices[j] -> name == v2 && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i] -> adj.push_back(av);
                    av.weight = num;
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j] -> adj.push_back(av2);
                    av2.weight = num;
                }
            }
        }
    }
}
void Graph::addVertex(string name) {
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] -> name == name) {
            found = true;
        }
    }
    if (found == false) {
        vertex *v = new vertex;
        v -> name = name;
        vertices.push_back(v);
    }
}
int sumRange(node *currNode int low, int high) {
    if (!currNode) return 0;
    if (currNode -> data == high && currNode -> data == low)
        return currNode -> data;
    if (currNode -> data <= high && currNode -> data >= low) {
        return currNode -> data + sumRange(currNode -> left, low, high) + sumRange(currNode -> right, low, high);
    }
}
