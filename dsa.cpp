//min heap

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Extract Minimum
    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Get Min
    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    // Decrease Key
    void decreaseKey(int i, int newVal) {
        if (i >= heap.size()) return;
        heap[i] = newVal;
        heapifyUp(i);
    }

    // Increase Key
    void increaseKey(int i, int newVal) {
        if (i >= heap.size()) return;
        heap[i] = newVal;
        heapifyDown(i);
    }

    // Search
    int search(int key) {
        for (int i = 0; i < heap.size(); i++)
            if (heap[i] == key)
                return i;
        return -1;
    }

    // Display
    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

    // Size
    int size() {
        return heap.size();
    }

    // Empty Check
    bool isEmpty() {
        return heap.empty();
    }
};

// ==================== TEST MIN HEAP ====================
int main() {
    MinHeap h;
    h.insert(10);
    h.insert(30);
    h.insert(5);
    h.insert(20);

    cout << "Min Heap: ";
    h.display();

    cout << "Extract Min: " << h.extractMin() << endl;

    cout << "After Extraction: ";
    h.display();

    return 0;
}


//max heap

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Extract Maximum
    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Get Max
    int getMax() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    // Increase Key
    void increaseKey(int i, int newVal) {
        if (i >= heap.size()) return;
        heap[i] = newVal;
        heapifyUp(i);
    }

    // Decrease Key
    void decreaseKey(int i, int newVal) {
        if (i >= heap.size()) return;
        heap[i] = newVal;
        heapifyDown(i);
    }

    // Search
    int search(int key) {
        for (int i = 0; i < heap.size(); i++)
            if (heap[i] == key)
                return i;
        return -1;
    }

    // Display
    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

    // Size
    int size() {
        return heap.size();
    }

    // Empty Check
    bool isEmpty() {
        return heap.empty();
    }
};

// ==================== TEST MAX HEAP ====================
int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(50);
    h.insert(20);
    h.insert(40);

    cout << "Max Heap: ";
    h.display();

    cout << "Extract Max: " << h.extractMax() << endl;

    cout << "After Extraction: ";
    h.display();

    return 0;
}



//doubly linked list

#include <iostream>
using namespace std;

// ==================== NODE STRUCTURE ====================
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// ==================== DOUBLY LINKED LIST CLASS ====================
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // ================= INSERT AT BEGINNING =================
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }

        head = newNode;
    }

    // ================= INSERT AT END =================
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // ================= INSERT AT POSITION =================
    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // ================= DELETE FROM BEGINNING =================
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // ================= DELETE FROM END =================
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    // ================= DELETE BY VALUE =================
    void deleteByValue(int key) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value Not Found\n";
            return;
        }

        if (temp == head) {
            deleteFromBeginning();
            return;
        }

        if (temp->next == NULL) {
            deleteFromEnd();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // ================= SEARCH =================
    void search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Value Found at Position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value Not Found\n";
    }

    // ================= COUNT NODES =================
    int countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // ================= DISPLAY FORWARD =================
    void displayForward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        cout << "Forward: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // ================= DISPLAY BACKWARD =================
    void displayBackward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Backward: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    // ================= REVERSE LIST =================
    void reverseList() {
        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL)
            head = temp->prev;
    }

    // ================= UPDATE VALUE =================
    void updateValue(int oldVal, int newVal) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                cout << "Value Updated Successfully\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Value Not Found\n";
    }
};

// ==================== MAIN FUNCTION (MENU DRIVEN) ====================
int main() {
    DoublyLinkedList list;
    int choice, val, pos;

    while (true) {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Value\n";
        cout << "7. Search\n";
        cout << "8. Display Forward\n";
        cout << "9. Display Backward\n";
        cout << "10. Count Nodes\n";
        cout << "11. Reverse List\n";
        cout << "12. Update Value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            list.insertAtPosition(val, pos);
            break;

        case 4:
            list.deleteFromBeginning();
            break;

        case 5:
            list.deleteFromEnd();
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteByValue(val);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;

        case 8:
            list.displayForward();
            break;

        case 9:
            list.displayBackward();
            break;

        case 10:
            cout << "Total Nodes: " << list.countNodes() << endl;
            break;

        case 11:
            list.reverseList();
            cout << "List Reversed\n";
            break;

        case 12:
            int oldVal, newVal;
            cout << "Enter old value and new value: ";
            cin >> oldVal >> newVal;
            list.updateValue(oldVal, newVal);
            break;

        case 0:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}


//splay tree

#include <iostream>
using namespace std;

// ======================= NODE CLASS =======================
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = NULL;
    }
};

// ======================= SPLAY TREE CLASS =======================
class SplayTree {
private:
    Node* root;

    // ---------- RIGHT ROTATION ----------
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    // ---------- LEFT ROTATION ----------
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // ---------- SPLAY OPERATION ----------
    Node* splay(Node* root, int key) {
        if (root == NULL || root->key == key)
            return root;

        // -------- KEY IN LEFT SUBTREE --------
        if (key < root->key) {
            if (root->left == NULL)
                return root;

            // Zig-Zig (Left Left)
            if (key < root->left->key) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            // Zig-Zag (Left Right)
            else if (key > root->left->key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right != NULL)
                    root->left = leftRotate(root->left);
            }

            return (root->left == NULL) ? root : rightRotate(root);
        }

        // -------- KEY IN RIGHT SUBTREE --------
        else {
            if (root->right == NULL)
                return root;

            // Zag-Zig (Right Left)
            if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left != NULL)
                    root->right = rightRotate(root->right);
            }
            // Zag-Zag (Right Right)
            else if (key > root->right->key) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }

            return (root->right == NULL) ? root : leftRotate(root);
        }
    }

    // ---------- INORDER ----------
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // ---------- PREORDER ----------
    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // ---------- POSTORDER ----------
    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

    // ---------- TREE STRUCTURE DISPLAY ----------
    void displayTree(Node* root, int space) {
        if (root == NULL)
            return;

        space += 5;

        displayTree(root->right, space);

        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << root->key << "\n";

        displayTree(root->left, space);
    }

public:
    SplayTree() {
        root = NULL;
    }

    // ---------- INSERT ----------
    void insert(int key) {
        if (root == NULL) {
            root = new Node(key);
            return;
        }

        root = splay(root, key);

        if (root->key == key)
            return;

        Node* newNode = new Node(key);

        if (key < root->key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = NULL;
        }
        else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = NULL;
        }

        root = newNode;
    }

    // ---------- SEARCH ----------
    void search(int key) {
        root = splay(root, key);

        if (root != NULL && root->key == key)
            cout << "Key Found and Splayed to Root\n";
        else
            cout << "Key Not Found\n";
    }

    // ---------- DELETE ----------
    void deleteKey(int key) {
        if (root == NULL)
            return;

        root = splay(root, key);

        if (root->key != key)
            return;

        Node* temp;
        if (root->left == NULL) {
            temp = root;
            root = root->right;
        }
        else {
            temp = root;
            root = splay(root->left, key);
            root->right = temp->right;
        }

        delete temp;
    }

    // ---------- DISPLAY TRAVERSALS ----------
    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    // ---------- TREE DISPLAY ----------
    void displayTree() {
        cout << "\nSplay Tree Structure:\n";
        displayTree(root, 0);
    }
};

// ======================= MAIN MENU =======================
int main() {
    SplayTree tree;
    int choice, key;

    while (true) {
        cout << "\n====== SPLAY TREE MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display Inorder\n";
        cout << "5. Display Preorder\n";
        cout << "6. Display Postorder\n";
        cout << "7. Display Tree Structure\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Key: ";
            cin >> key;
            tree.insert(key);
            break;

        case 2:
            cout << "Enter Key: ";
            cin >> key;
            tree.search(key);
            break;

        case 3:
            cout << "Enter Key: ";
            cin >> key;
            tree.deleteKey(key);
            break;

        case 4:
            tree.displayInorder();
            break;

        case 5:
            tree.displayPreorder();
            break;

        case 6:
            tree.displayPostorder();
            break;

        case 7:
            tree.displayTree();
            break;

        case 0:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}


// leftiest heap

#include <iostream>
using namespace std;

// ====================== NODE CLASS ======================
class Node {
public:
    int key;
    int npl;        // Null Path Length
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        npl = 0;
        left = right = NULL;
    }
};

// ====================== LEFTIST HEAP CLASS ======================
class LeftistHeap {
private:
    Node* root;

    // ---------- MERGE HEAPS ----------
    Node* merge(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        if (h1->key > h2->key)
            swap(h1, h2);

        h1->right = merge(h1->right, h2);

        int leftNPL = (h1->left) ? h1->left->npl : -1;
        int rightNPL = (h1->right) ? h1->right->npl : -1;

        if (leftNPL < rightNPL)
            swap(h1->left, h1->right);

        h1->npl = (h1->right == NULL) ? 0 : h1->right->npl + 1;

        return h1;
    }

    // ---------- INORDER DISPLAY ----------
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // ---------- TREE STRUCTURE DISPLAY ----------
    void displayTree(Node* root, int space) {
        if (!root) return;

        space += 6;
        displayTree(root->right, space);

        cout << endl;
        for (int i = 6; i < space; i++) cout << " ";
        cout << root->key << "(" << root->npl << ")\n";

        displayTree(root->left, space);
    }

    // ---------- SEARCH ----------
    Node* search(Node* root, int key) {
        if (!root) return NULL;
        if (root->key == key) return root;

        Node* found = search(root->left, key);
        if (found) return found;

        return search(root->right, key);
    }

    // ---------- DELETE SPECIFIC NODE ----------
    Node* deleteNode(Node* root, int key) {
        if (!root) return NULL;

        if (root->key == key) {
            Node* merged = merge(root->left, root->right);
            delete root;
            return merged;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

    // ---------- COUNT NODES ----------
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

public:
    LeftistHeap() {
        root = NULL;
    }

    // ---------- INSERT ----------
    void insert(int key) {
        Node* newNode = new Node(key);
        root = merge(root, newNode);
    }

    // ---------- MERGE WITH ANOTHER HEAP ----------
    void mergeWith(LeftistHeap& other) {
        root = merge(root, other.root);
        other.root = NULL;
    }

    // ---------- DELETE MIN ----------
    void deleteMin() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }

        Node* temp = root;
        cout << "Deleted Min: " << temp->key << endl;
        root = merge(root->left, root->right);
        delete temp;
    }

    // ---------- DELETE SPECIFIC KEY ----------
    void deleteKey(int key) {
        root = deleteNode(root, key);
        cout << "Key Deleted (if existed)\n";
    }

    // ---------- DECREASE KEY ----------
    void decreaseKey(int oldKey, int newKey) {
        if (newKey > oldKey) {
            cout << "New Key Must Be Smaller!\n";
            return;
        }

        Node* found = search(root, oldKey);
        if (!found) {
            cout << "Key Not Found\n";
            return;
        }

        root = deleteNode(root, oldKey);
        insert(newKey);
        cout << "Key Decreased Successfully\n";
    }

    // ---------- INCREASE KEY ----------
    void increaseKey(int oldKey, int newKey) {
        if (newKey < oldKey) {
            cout << "New Key Must Be Larger!\n";
            return;
        }

        Node* found = search(root, oldKey);
        if (!found) {
            cout << "Key Not Found\n";
            return;
        }

        root = deleteNode(root, oldKey);
        insert(newKey);
        cout << "Key Increased Successfully\n";
    }

    // ---------- SEARCH ----------
    void searchKey(int key) {
        Node* found = search(root, key);
        if (found)
            cout << "Key Found\n";
        else
            cout << "Key Not Found\n";
    }

    // ---------- DISPLAY INORDER ----------
    void displayInorder() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    // ---------- DISPLAY TREE STRUCTURE ----------
    void displayTree() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }
        cout << "\nLeftist Heap Tree Structure:\n";
        displayTree(root, 0);
    }

    // ---------- SIZE ----------
    void size() {
        cout << "Total Nodes: " << count(root) << endl;
    }

    // ---------- IS EMPTY ----------
    void isEmpty() {
        if (!root) cout << "Heap is Empty\n";
        else cout << "Heap is NOT Empty\n";
    }
};

// ====================== MAIN MENU ======================
int main() {
    LeftistHeap heap1, heap2;
    int choice, key, newKey;

    while (true) {
        cout << "\n====== LEFTIST TREE MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Delete Min\n";
        cout << "3. Delete Specific Key\n";
        cout << "4. Decrease Key\n";
        cout << "5. Increase Key\n";
        cout << "6. Search\n";
        cout << "7. Display Inorder\n";
        cout << "8. Display Tree Structure\n";
        cout << "9. Size\n";
        cout << "10. Is Empty\n";
        cout << "11. Merge with Another Heap\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Key: ";
            cin >> key;
            heap1.insert(key);
            break;

        case 2:
            heap1.deleteMin();
            break;

        case 3:
            cout << "Enter Key: ";
            cin >> key;
            heap1.deleteKey(key);
            break;

        case 4:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.decreaseKey(key, newKey);
            break;

        case 5:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.increaseKey(key, newKey);
            break;

        case 6:
            cout << "Enter Key: ";
            cin >> key;
            heap1.searchKey(key);
            break;

        case 7:
            heap1.displayInorder();
            break;

        case 8:
            heap1.displayTree();
            break;

        case 9:
            heap1.size();
            break;

        case 10:
            heap1.isEmpty();
            break;

        case 11:
            cout << "Enter 3 values into Heap-2:\n";
            for (int i = 0; i < 3; i++) {
                cin >> key;
                heap2.insert(key);
            }
            heap1.mergeWith(heap2);
            cout << "Heaps Merged Successfully\n";
            break;

        case 0:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}



//skew 

#include <iostream>
using namespace std;

// ====================== NODE CLASS ======================
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = NULL;
    }
};

// ====================== SKEW HEAP CLASS ======================
class SkewHeap {
private:
    Node* root;

    // ---------- MERGE ----------
    Node* merge(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        if (h1->key > h2->key)
            swap(h1, h2);

        // Merge on right subtree
        h1->right = merge(h1->right, h2);

        // ALWAYS swap children (key rule of skew heap)
        swap(h1->left, h1->right);

        return h1;
    }

    // ---------- SEARCH ----------
    Node* search(Node* root, int key) {
        if (!root) return NULL;
        if (root->key == key) return root;

        Node* found = search(root->left, key);
        if (found) return found;

        return search(root->right, key);
    }

    // ---------- DELETE SPECIFIC NODE ----------
    Node* deleteNode(Node* root, int key) {
        if (!root) return NULL;

        if (root->key == key) {
            Node* merged = merge(root->left, root->right);
            delete root;
            return merged;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

    // ---------- INORDER ----------
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // ---------- TREE DISPLAY ----------
    void displayTree(Node* root, int space) {
        if (!root) return;

        space += 6;
        displayTree(root->right, space);

        cout << endl;
        for (int i = 6; i < space; i++) cout << " ";
        cout << root->key << "\n";

        displayTree(root->left, space);
    }

    // ---------- COUNT ----------
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

public:
    SkewHeap() {
        root = NULL;
    }

    // ---------- INSERT ----------
    void insert(int key) {
        Node* newNode = new Node(key);
        root = merge(root, newNode);
    }

    // ---------- MERGE WITH ANOTHER HEAP ----------
    void mergeWith(SkewHeap& other) {
        root = merge(root, other.root);
        other.root = NULL;
    }

    // ---------- DELETE MIN ----------
    void deleteMin() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }

        Node* temp = root;
        cout << "Deleted Min: " << temp->key << endl;
        root = merge(root->left, root->right);
        delete temp;
    }

    // ---------- DELETE SPECIFIC KEY ----------
    void deleteKey(int key) {
        root = deleteNode(root, key);
        cout << "Key Deleted (if existed)\n";
    }

    // ---------- DECREASE KEY ----------
    void decreaseKey(int oldKey, int newKey) {
        if (newKey > oldKey) {
            cout << "New Key Must Be Smaller!\n";
            return;
        }

        if (!search(root, oldKey)) {
            cout << "Key Not Found\n";
            return;
        }

        root = deleteNode(root, oldKey);
        insert(newKey);
        cout << "Key Decreased Successfully\n";
    }

    // ---------- INCREASE KEY ----------
    void increaseKey(int oldKey, int newKey) {
        if (newKey < oldKey) {
            cout << "New Key Must Be Larger!\n";
            return;
        }

        if (!search(root, oldKey)) {
            cout << "Key Not Found\n";
            return;
        }

        root = deleteNode(root, oldKey);
        insert(newKey);
        cout << "Key Increased Successfully\n";
    }

    // ---------- SEARCH ----------
    void searchKey(int key) {
        if (search(root, key))
            cout << "Key Found\n";
        else
            cout << "Key Not Found\n";
    }

    // ---------- DISPLAY INORDER ----------
    void displayInorder() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }

        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    // ---------- DISPLAY TREE ----------
    void displayTree() {
        if (!root) {
            cout << "Heap is Empty\n";
            return;
        }

        cout << "\nSkew Heap Tree Structure:\n";
        displayTree(root, 0);
    }

    // ---------- SIZE ----------
    void size() {
        cout << "Total Nodes: " << count(root) << endl;
    }

    // ---------- IS EMPTY ----------
    void isEmpty() {
        if (!root) cout << "Heap is Empty\n";
        else cout << "Heap is NOT Empty\n";
    }
};

// ====================== MAIN MENU ======================
int main() {
    SkewHeap heap1, heap2;
    int choice, key, newKey;

    while (true) {
        cout << "\n====== SKEW HEAP MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Delete Min\n";
        cout << "3. Delete Specific Key\n";
        cout << "4. Decrease Key\n";
        cout << "5. Increase Key\n";
        cout << "6. Search\n";
        cout << "7. Display Inorder\n";
        cout << "8. Display Tree Structure\n";
        cout << "9. Size\n";
        cout << "10. Is Empty\n";
        cout << "11. Merge with Another Heap\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Key: ";
            cin >> key;
            heap1.insert(key);
            break;

        case 2:
            heap1.deleteMin();
            break;

        case 3:
            cout << "Enter Key: ";
            cin >> key;
            heap1.deleteKey(key);
            break;

        case 4:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.decreaseKey(key, newKey);
            break;

        case 5:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.increaseKey(key, newKey);
            break;

        case 6:
            cout << "Enter Key: ";
            cin >> key;
            heap1.searchKey(key);
            break;

        case 7:
            heap1.displayInorder();
            break;

        case 8:
            heap1.displayTree();
            break;

        case 9:
            heap1.size();
            break;

        case 10:
            heap1.isEmpty();
            break;

        case 11:
            cout << "Enter 3 values for Heap-2: ";
            for (int i = 0; i < 3; i++) {
                cin >> key;
                heap2.insert(key);
            }
            heap1.mergeWith(heap2);
            cout << "Heaps Merged Successfully\n";
            break;

        case 0:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}



//binomial

#include <iostream>
#include <climits>
using namespace std;

// ====================== NODE CLASS ======================
class Node {
public:
    int key;
    int degree;
    Node* parent;
    Node* child;
    Node* sibling;

    Node(int val) {
        key = val;
        degree = 0;
        parent = child = sibling = NULL;
    }
};

// ====================== BINOMIAL HEAP CLASS ======================
class BinomialHeap {
private:
    Node* head;

    // ---------- LINK TWO BINOMIAL TREES ----------
    void binomialLink(Node* y, Node* z) {
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree++;
    }

    // ---------- MERGE ROOT LIST ----------
    Node* mergeRootLists(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        Node* head = NULL;
        Node* tail = NULL;

        Node* a = h1;
        Node* b = h2;

        if (a->degree <= b->degree) {
            head = a;
            a = a->sibling;
        } else {
            head = b;
            b = b->sibling;
        }

        tail = head;

        while (a && b) {
            if (a->degree <= b->degree) {
                tail->sibling = a;
                a = a->sibling;
            } else {
                tail->sibling = b;
                b = b->sibling;
            }
            tail = tail->sibling;
        }

        tail->sibling = (a) ? a : b;
        return head;
    }

    // ---------- UNION BINOMIAL HEAPS ----------
    Node* unionHeaps(Node* h1, Node* h2) {
        Node* newHead = mergeRootLists(h1, h2);
        if (!newHead) return NULL;

        Node* prev = NULL;
        Node* curr = newHead;
        Node* next = curr->sibling;

        while (next != NULL) {
            if ((curr->degree != next->degree) ||
                (next->sibling != NULL && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            }
            else {
                if (curr->key <= next->key) {
                    curr->sibling = next->sibling;
                    binomialLink(next, curr);
                }
                else {
                    if (prev == NULL)
                        newHead = next;
                    else
                        prev->sibling = next;
                    binomialLink(curr, next);
                    curr = next;
                }
            }
            next = curr->sibling;
        }
        return newHead;
    }

    // ---------- SEARCH ----------
    Node* search(Node* root, int key) {
        if (!root) return NULL;
        if (root->key == key) return root;

        Node* res = search(root->child, key);
        if (res) return res;

        return search(root->sibling, key);
    }

    // ---------- REVERSE ROOT LIST ----------
    Node* reverseList(Node* node) {
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;

        while (curr) {
            curr->parent = NULL;
            next = curr->sibling;
            curr->sibling = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // ---------- DISPLAY TREE ----------
    void displayTree(Node* root, int level) {
        while (root) {
            for (int i = 0; i < level; i++) cout << "  ";
            cout << root->key << endl;
            if (root->child)
                displayTree(root->child, level + 1);
            root = root->sibling;
        }
    }

    // ---------- COUNT ----------
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->child) + count(root->sibling);
    }

public:
    BinomialHeap() {
        head = NULL;
    }

    // ---------- INSERT ----------
    void insert(int key) {
        Node* temp = new Node(key);
        head = unionHeaps(head, temp);
    }

    // ---------- MERGE ----------
    void mergeWith(BinomialHeap& other) {
        head = unionHeaps(head, other.head);
        other.head = NULL;
    }

    // ---------- GET MIN ----------
    int getMin() {
        if (!head) {
            cout << "Heap is Empty\n";
            return -1;
        }

        int minVal = INT_MAX;
        Node* temp = head;

        while (temp) {
            if (temp->key < minVal)
                minVal = temp->key;
            temp = temp->sibling;
        }
        return minVal;
    }

    // ---------- DELETE MIN ----------
    void deleteMin() {
        if (!head) {
            cout << "Heap is Empty\n";
            return;
        }

        Node* prevMin = NULL;
        Node* minNode = head;
        Node* prev = NULL;
        Node* curr = head;

        int minVal = curr->key;

        while (curr) {
            if (curr->key < minVal) {
                minVal = curr->key;
                prevMin = prev;
                minNode = curr;
            }
            prev = curr;
            curr = curr->sibling;
        }

        // Remove minNode from root list
        if (prevMin)
            prevMin->sibling = minNode->sibling;
        else
            head = minNode->sibling;

        // Reverse minNode's children
        Node* childHeap = reverseList(minNode->child);

        // Merge with main heap
        head = unionHeaps(head, childHeap);

        cout << "Deleted Min: " << minNode->key << endl;
        delete minNode;
    }

    // ---------- DECREASE KEY ----------
    void decreaseKey(int oldKey, int newKey) {
        Node* node = search(head, oldKey);
        if (!node || newKey > oldKey) {
            cout << "Invalid Operation\n";
            return;
        }

        node->key = newKey;
        Node* parent = node->parent;

        while (parent && node->key < parent->key) {
            swap(node->key, parent->key);
            node = parent;
            parent = parent->parent;
        }

        cout << "Key Decreased Successfully\n";
    }

    // ---------- INCREASE KEY ----------
    void increaseKey(int oldKey, int newKey) {
        Node* node = search(head, oldKey);
        if (!node || newKey < oldKey) {
            cout << "Invalid Operation\n";
            return;
        }

        deleteKey(oldKey);
        insert(newKey);
        cout << "Key Increased Successfully\n";
    }

    // ---------- DELETE SPECIFIC KEY ----------
    void deleteKey(int key) {
        decreaseKey(key, INT_MIN);
        deleteMin();
    }

    // ---------- SEARCH ----------
    void searchKey(int key) {
        if (search(head, key))
            cout << "Key Found\n";
        else
            cout << "Key Not Found\n";
    }

    // ---------- DISPLAY ----------
    void display() {
        if (!head) {
            cout << "Heap is Empty\n";
            return;
        }

        cout << "\n===== BINOMIAL HEAP STRUCTURE =====\n";
        displayTree(head, 0);
    }

    // ---------- SIZE ----------
    void size() {
        cout << "Total Nodes: " << count(head) << endl;
    }

    // ---------- IS EMPTY ----------
    void isEmpty() {
        if (!head) cout << "Heap is Empty\n";
        else cout << "Heap is NOT Empty\n";
    }
};

// ====================== MAIN MENU ======================
int main() {
    BinomialHeap heap1, heap2;
    int choice, key, newKey;

    while (true) {
        cout << "\n====== BINOMIAL HEAP MENU ======\n";
        cout << "1. Insert\n";
        cout << "2. Get Min\n";
        cout << "3. Delete Min\n";
        cout << "4. Delete Specific Key\n";
        cout << "5. Decrease Key\n";
        cout << "6. Increase Key\n";
        cout << "7. Search\n";
        cout << "8. Display Heap (Tree Structure)\n";
        cout << "9. Size\n";
        cout << "10. Is Empty\n";
        cout << "11. Merge with Another Heap\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Key: ";
            cin >> key;
            heap1.insert(key);
            break;

        case 2:
            cout << "Min Value: " << heap1.getMin() << endl;
            break;

        case 3:
            heap1.deleteMin();
            break;

        case 4:
            cout << "Enter Key: ";
            cin >> key;
            heap1.deleteKey(key);
            break;

        case 5:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.decreaseKey(key, newKey);
            break;

        case 6:
            cout << "Enter Old Key: ";
            cin >> key;
            cout << "Enter New Key: ";
            cin >> newKey;
            heap1.increaseKey(key, newKey);
            break;

        case 7:
            cout << "Enter Key: ";
            cin >> key;
            heap1.searchKey(key);
            break;

        case 8:
            heap1.display();
            break;

        case 9:
            heap1.size();
            break;

        case 10:
            heap1.isEmpty();
            break;

        case 11:
            cout << "Enter 3 values for Heap-2:\n";
            for (int i = 0; i < 3; i++) {
                cin >> key;
                heap2.insert(key);
            }
            heap1.mergeWith(heap2);
            cout << "Heaps Merged Successfully\n";
            break;

        case 0:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}
