// union find algorithm 
// initially :
//      the size of every index will be 1
//      parent[i] = i for every i

ll find_set(ll a, vl &parent)
{
    if(a == parent[a])
        return a;
    return parent[a] = find_set(parent[a]);
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
