// Link: https://leetcode.com/problems/design-linked-list/

// 1) Using deque (doubly linked list) STL

class MyLinkedList {
public:
    deque<int> L;

    MyLinkedList() {

    }

    int get(int index) {
        if (index >= 0 && index < L.size()){
            deque<int>::iterator it = L.begin();
            std::advance(it,index);
            return *it;//List[index];
        }
        return -1;
    }

    void addAtHead(int val) {
        L.push_front(val);
    }

    void addAtTail(int val) {
        L.push_back(val);
    }

    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= L.size()){
            deque<int>::iterator it = L.begin();
            std::advance(it,index);
            L.insert(it, val);
        }
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < L.size()){
            deque<int>::iterator it = L.begin();
            std::advance(it,index);
            L.erase(it);
        }
    }
};

// 2) Using pointers only
class Node{
public:
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}
    Node(int a) : val(a), next(nullptr) {}
    Node(int a, Node* b) : val(a), next(b) {}

};

class MyLinkedList {
public:
    Node *head;

    MyLinkedList() {
        head = NULL;
    }

    void print(){
      /*  Node* tail = head;
        printf("List: ");
        while (tail != NULL) {
            printf("%d ", tail->val);
            tail = tail->next;
        }
        cout<<endl;*/
    }

    int get(int index) {
        int i = 0;
        Node* temp = head;
        while (temp!=NULL){
            if (i == index) {
                 print();
                return temp->val;
            }
            temp = temp->next; i++;
        }
        print();
        return -1;
    }

    void addAtHead(int val) {
        Node* curr = new Node(val);
        curr->next = head;
        head = curr;
        print();
    }

    void addAtTail(int val) {

        if (!head) {
            addAtHead(val);
            print();
            return;
        }

        Node* curr = new Node(val);
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = curr;
        print();
    }

    void addAtIndex(int index, int val) {

        if (index == 0){
            addAtHead(val);
            print();
            return;
        }

        int i = 0;
        Node* temp = head;
        Node* prev = new Node(-99,head);
        while (temp != NULL){
            if (i==index){
                Node* curr = new Node(val);
                prev->next = curr;
                curr->next = temp;
                print();
                return;
            }
            printf("Done trying to add bw %d and %d\n", prev->val, temp->val);
            temp = temp->next; i++;
            prev = prev->next;
        }
        if (i==index){
            Node* curr = new Node(val);
            prev->next = curr;
            curr->next = temp;
            print();
            return;
        }
        print();
    }

    void deleteAtIndex(int index) {

        if (index == 0){
            if (head) head = head->next;
            print();
            return;
        }

        int i = 0;
        Node* temp = head;
        Node* prev = new Node(-99,head);
        while (temp != NULL){
            if (i==index){
                prev->next = temp->next;
                 print();
                return;
            }
            temp = temp->next; i++;
            prev = prev->next;
        }
        print();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */