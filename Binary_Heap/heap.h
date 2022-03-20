// C++ header file for binary heap


class maxHeap
{
public:
    vector<float> nums;
    int n;

    maxHeap(int size, int input[])
    {
        n = size;
        for (int i=0; i<n; i++)
            nums.push_back(input[i]);
    }

    ~maxHeap() {}

    void print()
    {
        printf("nums: ");
        for (int i=0; i<nums.size(); i++)
            printf("%0.0f ", nums[i]);
        printf("\n");
    }

    void max_heapify(int i)
    {
        //printf("i: %d \n", i);
        int largest = i;
        int l = 2*i + 1; //left-child
        int r = 2*i + 2; //right-child

        if (l < n && nums[l] > nums[largest])
            largest = l;

         if (r < n && nums[r] > nums[largest])
            largest = r;

        if (largest != i)
        {
            swap(nums[i], nums[largest]);
            max_heapify(largest);
        }
    }

    void buildHeap()
    {
        for (int i = n/2; i >= 0; i--)
            max_heapify(i);

    }

    void deleteRoot()
    {
        // 1) delete top, i.e., swap first and last element
        swap(nums[0], nums[n-1]);

        // 2) delete last element
        nums.pop_back();
        n--;

        // 3) heapify the root node
        max_heapify(0);
        print();
    }

    void deleteNode(float s)
    {
        // 1) find index of element s and swap it with last element
        int index;
        for (index=0; index<n; index++)
            if (nums[index] == s)
                break;
        swap(nums[n-1], nums[index]);

        // 2) delete the node s
        nums.pop_back();
        n--;

        // 3) heapify the inserted node
        max_heapify(index);
        print();
    }

    void insertNode(float s)
    {
        // 1) increase heap size
        n++;

        // 2) insert new node at end of the heap
        nums.push_back(s);

        // 3) heapify the inserted node
        bubble_up(n-1);
        print();
    }

    void bubble_up(int i)
    {
        //find parent
        int parent = (i-1)/2; //index
        if (nums[parent] < nums[i])
        {
            swap(nums[parent], nums[i]);
            bubble_up(parent);
        }
    }

    void peek()
    {
        printf("Peek: %0.02f\n", nums[0]);
    }

};