#include <iostream>
#include <list>
#include <algorithm>

class BrainFuck {
public:
    void parseKeywords();

private:
    std::string bfCommands;
    std::list<int> registers;
    std::list<int>::iterator it;
    std::list<std::string::iterator> loop = {};
};


void BrainFuck::parseKeywords() {

    const std::string::const_iterator end = std::end(bfCommands);

    for(std::string::iterator i = std::begin(bfCommands); i <= end; ++i ) {
        switch(*i) {
            case '+':
                (*it)++;
                break;
            case '-':
                (*it)--;
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
                it--;
                break;
            case '[':
                loop.push_back(i);
                break;
            case ']': {
                if(*it != 0 && loop.size() != 0) {
                    i = loop.back();
                } else if(*it == 0 && loop.size() > 1) {
                    loop.pop_back();
                    std::cout << ": " << *i << std::endl;
                } else {
                    break;
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
    std::string bfCommands = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    std::string bfCommands2 = "++++++++[>+>++>+++>++++>+++++>++++++>+++++++>++++++++>+++++++++>++++++++++>+++++++++++>++++++++++++>+++++++++++++>++++++++++++++>+++++++++++++++>++++++++++++++++<<<<<<<<<<<<<<<<-]>>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>+++.---<<<<<<<<<<<<<<>>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<<.";

    parseKeywords(bfCommands);
    std::cout << std::endl;
    parseKeywords(bfCommands2);

    return 0;
}