class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int sb = 0;

    while (m != n) {
      m >>= 1;
      n >>= 1;
      ++sb;
    }
    return m << sb;
  }
};
