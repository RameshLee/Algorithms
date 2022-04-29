// Link: https://leetcode.com/playground/aZ8XT2FP

class cmp{
public:
    bool operator()(int a, int b)const{
        return a>b;
    }
};

int main() {
    std::cout << "Hello World!\n";
    set<int,cmp> Set;
    Set.insert(1);
    Set.insert(2);
    Set.insert(3);

    printf("%d\n", *Set.rbegin());
    return 0;
}