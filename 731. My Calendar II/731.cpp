// Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.
//
// Each time of book, instead of fail a book when there is 1 or more overlap with existing books as in MyCalendar I, 
// we just want to make sure these overlaps does not overlap - having overlap is now ok, 
// but overlapped period cannot be overlapped again.

class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end)
    {
        for (const auto i : overlap) {
            if (start < i.second && end > i.first) {                // new book overlaps with existing overlapped period 
                return false;
            }
        }
        for (const auto i : bookings) {
            if (start < i.second && end > i.first) {                // overlaps with existing book, 
                                                                    // insert overlap into overlapped period
                overlap.push_back({max(start, i.first), min(end, i.second)});
            }
        }
        bookings.push_back({start, end});
        return true;
    }

private:
    vector<pair<int,int>> overlap;
    vector<pair<int,int>> bookings;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */


