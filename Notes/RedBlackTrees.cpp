Red black parent
Every black parent has a red child.
234 nodes

class Node {
    int n;
    K[] key;
    V[] val;
    Node[] children
}
int n can only be 2, 3, or 4
if 2, then key will be K[2] and value will be V[2].
Children will be Node[3]


For binary tree , we eliminate most of tree in 2 decisions for a tree 3 high

For a trinary tree, this elimination will be even greater.

O(n) -> 20
2^10 is about 1000 or 1 kilobyte
2^20 is about 1 million or 1 megabyte
2^30 is about 1 billion or 1 gigabyte

Graph theory
Pointers allow us to travel
We use an adjacency matrix
Have the same nodes going both ways
in binary we say whether or not a path exists
represented with either a 0 or 1
Undirecetd Graph vs Directed Graph

Undirected
    Edges are bidirectional
    Adjacency matrix is symmetric
Directed
    Edges are unidirectional
    Each edge in the adjacency matrix is an outgoing edge
    Adjacency matrix may not be symmetric
