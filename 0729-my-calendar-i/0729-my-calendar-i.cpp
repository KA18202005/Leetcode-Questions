class MyCalendar {
    map<int, int> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto next = intervals.lower_bound(startTime);
        if (next != intervals.end() && next->first < endTime) {
            return false;
        }
        if (next != intervals.begin() && prev(next)->second > startTime) {
            return false;
        }
        intervals[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */