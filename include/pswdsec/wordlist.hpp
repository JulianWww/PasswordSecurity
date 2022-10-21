#pragma once
#include <iostream>
#include <vector>

namespace pswdsec {
    class Wordlist {
        public: std::vector<std::string> pswds;
        
        public: Wordlist();
        public: void load(std::istream& in);
        public: bool contains(const std::string& pswd) const;
    };
}