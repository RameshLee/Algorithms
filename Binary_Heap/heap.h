// C++ header file for binary heap

class heap
{
public:
    vector<int> arr;
    int n;

    heap(int size, int input[])
    {
        n = size;
        for (int i=0; i<size; i++)
            arr.push_back(input[i]);

    }

    ~heap() {}

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

    void min_heapify(int i)
    {
        int smallest = i;
        int l = 2*i + 1; //left-child
        int r = 2*i + 2; //right-child

        if (l < n && arr[l] < arr[smallest])
            smallest = l;

         if (r < n && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            min_heapify(smallest);
        }
    }

    void buildHeap(int option)
    {
        // option 0: minHeap, else, maxHeap
        if (option == 0)
        {
            for (int i = n/2; i >= 0; i--)
                min_heapify(i);
        }
        else
        {
            for (int i = n/2; i >= 0; i--)
                max_heapify(i);
        }
    }

    void deleteRoot()
    {
        // 1) delete top, i.e., swap first and last element
        swap(arr[0], arr[n-1]);

        // 2) delete last element
        n--;

        // 3) heapify the root node
        //min_heapify(1);
        max_heapify(0);
        print();
    }

    void insertNode(int s)
    {
        // 1) increase heap size
        n++;

        // 2) insert new node at end of the heap
        arr[n-1] = s;

        // 3) heapify the inserted node
        //min_heapify(n-1);
        //bubble_up(n-1);
        buildHeap(1);
        print();
    }
};

