struct Workshop
{
    int start, duration, end;
};

struct Available_Workshops
{
    vector<Workshop> workshops;
};

int comp(const void * left, const void * right)
{
    return ((Workshop*)left)->end - ((Workshop*)right)->end;
}

Available_Workshops * initialize(int start_time[], int duration[], int n)
{
    Available_Workshops * aw = new Available_Workshops;
    aw->workshops = vector<Workshop>(n);
    for (int i = 0; i < n; i++)
    {
        aw->workshops[i].start = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end = start_time[i] + duration[i];
    }
    
    qsort(&(aw->workshops[0]), n, sizeof(Workshop), comp);
    
    return aw;
}    

int CalculateMaxWorkshops(Available_Workshops * aw)
{
    size_t n = aw->workshops.size();
    int cnt = 1;
    int curr_end = aw->workshops[0].end;
    for (int i = 1; i < n; i++)
    {
        if (aw->workshops[i].end - aw->workshops[i].duration >= curr_end)
        {
            cnt++;
            curr_end = aw->workshops[i].end;
        }
            
    }    
        return cnt;
}

