#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct to store fish and their respective price
struct Fish {
    string name;
    int price;

    // Constructor for convenience
    Fish(string n, int p) : name(n), price(p) {}
};

// Comparator to sort by price (ascending order)
struct ComparePrice {
    bool operator()(const Fish& f1, const Fish& f2) {
        return f1.price > f2.price; // Min-heap: lowest price first
    }
};

int calculatePrice(const string& name) {
    int sum = 0;
    for (char c : name) {
        sum += (int)c; // Add ASCII values of all characters
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of fish: ";
    cin >> n;

    priority_queue<Fish, vector<Fish>, ComparePrice> pq;
    vector<Fish> fishes;

    cout << "Enter the fish names:\n";
    for (int i = 0; i < n; ++i) {
        string fishName;
        cin >> fishName;

        int price = calculatePrice(fishName);
        Fish fish(fishName, price);
        pq.push(fish);          // Add to priority queue
        fishes.push_back(fish); // Store in vector for additional processing
    }

    // Display sorted order (ascending by price)
    cout << "\nFish names sorted by price (ASCII sum):\n";
    while (!pq.empty()) {
        Fish f = pq.top();
        pq.pop();
        cout << f.name << " -> Price: " << f.price << "\n";
    }

    // Find fish with the highest price
    auto maxFish = max_element(fishes.begin(), fishes.end(), [](const Fish& f1, const Fish& f2) {
        return f1.price < f2.price;
    });

    cout << "\nFish with the highest price:\n";
    cout << maxFish->name << " -> Price: " << maxFish->price << "\n";

    return 0;
}

