// Priority queue STL template for <pair> in C++

class myComparator{
public:
    using pairing = pair<int,int>;

    constexpr bool operator()(pairing &a, pairing &b)
    {
        return a.second > b.second;
    }
};


struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};


int main() {
    using pairing = pair<int,int>;

    priority_queue<pairing, vector<pairing>, myComparator> pq;

    // ways to intialize priority queue
    // 1) insert ele one by one at T=O(N logN)
    // 2) build heap altogether using "priority_queue<type> pq(vec.begin(), vec.end();" Here, T = O(N).

    pq.push(make_pair(1,93));
    pq.push(make_pair(2,91));
    pq.push(make_pair(3,99));
    pq.push(make_pair(4,97));

    while (!pq.empty()){
        printf("(%d,%d)\n", pq.top().first, pq.top().second);
        pq.pop();
    }

}