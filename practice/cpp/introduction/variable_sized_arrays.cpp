    int n, q;
    cin >> n >> q;
    
    int k[100001] = {0};
    int a[300001] = {0};
    int kpos = 1;
    int apos = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> k[kpos++];
        for (int j = 0; j < k[kpos - 1]; j++)
        {
            cin >> a[apos++];
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        k[i] += k[i - 1];
    }
    int kidx, aidx;
    for (int i = 0; i < q; i++)
    {
        cin >> kidx >> aidx;
        cout << a[k[kidx] + aidx] << endl;;
    }
    
	return 0;
}

