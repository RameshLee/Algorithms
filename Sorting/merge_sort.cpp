// C++ program for building Heap from Array 

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
    {   int i = 0;

        vector<int> A; vector<int> B;
        while (1)//queue.q.size() == 1)
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

        while(left_index <= A.size() || right_index <= B.size())
        {

           /* printf("left_index: %d, right_index: %d\n", left_index, right_index);

            printf("BEFORE:\n");
            printf("A-Vector(%d): ", A.size());
            for (int i=0; i<A.size(); i++)
                printf("%d ", A[i]);
            printf("\n");
            printf("B-Vector(%d): ", B.size());
            for (int i=0; i<B.size(); i++)
                printf("%d ", B[i]);
            printf("\n");*/

            if (A.size() == 0)
            {
                new_vec.push_back(B[right_index]);
                B.erase(B.begin());
                right_index++;
            }
            else if (B.size() == 0)
            {
                new_vec.push_back(A[left_index]);
                A.erase(A.begin());
                left_index++;
            }
            else if (A[left_index] < B[right_index])
            {
                new_vec.push_back(A[left_index]);
                A.erase(A.begin());
                left_index++;
            }
            else if (A[left_index] > B[right_index])
            {
                new_vec.push_back(B[right_index]);
                B.erase(B.begin());
                right_index++;
            }

            /*printf("AFTER:\n");
            printf("A-Vector(%d): ", A.size());
            for (int i=0; i<A.size(); i++)
                printf("%d ", A[i]);
            printf("\n");
            printf("B-Vector(%d): ", B.size());
            for (int i=0; i<B.size(); i++)
                printf("%d ", B[i]);
            printf("\n\n");*/
        }
        return new_vec;
    }
};


// Driver Code 
int main() 
{

    int arr[] = {8, 22, 5, 1, 13, 0, 6, 3, 4, 2};
    MergeSort MS;
    MS.fill_input(10, arr);
    MS.queue.print();
    MS.merge_sort();
    MS.queue.print();

    printf("Exiting program! \n\n");
    return 0; 
} 
