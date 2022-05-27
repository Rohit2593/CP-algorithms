// union find algorithm 
// initially :
//      the size of every index will be 1
//      parent[i] = i for every i
 
// applications : 
// detecting cycle in a graph ( in the union function if a!=b, cycle is not present for edge (a, b), but if a == b then there is a cycle )
// finding the number of connected components in the graph : initialize ans to n (number of nodes) and decrement the ans if union operation is performed on two sets

ll find_set(ll a, vl &parent)
{
    if(a == parent[a])
        return a;
    return parent[a] = find_set(parent[a], parent);
}

void union_set(ll a, ll b, vl &parent, vl &size)
{
    a = find_set(a, parent);
    b = find_set(b, parent);

    if(a!=b) {
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
