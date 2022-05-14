// Link: https://leetcode.com/playground/bJVB9j8X

void disp(int a) {
    printf("%d\n",a);
}

class ptrDemo {
private:
    typedef void (*fPtr)(int);
public:
    void demonstrate() {
        fPtr fPtr1 = NULL, fPtr2 = NULL;
        fPtr1 = &disp;
        fPtr2 = disp;
        (*fPtr1)(10);
        fPtr2(10);
    }

public:
    void passbyreference() {
      int data = 27;
      int *p = &data;
      fun(&p);
      printf("%d", *p);
    }
public:
    void incrementpointers() {
        int i;
        int *ptr = new int[5];
        int *A = ptr;
        for (i=0; i<5; i++) ptr[i] = (i+1)*(i+1);   // [1,4,9,16,25]
        print(A);
        printf("Ans: %d, ", *ptr++);    // post-increment the pointer ptr
        print(A);
        printf("Ans: %d, ", (*ptr)++);  // post-increment the value pointed by ptr
        print(A);
        printf("Ans: %d, ", *ptr);      //
        print(A);
        printf("Ans: %d, ", *++ptr);    //
        print(A);
        printf("Ans: %d, ", ++*ptr);    //
        print(A);


    }
public:
    void triplepointers() {
        int acData[2][3] = {{1, 2, 15}, {200, 215, 400}};
        int(*pcData)[2][3] = &acData;
        printf("%d\t", ***pcData);
        //printf("%d\t", ***(pcData + 1)); // returns garbage value
        printf("%d\t", **(*pcData + 1));
        printf("%d\t", *(*(*pcData + 1) + 2));
    }
private:
    void print(int *A) {
        cout <<"Arr: ";
        for (int i=0; i<5; i++) {
            printf("%d ", A[i]);
        } cout<<endl;
    }

    void fun(int **p) {
      int q = 40;
      *p = &q;
    }
};

int main() {
    ptrDemo f;
   // f.passbyreference();
   //f.incrementpointers();
  //  f.triplepointers();
   f.demonstrate();
    return 0;
}
