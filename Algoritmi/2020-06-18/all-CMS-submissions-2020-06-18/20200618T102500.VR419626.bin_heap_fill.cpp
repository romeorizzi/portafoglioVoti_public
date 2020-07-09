/**
* user:  VR419626
* fname: SOLOMON MARIAN
* lname: CLAUDIU
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 10:25:00.076981
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, t;
vector<int> A, E;

std::string do_padding(unsigned index, unsigned mlength) {
    std::string padding;
    if (int((index - 1) / 2) != 0) {
        return (int((index - 1) / 2) % 2 == 0) ?
               (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
               (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
    }
    return padding;
}


void printer(std::vector<int> const &tree, unsigned index, unsigned mlength) {
    auto last = tree.size() - 1;
    auto left = 2 * index + 1;
    auto right = 2 * index + 2;
    std::cout << " " << tree[index] << " ";
    if (left <= last) {
        auto llength = std::to_string(tree[left]).size();
        std::cout << "---" << std::string(mlength - llength, '-');
        printer(tree, left, mlength);
        if (right <= last) {
            auto rlength = std::to_string(tree[right]).size();
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " └" <<
                      std::string(mlength - rlength, '-');
            printer(tree, right, mlength);
        }
    }
}


void print_tree(std::vector<int> &tree) {
    unsigned mlength = 0;
    for (int &element : tree) {
        auto clength = std::to_string(element).size();
        if (clength > mlength) {
            mlength = std::to_string(element).size();
        }
    }
    std::cout << std::string(mlength - std::to_string(tree[0]).size(), ' ');
    printer(tree, 0, mlength);
}

bool isHeap() {
    for (int i = 0; i <= (N - 2) / 2; i++) {
        //verifico E-buono
        if (E[i] == 1 && A[i] < A[(i - 1) / 2])
            return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int smallest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than largest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    // If largest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}


void buildHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    cin >> N >> t;
    A.resize(N);
    E.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> E[i];
    /*
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(E.begin(), E.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    */

    if (t == 1)
        cout << isHeap() << endl;
    else {
        vector<int> Ap(A);
        buildHeap(Ap.data(), N);
        cout << endl;
        //copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        print_tree(A);
        cout << endl;
        //copy(Ap.begin(), Ap.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        print_tree(Ap);
        cout << endl;
    }
    return 0;
}