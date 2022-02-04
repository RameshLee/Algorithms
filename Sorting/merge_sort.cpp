// C++ program for Merge Sort using Queue

#include <iostream>
#include <vector>
using namespace std;


class Queue
{
public:
    vector< vector<int> > q;

     void push(vector<int> value){
       q.insert(q.end(),value);
     }

     vector<int> pop(){
         vector<int> front = q[0];
         q.erase(q.begin());
         return front;
     }

     void print()
     {
        printf("q-contents(%d): ", (int)q.size());
        for (int i = 0; i < (int)q.size(); i++)
        {
            printf(" ");
            for (int j = 0; j < (int)q[i].size(); j++)
                printf("%d ", q[i][j]);
        }
        printf("\n");
     }

};

class MergeSort
{
public:
    Queue queue;
    vector<int> v;
    int n;

    void fill_input(int size, int input[])
    {
        n = size;
        for (int i=0; i<n; i++)
        {
            v.clear();
            v.push_back(input[i]);
            queue.push(v);
        }
    }

    void merge_sort()
    {
        vector<int> A; vector<int> B;
        while (1)
        {
            A.clear(); B.clear();
            A = queue.pop();
            B = queue.pop();
            queue.push(merge(A,B));
            queue.print();

            if ((int)queue.q.size() == 1)
                break;
        }
    }

    vector<int> merge(vector<int> A, vector<int> B)
    {
        vector<int> new_vec;
        int left_index = 0;
        int right_index = 0;

        int initial_size_A = (int)A.size();
        int initial_size_B = (int)B.size();

        while(left_index < initial_size_A || right_index < initial_size_B)
        {
            if (left_index == initial_size_A)//(int)A.size() == 0)
            {
                new_vec.push_back(B[right_index++]);
            }
            else if (right_index == initial_size_B)//(int)B.size() == 0)
            {
                new_vec.push_back(A[left_index++]);
            }
            else if (A[left_index] < B[right_index])
            {
                new_vec.push_back(A[left_index++]);
            }
            else if (A[left_index] > B[right_index])
            {
                new_vec.push_back(B[right_index++]);
            }
        }
        return new_vec;
    }
};


// Driver Code 
int main() 
{

    int arr[] = {0, 9, 7, 3, 6, 5, 1, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    MergeSort MS;
    MS.fill_input(size, arr);
    MS.queue.print();
    MS.merge_sort();
    MS.queue.print();

    printf("Exiting program! \n\n");
    return 0; 
} 
