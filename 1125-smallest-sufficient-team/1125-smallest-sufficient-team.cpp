class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
       map<string, int> mp;
        int req_skill = 0;
        for(int i = 0; i < req_skills.size(); i++){
            mp[req_skills[i]] = i;
            req_skill |= (1 << i);
        }

        vector<int> ppl(people.size());
        for(int i = 0; i < people.size(); i++){
            int p_skills = 0;
            for(int j = 0; j < people[i].size(); j++){
                p_skills |= (1 << mp[people[i][j]]);
            }
            ppl[i] = p_skills;
        }

        
        vector<vector<long long>> dp(ppl.size()+1, vector<long long>(req_skill + 1, INT_MAX));
        dp[0][0] = 0;


        for(int i = 1; i <= ppl.size(); i++){
            // if we dont consider the current person
            dp[i] = dp[i-1];

            if(ppl[i-1] == 0) continue;

            // if we consider the current person
            for(int j = req_skill; j >= 0 ; j--){
                int cur_person_req_skills = (ppl[i-1]&j);
                int req_skills_cur_person_dnh = (j^cur_person_req_skills);

                // cout << dp[i][j] << "\n";
                dp[i][j] = min(dp[i][j], dp[i-1][req_skills_cur_person_dnh] + 1ll);
                
            }
        }

        vector<int> ans;
        int skill = req_skill;
        for(int i = ppl.size(); i >= 1; i--){
            if(dp[i][skill] == dp[i-1][skill]) continue;
            ans.push_back(i-1);
            int cur_person_req_skills = (ppl[i-1]&skill);
            skill = (skill^cur_person_req_skills);
        }

        return ans;
    }
};