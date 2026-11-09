class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::vector<std::string>> adjacencyList;
        for(const auto& ticket : tickets){
            adjacencyList[ticket[0]].push_back(ticket[1]);
        }

        // Sort slices
        for(auto& [_, destinationNodes] : adjacencyList){
            std::sort(destinationNodes.rbegin(), destinationNodes.rend());
        }

        std::vector<std::string> resultVector;
        resultVector.reserve(tickets.size() + 1);
        
        std::stack<std::string> dfsStack;
        std::size_t read = 0;
        dfsStack.push("JFK");

        while(!dfsStack.empty()){
            auto& sourceNode = dfsStack.top();
            auto& destinationNodes = adjacencyList[sourceNode];

            if(destinationNodes.empty()){
                resultVector.push_back(sourceNode);
                dfsStack.pop();
            } else {
                dfsStack.push(std::move(destinationNodes.back()));
                destinationNodes.pop_back();
            }
        }

        std::reverse(resultVector.begin(), resultVector.end());

        return resultVector;
    }
};
