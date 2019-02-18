/*
If count has already the key, it won't change anything.
upper_bound and lower_bound both work.

emplace returns a pair of an iterator to the newly inserted element and a value of true.
Otherwise, it returns an iterator to the equivalent element within the container and a value of false.
*/
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }

    // 看不懂...
    int book(int s, int e) {
        // ?: --count.lower_bound(s)->second
        auto start = count.emplace(s, (--count.lower_bound(s))->second).first;
        // ?: --count.lower_bound(e)->second 
        auto end = count.emplace(e, (--count.lower_bound(e))->second).first;

        // [start, end) is the iterator which this book will affect
        for (auto i = start; i != end; ++i) {
            res = max(res, ++(i->second));
        }
        return res;
    }
    
    map<int, int> count = {{-1,0}};
    int res = 0;
};

