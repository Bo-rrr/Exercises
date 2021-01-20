class Solution
{
public:
        map<char,int> mp;
        queue<char> p;
  //Insert one char from stringstream
    void Insert(char ch)
    {
        map<char,int>::iterator iter=mp.find(ch);
        if(iter==mp.end())
        {
            p.push(ch);
        }
        ++mp[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!p.empty())
        {
            char ch;
            ch=p.front();
            if(mp[ch]==1)
            {
                return ch;
            }
            else
            {
                p.pop();
            }
        }
        return '#';
    }

};