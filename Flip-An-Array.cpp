#include <deque>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v {7,6,4,2,8,0};
deque<int>queue(v.begin(), v.end());
for (int a : queue) {
    cout << a << " ";
}
while (queue.front() != 0) {
    queue.push_back(queue.front()); // значения из начала заносим в конец
    queue.pop_front(); // удалем из начала
}
cout << endl;
for (int a : queue) {
    cout << a << " ";
}