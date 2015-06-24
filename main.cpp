#include <iostream>
#include <vector>
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

void parseKeywords(std::vector<int> registers, std::string commands) {
    std::vector<int>::iterator it = std::begin(registers);
    const std::string::iterator end = std::end(commands);

    std::string::iterator loop;

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
                //registers.push_back(0);
                it++;
                break;
            case '<':
                it--;
                break;
            case '[':
                loop = i;
                break;
            case ']':
                if(*it != 0)
                    i = loop;
                break;
            default:
                std::cout << "Invalid keyword" << std::endl;
                break;
        }
    }
    return;
}


int main() {
    std::vector<int> registers = {0,0,0,0};
    std::string bfCommands = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

    parseKeywords(registers, bfCommands);

    return 0;
}