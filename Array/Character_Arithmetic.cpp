// Link: https://leetcode.com/playground/CXkpZBJk

int main() {
    std::cout << "Hello World!\n";

    /*
     string code = "1234";
    printf("code: %s\n", code.c_str());

    string number; number += code[1];
    int digit = (stoi(number)+9 + 8) % 9;
    printf("digit: %d\n", digit);
    char c = static_cast<char>(digit);
    printf("character: %c\n", c);

    code.erase(code.begin()+1);
    code.insert(code.begin()+1,'9');
    printf("code: %s\n", code.c_str());
    */

    ////////////////
    string code = "8888";
    int k = 0;

    int digit = code[k] - '0'; // convert character to integer
    printf("%d \n", digit);

    char c = digit + '0'; // convert integer to character
    printf("%c \n", c);
}