/// https://leetcode.com/playground/hWCU76Ni

// MaxHeap: Library Implementation in C++

class heap {
private:
    int n; vector<float> nums;
    
public:
    heap(vector<float> input):nums(input),n(input.size()) {}
    ~heap() {}
    void print() {
        printf("Heap: "); for (auto i:nums) cout<<i<<","; cout<<endl;
    }
public:
    void buildheap() {
        for (int i=n/2; i>=0; i--) {
            heapify(i);
        }
    }

    void deleteRoot() {
        // swap root and last element
        std::swap(nums[0], nums[n-1]);    
        nums.pop_back(), n--;
        heapify(0);
    }
    
    void deleteNode(float target) {
        // find target index
        int i; for (i=0; i<n; i++) if (nums[i] == target) break;
        std::swap(nums[i], nums[n-1]);
        nums.pop_back(), n--;
        heapify(0);
    }
    
    void insertNode(float target) {
        // insert at the bottom-most
        nums.push_back(target), n++;
        bubbleup(n-1);
    }
private:
    void heapify(int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if (l<n && nums[largest]<nums[l]) largest = l;
        if (r<n && nums[largest]<nums[r]) largest = r;
        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            heapify(largest);
        }
    }
    
    void bubbleup(int i) {
        auto parent = (i-1)/2;
        if (nums[parent] < nums[i]) {
            std::swap(nums[parent], nums[i]);
            bubbleup(parent);
        }
    }
};

int main() {
    std::cout << "Hello World!\n";
    heap H(vector<float>({1,4,5,2,3,6,7}));
    H.buildheap();
    H.print();
    H.insertNode(9);
    H.print();
}