class NestedIterator {
    vector<int> output;  
    int i = 0;           

public:
    void helper(const vector<NestedInteger>& nesList) {
        for (const auto& ni : nesList) {
            if (ni.isInteger()) {
                output.push_back(ni.getInteger());
            } else {
                helper(ni.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        return output[i++];
    }
    
    bool hasNext() {
        return i < output.size();
    }
};

