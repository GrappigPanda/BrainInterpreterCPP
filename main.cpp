#include "brainfsck/brainfsck.cpp"

int main() {
    BrainFsck bf1("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");

    bf1.parseKeywords();

    return 0;
}