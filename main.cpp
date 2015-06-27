#include <iostream>
#include <list>
#include <algorithm>

class BrainFsck {
public:
    void parseKeywords();
    BrainFsck(std::string);

private:
    std::string bfKeywords;
    std::list<int> registers;
    std::list<int>::iterator it;
    std::string::const_iterator end;
    std::list<std::string::iterator> loop;
};

BrainFsck::BrainFsck(std::string bfCommands) {
    bfKeywords  = bfCommands;
    loop        = {};
    registers   = {0};
    it          = std::begin(registers);
    end         = std::end(bfKeywords);
}

void BrainFsck::parseKeywords() {
    for(std::string::iterator i = std::begin(bfKeywords); i <= end; ++i ) {
        switch(*i) {
            case '+':
                ++(*it);
                break;
            case '-':
                if(*it != 0)
                    --(*it);
                break;
            case '.':
                if(std::next(i) == end)
                    return;
                std::putchar(*it);
                break;
            case ',':
                std::getchar();
                break;
            case '>':
                registers.push_back(0);
                ++it;
                break;
            case '<':
                if(std::begin(registers) == it)
                    registers.push_front(0);
                --it;
                break;
            case '[':
                loop.push_back(i);
                break;
            case ']': {
                if(*it != 0 && loop.size() != 0) {
                    i = loop.back();
                } else if(*it == 0 && loop.size() > 0) {
                    loop.pop_back();
                } else {
                    std::cout << "Why am I even here?" << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid keyword" << std::endl;
                break;
        }
    }
    return;
}


int main() {
    BrainFsck bf1("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    BrainFsck bf2(">++++++++[<+++++++++>-]<.>>+>+>++>[-]+<[>[->+<<++++>]<<]>.+++++++..+++.>>+++++++.<<<[[-]<[-]>]<+++++++++++++++.>>.+++.------.--------.>>+.>++++.");
    // I just can't get bf2 to work properly. The "W" in world is improperly formatted and I have no clue why.

    bf1.parseKeywords();
    std::cout << std::endl;
    bf2.parseKeywords();

    return 0;
}