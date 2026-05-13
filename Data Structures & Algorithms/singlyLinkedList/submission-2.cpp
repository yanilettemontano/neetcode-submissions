class LinkedList {
private:
struct Node{
int data;
struct Node* next;
Node(int val) : data(val), next(nullptr){}
};
int size;
Node* head;
Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            if(count == index){
                return current->data;
            }
            current = current->next;
            count++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (size == 0) tail = newNode;
        size++;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) return false;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (size == 1) tail = nullptr;
            delete temp;
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) prev = prev->next;
            Node* temp = prev->next;
            prev->next = temp->next;
            if (index == size - 1) tail = prev;
            delete temp;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head;
        while (curr) {
            res.push_back(curr->data);
            curr = curr->next;
        }
        return res;
    }
};
