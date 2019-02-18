vector<Interval> insert_range(vector<Interval> intervals_list, Interval insert) 
{
    vector<Interval> result;
    Interval prev;
    for (int i = 0; i < intervals_list.size(); i++)
    {
        prev = intervals_list.at(i);
        if(prev.end < insert.start)
            result.push_back(prev);
        else if(prev.start > insert.end) 
        {
            result.push_back(insert);
            insert = prev;
        }
        else if(prev.start <= insert.end || prev.end >= insert.start)
        {
            int new_start = min(prev.start, insert.start);
            int new_end = max(prev.end, insert.end);
            insert = Interval(new_start, new_end);
        }
    }
    result.push_back(insert);
    return result;
}
