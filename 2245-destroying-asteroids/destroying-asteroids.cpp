class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long ans = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int aster: asteroids) {
            if(ans < aster) {
                return false;
            }
            ans += aster;
        }
        return true;
    }
};