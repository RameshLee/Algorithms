// C++ header file for binary heap

class maxHeap
{
public:
    vector<int> arr;
    int n;

    maxHeap(int size, int input[])
    {
        n = size;
        for (int i=0; i<size; i++)
            arr.push_back(input[i]);

    }

    ~maxHeap() {}

    void print()
    {
        printf("arr: ");
        for (int i=0; i<n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    void max_heapify(int i)
    {
        //printf("i: %d \n", i);
        int largest = i;
        int l = 2*i + 1; //left-child
        int r = 2*i + 2; //right-child

        if (l < n && arr[l] > arr[largest])
            largest = l;

         if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
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
        swap(arr[0], arr[n-1]);

        // 2) delete last element
        n--;

        // 3) heapify the root node
        max_heapify(0);
        print();
    }

    void deleteNode(int s)
    {
        // 1) find index of element s and swap it with last element
        int index;
        for (index=0; index<n; index++)
            if (arr[index] == s)
                break;
        swap(arr[n-1], arr[index]);

        // 2) delete the node s
        n--;

        // 3) heapify the inserted node
        max_heapify(index);
        print();
    }

    void insertNode(int s)
    {
        // 1) increase heap size
        n++;

        // 2) insert new node at end of the heap
        arr[n-1] = s;

        // 3) heapify the inserted node
        bubble_up(n-1);
        print();
    }

    void bubble_up(int i)
    {
        //find parent
        int parent = (i-1)/2; //index
        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            bubble_up(parent);
        }
    }

};

