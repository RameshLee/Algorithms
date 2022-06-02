// Link: https://leetcode.com/problems/design-hit-counter/

class HitCounter {
public:
    HitCounter() {

    }

    void hit(int timestamp) {
        q.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!q.empty() && abs(q.front()-timestamp) >= 300) q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */