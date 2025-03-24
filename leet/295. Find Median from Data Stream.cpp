#include <vector>
#include <queue>
#include <functional>
inline void println(std::string_view rem, const std::vector<int>& v)
{
    return ;
    std::cout << rem;
    for (int e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}
template <class T, class Compare = std::less<T>>
class Heap {
private:
    Compare c;
    std::vector<T> v;

public:
    void push(const T& val) {
        v.push_back(val);
        std::push_heap(v.begin(), v.end(), c);
        println("after push: ", v);
    }

    T pop() {
        std::pop_heap(v.begin(), v.end(), c);
        T val = v.back();
        v.pop_back();
        println("after pop: ", v);
        return val;
    }

    T top() const {
        return v.front();
    }

    size_t size() const {
        return v.size();
    }
};

class MedianFinder {
private:
    Heap<int, std::less<>> minQ; // max heap for smaller half
    Heap<int, std::greater<>> maxQ; // min heap for larger half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (minQ.size() == 0 || num <= minQ.top()) {
            minQ.push(num);
        } else {
            maxQ.push(num);
        }

        // Balance heaps
        if (minQ.size() > maxQ.size() + 1) {
            maxQ.push(minQ.pop());
        } else if (maxQ.size() > minQ.size()) {
            minQ.push(maxQ.pop());
        }
    }

    double findMedian() {
        if ((minQ.size() + maxQ.size()) % 2 == 0) {
            return (static_cast<double>(minQ.top()) + maxQ.top()) / 2.0;
        } else {
            return static_cast<double>(minQ.top());
        }
    }
};
