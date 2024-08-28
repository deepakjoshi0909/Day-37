class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int candidate = 0;
        int n = mat.size();
        
        for(int i=0;i<n;i++){
            if(mat[candidate][i] == 1){
                candidate = i;
            }
        }
        
        for(int i=0;i<n;i++){
            if(i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)){
                return -1;
            }
        }
        
        return candidate;
    }
};
