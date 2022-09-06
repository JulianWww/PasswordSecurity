#include <pswdsec/pswdsec.hpp>
#include <pswdsec/charSet.hpp>
#include <math.h>
#include <pswdsec/wordlist.hpp>

bool pswdsec::password::meetsOWASP() {
    Wordlist list;
    return (
        this->meetsCharSets() >= 3
        && this->size() >= 10
        && this->size() <= 128
        && this->getMaxIdenticalCharsInRow() <= 2
        && (!list.contains(*this))
    );
}
bool pswdsec::password::meetsOWASP_ASVS() {
    Wordlist list;
    return (
        this->size() >= 12
        && (!list.contains(*this))
    );
}
bool pswdsec::password::meetsNIST() {
    Wordlist list;
    return (
        this->size() >= 8
        && (!list.contains(*this))
    );
}
bool pswdsec::password::meetsPCI_DSS() {
    Wordlist list;
    auto charSets = this->charUsage();
    return (
        this->size() >= 7
        && (std::get<0>(charSets) || std::get<1>(charSets))
        && std::get<2>(charSets)
    );
}

pswdsec::charSetUsage pswdsec::password::charUsage() {
    bool usage[4] = {false, false, false, false};
    for (const char& element: *this){
        usage[pswdsec::charSet(element)] = true;
    }
    return {usage[0], usage[1], usage[2], usage[3]};
};
size_t pswdsec::password::charSetSize() {
    pswdsec::charSetUsage usage = this->charUsage();
    return (  26 * std::get<0>(usage) \
            + 26 * std::get<1>(usage) \
            + 10 * std::get<2>(usage) \
            + 33 * std::get<3>(usage));
};
double pswdsec::password::getEntropy() {
    double base = std::log2(this->charSetSize());
    size_t exp(this->size());
    return base * exp;
}

size_t pswdsec::password::meetsCharSets() {
    pswdsec::charSetUsage usage = this->charUsage();
    return (std::get<0>(usage) + std::get<1>(usage) + std::get<2>(usage) + std::get<3>(usage));
}
size_t pswdsec::password::getMaxIdenticalCharsInRow() {
    char lastChar = '\000';
    size_t max = 0;
    size_t count = 0;
    for (const char& element: *this) {
        if (element == lastChar) {
            count++;
        }
        else {
            if (count > max){
                max == count;
            }
            count = 0;
            lastChar = element;
        }
    }
    return max;
}