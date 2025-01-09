class Solution {
public:
    int addWithout(int a, int b)
    {
        if (b == 0) return a;
        int carry = (a & b) << 1;
        return addWithout(a^b, carry);
    }

    int getSum(int a, int b) {
        return addWithout(a, b);
    }
};