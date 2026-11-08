class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordListSet;
        wordListSet.reserve(wordList.size() + 1);

        for(const auto& str : wordList){
            wordListSet.insert(str);
        }
        if(!wordListSet.contains(endWord)) return 0;

        
        std::vector<std::string> bfsVector;
        bfsVector.reserve(wordList.size() + 1);
        bfsVector.push_back(beginWord);
        wordListSet.erase(beginWord);

        int level = 1;
        std::size_t read = 0;
        while(read < bfsVector.size()){
            std::size_t levelEnd = bfsVector.size();
            while(read < levelEnd){
                auto originalStr = bfsVector[read];
                read++;

                for(size_t i = 0; i < originalStr.size(); i++){
                    char originalChar = originalStr[i];
                    for(char j = 'a'; j <= 'z'; j++){
                        if(originalChar != j){
                            originalStr[i] = j;
                            if(wordListSet.erase(originalStr)){
                                if(originalStr == endWord) return (level + 1);
                                bfsVector.push_back(originalStr);
                            }
                        }
                    }
                    originalStr[i] = originalChar;
                }
            }
            level++;
        }
        return 0;
    }
};
