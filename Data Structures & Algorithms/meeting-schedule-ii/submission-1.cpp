/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(const std::vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        std::vector<Interval> intervalCopy(intervals);

        std::sort(intervalCopy.begin(), intervalCopy.end(),
        [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        int conflictCount = 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> meetingEndQueue;
        meetingEndQueue.push(intervalCopy.front().end);

        for(std::size_t i = 1; i < intervalCopy.size(); i++){
            if(intervalCopy[i].start >= meetingEndQueue.top()){
                meetingEndQueue.pop();
            }
            meetingEndQueue.push(intervalCopy[i].end);
        }

        return static_cast<int>(meetingEndQueue.size());
    }
};
