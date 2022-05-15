// Link: https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
public:
    MovingAverage(int size) {
        this->k = size;
    }

    double next(int val) {
        // corner-case
        if (k == 1) return val;

        // case-1: partially filled queue
        if (q.size() < k) {
            q.push((double)val);
            queue<double> q2 = q; double n = (double)q2.size(); double sum = 0;
            while (!q2.empty()) sum += q2.front(), q2.pop();
            return (q.size() == k) ? MovingAvg = sum/n : sum/n;
        }
        // case-2: fully filled queue
        if (q.size() == k) {
            q.push((double)val);
            MovingAvg += (q.back()/(double)k) - (q.front()/(double)k); q.pop();
            return MovingAvg;
        }
        return -1;
    }
private:
    int k; queue<double> q; double MovingAvg = -1;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */