void remove_negative(set<int>& Set) {
    set<int> Result;
    for (auto it = Set.begin(); it!=Set.end(); it++) {
        if (*it >= 0) {
            Result.insert(*it);
        }
    }
    Set = std::move(Result);

    // iterator -> if it points to begin(), end(), then after erasing an element, the iterator points to same begin() or end()..

    /*
    Set = { 0 , 1 , 3 }
     i -> 0, j -> 1, k -> 1, l -> 3
     s.erase(j)
     { 0, 3 }
     i -> 0, l -> 3, j,k invalid
     auto j = i;
    */

    for (auto it = Set.begin(); it!=Set.end(); ) {
        if (*it < 0) {
            Set<int>::iterator curr = it;
            ++it; // it=it->next;
            Set.erase(curr);
            continue;
        }
        it++;
        // it=it->next;
    }

    int a = 3;
    int b = ++a; // b = 4;
    // a=4

    int i=0;
    while (1) {
        if (i >= vec.size()) break;
        if (vec[i] < 0) {
            vec.erase(vec.begin() + i); // Time=O(N), Space=O(1) ->space-efficient
            continue;
        }
        i++;
    }

    // linear-time, constant-space
    vec = {1,2,-4,5,-6} ==> vec={1,2,5};
    vec = {1,2,5//,5,-6};
    //vec.resize();

    vector<int> result; // S=O(N)
    for (auto i:vec) {
        if (i >= 0)
            result.push_back(i);
    }

    //
    int index = 0;
    for (int j=0; j<vec.size(); j++) {
        if (vec[index] < 0) {
            if (index != j && vec[j] >= 0) {
                vec[index] = vec[j];
                index++;
            }
        }
    }
    //

    // vec = {-1,1,2,-4,5,-6,..., 1,2,5}
    // vec = {-1//,1}; // vec = {1};
    int index = 0;
    for (int j=0; j<vec.size(); j++) {
        if (vec[j] >= 0) {
            vec[index] = vec[j];
            index++;
        }
    }

    // vec = {-1//,1};
    // index = 1;
    vec.resize(index);
}

/////////////////////////////////////////////////













