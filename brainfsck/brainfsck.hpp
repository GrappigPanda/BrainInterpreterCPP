#ifndef BRAINFSCK_HPP
#define BRAINFSCK_HPP

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

#endif