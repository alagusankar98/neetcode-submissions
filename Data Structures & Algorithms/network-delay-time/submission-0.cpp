class Solution {
public:
    struct EdgeTime{
        int edge;
        int time;
    };
    int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
        std::vector<int> offset(n + 1, 0);

        for(const auto& time : times){
            offset[time[0] - 1]++;
        }

        for(int i = 0; i < n; i++){
            offset[i + 1] += offset[i];
        }

        std::vector<EdgeTime> edges(times.size());
        for(const auto& time : times){
            edges[--offset[time[0] - 1]] = {time[1] - 1, time[2]};
        }

        std::vector<int> distanceVector(n, std::numeric_limits<int>::max());
        distanceVector[k - 1] = 0;

        using DistanceIndexPair = std::pair<int, int>;
        std::vector<DistanceIndexPair> vec;
        vec.reserve(times.size() + 1);
        std::priority_queue<DistanceIndexPair, std::vector<DistanceIndexPair>, std::greater<DistanceIndexPair>> minQueue(std::greater<DistanceIndexPair>(), std::move(vec));
        minQueue.emplace(0, (k-1));

        int settledNodes = 0;
        int lastSettledTime = 0;
        while(!minQueue.empty() && (settledNodes < n)){
            auto [minDistance, sourceIdx] = minQueue.top(); minQueue.pop();
            if(minDistance > distanceVector[sourceIdx]) continue;

            settledNodes++;
            lastSettledTime = minDistance;
            for(int i = offset[sourceIdx]; i < offset[sourceIdx + 1]; i++){
                auto& [neighborNodeIdx, neighborDistance] = edges[i];
                if((minDistance + neighborDistance) < distanceVector[neighborNodeIdx]){
                    distanceVector[neighborNodeIdx] = (minDistance + neighborDistance);
                    minQueue.emplace(distanceVector[neighborNodeIdx], neighborNodeIdx);
                }
            }
        }

        return (settledNodes == n) ? lastSettledTime : -1;
    }
};
