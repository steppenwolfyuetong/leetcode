class MyCalendar {
    set<pair<int, int>> books;
public:
    bool book(int s, int e) {
        auto it = books.lower_bound({s, e});
        if (it != books.end() && it->first < e) 
            return false;
        if (it != books.begin() && s < (--it)->second) 
            return false;
        books.insert({ s, e });
        return true;
    }
};
