class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        for(int i = 0; i <= 15; i++){
            int temp = b[i];
            b[i] = b[31 - i];
            b[31 - i] = temp;
        }
        
        return b.to_ulong();
    }
};