/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;
        unordered_set<char> tchar;
        for (int i = 0; i < t.size(); i++){
            tmap[t[i]]++;
            tchar.insert(t[i]);
        }
        int l = 0, r = 0;
        int ans = INT_MAX;
        int ans_l = 0;
        int ans_r = 0;
        while(l <= r && r < s.size()){
            while(r < s.size() && !comp(smap, tmap, tchar)){
                // cout << "!" << l << " " << r << endl;
                smap[s[r]]++;
                r++;
            }
            while(l <= r && comp(smap, tmap, tchar)){
                // cout << l << " " << r << endl;
                if (r-l < ans){
                    ans = r-l;
                    ans_l = l;
                    ans_r = r;
                }
                smap[s[l]]--;
                l++;
            }
        }
        return s.substr(ans_l, (ans_r-ans_l));
    }
    bool comp(unordered_map<char,int> & smap, unordered_map<char,int> & tmap, unordered_set<char> & t){
        for (auto c : t){
            // cout << t[i] << " " << smap[t[i]] << " " << tmap[t[i]] << endl;
            if (smap[c] < tmap[c]){
            // if (smap[t[i]] < 1){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    cout << Solution{}.minWindow("ADOBECODEBANC", "ABCDEF") << endl;
}