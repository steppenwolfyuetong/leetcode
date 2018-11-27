class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0]))
        {
            int upper = 0, lower = 0;
            for(int i = 1; i < word.size(); i++)
            {
                if(isupper(word[i]))
                    upper++;
                if(islower(word[i]))
                    lower++;
                if(upper > 0 && lower > 0)
                    return false;
            }
        }
        else
        {
            for(int i = 1; i < word.size(); i++)
            {
                if(isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};
