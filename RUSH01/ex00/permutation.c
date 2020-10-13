public void perm(int[] arr, int depth, int n, int k)
    { 
        if (depth == k) // 한번 depth 가 k로 도달하면 사이클이 돌았음. 출력함. 
        {
            print(arr); 
            return; 
        } 
        for (int i = depth; i < n; i++)
        { 
            swap(arr, i, depth); 
            perm(arr, depth + 1, n, k); 
            swap(arr, i, depth);
        }
    }

