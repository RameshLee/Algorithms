// Link: https://leetcode.com/playground/5UPh5aB5

class Box{
public:
    static int totalObjects;

    int l,h;

    Box(){
        l=2, h=2;
        totalObjects++;
    }

    Box(const Box& box);

    void print(){
        printf("l=%d, h=%d\n",l,h);
    }
};

int Box::totalObjects = 0; // static object declaration

int main() {
    std::cout << "Hello World!\n";
    Box A; A.l = 4, A.h = 4;
    Box B;
    B.print();
    B = A; // invoking copy constructor
    B.print();


    printf("Total Objects: %d\n",Box::totalObjects); // static object count

    return 0;
}