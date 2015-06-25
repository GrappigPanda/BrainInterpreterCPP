#include <iostream>
#include <list>
#include <algorithm>

template<class T, class Term>
std::vector<int> findAll(T container, const Term& term) {
    const typename T::iterator begin = std::begin(container);
    const typename T::iterator last = std::end(container);
    typename T::iterator first = std::begin(container);

    std::vector<int> indexes;

    while(first != last) {
        if(*first == term)
            indexes.push_back(first - begin);
        ++first;
    }
    return indexes;
}

template<class T>
typename T::iterator findLastLoop(T bfCommands) {
    typename T::iterator it = bfCommands.begin();

    std::cout << bfCommands.find("[") << std::endl;
    return it;
}

void parseKeywords(std::string commands) {
    std::list<int> registers = {0};
    std::list<int>::iterator it = std::begin(registers);

    const std::string::const_iterator end = std::end(commands);

    std::list<std::string::iterator> loop = {};

    for(std::string::iterator i = std::begin(commands); i <= end; ++i ) {
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