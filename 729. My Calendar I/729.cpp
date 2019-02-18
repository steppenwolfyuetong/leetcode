struct MyInterval {
    int start;
    int end;
    MyInterval() : start(0), end(0) {}
    MyInterval(int s, int e): start(s), end(e) {}
};

// same as 57. Insert Interval?
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        MyInterval wtf(start, end);
        auto it = events_.begin();                  // find the right position to insert
        while (it != events_.end()) {
            if (wtf.end <= it->start) {
                events_.insert(it, wtf);
                return true;
            } else if (wtf.start >= it->end) {
                it++;
            } else {
                return false;
            }
        }
        events_.emplace_back(wtf);
        return true;
    }
private:
    vector<MyInterval> events_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
