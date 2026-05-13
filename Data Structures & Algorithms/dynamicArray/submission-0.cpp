class DynamicArray {
private: 
int* array = NULL;
int capacity;
int length;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->array = new int[capacity];
    }

    int get(int i) {
        return array[i];
    }

    void set(int i, int n) {
        array[i] = n;
    }

    void pushback(int n) {
        if(length == capacity){
            resize();
        }
        array[length] = n;
        length++;
    }

    int popback() {
        length--;
        return array[length];
    }

    void resize() {
        int* newArray = new int[capacity * 2];
        for(int i = 0; i < length; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = capacity * 2;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
