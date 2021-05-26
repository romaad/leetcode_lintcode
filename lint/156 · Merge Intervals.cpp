/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
    int comp (Interval & a, Interval & b) {
        return a.start < b.start;
    }
class Solution {
private:

public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(!intervals.size()) {
             return vector<Interval>(0);
        }

        sort(intervals.begin(), intervals.end(), comp);

        int curL = intervals[0].start, curR = intervals[0].end, id = 1;
        vector<Interval> res;
        while(id < intervals.size()) {
            Interval itv = intervals[id++];
            if(itv.start > curR) {
                res.push_back(Interval(curL, curR));
                curL = itv.start; curR = itv.end;
            } else {
                curR = max(curR, itv.end);
            }
        }
        res.push_back(Interval(curL, curR));
        return res;
    }
};
