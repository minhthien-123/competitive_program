for (i = 0; i < n - 1; i++){
        //cout << a[i].en << " " << a[i + 1].beg << "\n";
        if (a[i].en > a[i + 1].beg){
            m[a[i].en]++;
            m[a[i + 1].beg]++;
        }else if (a[i].en == a[i + 1].beg){
            m[a[i].en]++;
            if (m[a[i].beg] == 0) m[a[i].beg]++;
            else if (m[a[i + 1].en] == 0) m[a[i + 1].en]++;
            else if (m[a[i].beg] == 0 && m[a[i + 1].en] == 0){
                m[a[i].beg]++;
                m[a[i + 1].en]++;
            }
        }else{
            m[a[i].beg]++;
            m[a[i].en]++;
            m[a[i + 1].beg]++;
            m[a[i + 1].en]++;
        }
    }

    for (i = -1000000; i <= 1000000; i++){
        if (m[i] != 0) d++;
    }
    cout << d << "\n";

    for (i = -1000000; i <= 1000000; i++){
        if (m[i] != 0) cout << i << " ";
    }
