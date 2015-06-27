#include <iostream>
#include <list>
#include <algorithm>

class BrainFuck {
public:
    void parseKeywords();
    BrainFuck(std::string);

private:
    std::string bfKeywords;
    std::list<int> registers;
    std::list<int>::iterator it;
    std::list<std::string::iterator> loop;
    std::string::const_iterator end;
};

BrainFuck::BrainFuck(std::string bfCommands) {
    bfKeywords  = bfCommands;
    loop        = {};
    registers   = {0};
    it          = std::begin(registers);
    end         = std::end(bfKeywords);
}


void BrainFuck::parseKeywords() {
    for(std::string::iterator i = std::begin(bfKeywords); i <= end; ++i ) {
        switch(*i) {
            case '+':
                (*it)++;
                break;
            case '-':
                if(*it != 0)
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
    BrainFuck bf1("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    BrainFuck bf2("++++++++[>+>++>+++>++++>+++++>++++++>+++++++>++++++++>+++++++++>++++++++++>+++++++++++>++++++++++++>+++++++++++++>++++++++++++++>+++++++++++++++>++++++++++++++++<<<<<<<<<<<<<<<<-]>>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>+++.---<<<<<<<<<<<<<<>>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<<.");

    bf1.parseKeywords();
    std::cout << std::endl;
    bf2.parseKeywords();

    return 0;
}