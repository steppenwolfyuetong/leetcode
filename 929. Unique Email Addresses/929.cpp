class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> cache;
        for( const auto& email: emails ){
            auto index = email.find_first_of('@'); 
            auto name = email.substr(0, index), domain = email.substr(index);
            name.erase(remove_if(name.begin(), name.end(), []( const auto& c ){ return c == '.'; }), name.end());
            cache.insert(name.erase(name.find_first_of('+')) + domain);
        }
        
        return static_cast<int>(cache.size());
    }
};
