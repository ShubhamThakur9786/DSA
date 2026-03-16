class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> st;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                st.insert(grid[i][j]); // size 0 rhombus
                
                for(int k=1;;k++){
                    
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n)
                        break;
                    
                    int sum = 0;
                    
                    int x = i-k, y = j;
                    
                    // top -> right
                    for(int t=0;t<k;t++){
                        sum += grid[x+t][y+t];
                    }
                    
                    // right -> bottom
                    for(int t=0;t<k;t++){
                        sum += grid[x+k+t][y+k-t];
                    }
                    
                    // bottom -> left
                    for(int t=0;t<k;t++){
                        sum += grid[x+2*k-t][y-t];
                    }
                    
                    // left -> top
                    for(int t=0;t<k;t++){
                        sum += grid[x+k-t][y-k+t];
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        for(auto it : st){
            ans.push_back(it);
            if(ans.size()==3) break;
        }
        
        return ans;
    }
};