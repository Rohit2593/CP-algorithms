struct Query {
    int l, r, idx ;
} ;

bool comp(Query &q1, Query &q2) {
    if(q1.l != q2.l)
        return q1.l < q2.l ;
    return q1.r < q2.r ;
}

ll add(ll idx) {
    // 
    return 0 ;
}

ll subtract(ll idx) {
    // 
    return 0 ;
} 

vector<ll> mo_s_algorithm(vector<Query> queries) { // time complexity : ((N + Q) sqrt(N) )
    int q = (int) queries.size() ;

    sort(queries.begin(), queries.end(), comp) ;

    vector<ll> ans(q) ;

    ll currL = 0, currR = -1 ;

    ll currAns = 0 ;

    for(auto i : queries) {
        while(currL > i.l) {
            currL--;
            currAns += add(currL) ;
        }

        while(currL < i.l) {
            currAns += subtract(currL) ;
            currL++;
        }

        while(currR > i.r) {
            currAns += subtract(currR) ;
            currR--;
        }

        while(currR < i.r) {
            currR++;
            currAns += add(currR) ;
        }

        ans[i.idx] = currAns ;
    }

    return ans ;
}

// testing