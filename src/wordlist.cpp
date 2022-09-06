#include <pswdsec/wordlist.hpp>
#include <fstream>

pswdsec::Wordlist::Wordlist(){
    std::ifstream in;
    in.open(WORDLIST);
    this->load(in);
}

void pswdsec::Wordlist::load(std::istream& stream) {
    std::string current;
    while (getline(stream, current)) {
        this->pswds.push_back(current);
    }
    this->pswds.shrink_to_fit();
}
bool pswdsec::Wordlist::contains(const std::string& pswd) {
    for (auto const& element : this->pswds) {
        if (element == pswd) {
            return true;
        }
    }
    return false;
}