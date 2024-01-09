class Solution {
public:
    int clumsy(int N) {
        int result_map[] = {0, 1, 2, 6, 7, 7, 8, 6, 9};
        
        if (N <= 8)
            return result_map[N];
        else if (N % 4 == 0)
            return N + 1;
        else if (N % 4 == 3)
            return N - 1;
        else
            return N + 2;
    }
};