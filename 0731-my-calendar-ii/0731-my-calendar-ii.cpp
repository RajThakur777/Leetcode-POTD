class MyCalendarTwo {
public:
    map<int , int> mpp;

    MyCalendarTwo() { 
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;

        int sum = 0;
        for(auto& [first , second] : mpp){
            sum += second;

            if(sum > 2){
                mpp[startTime]--;
                mpp[endTime]++;

                return false;
            }
        }        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */