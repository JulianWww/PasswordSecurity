#pragma once

#include <string>
#include <tuple>
#include <jce/math.hpp>

namespace pswdsec {
    // what characters are used (lower case, upper case, numbers, special Characters)
    using charSetUsage                  = std::tuple<bool, bool, bool, bool>;

    // main class used for calculating the security of a password.
    class password : public std::string {
        // initialize the password like a string
        public: template<typename ...T>
        password(T... data);
        ~password();

        public: bool meetsOWASP() const;
        public: bool meetsOWASP_ASVS() const;
        public: bool meetsNIST() const;
        public: bool meetsPCI_DSS() const;

        private: charSetUsage charUsage() const;
        private: size_t charSetSize() const;
        public: double getEntropy() const;

        private: size_t meetsCharSets() const;
        private: size_t getMaxIdenticalCharsInRow() const;
    };
}

template<typename ...T>
pswdsec::password::password(T... data): std::string(data...) {};