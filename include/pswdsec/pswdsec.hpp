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

        public: bool meetsOWASP();
        public: bool meetsOWASP_ASVS();
        public: bool meetsNIST();
        public: bool meetsPCI_DSS();

        public: charSetUsage charUsage();
        public: size_t charSetSize();
        public: double getEntropy();

        private: size_t meetsCharSets();
        private: size_t getMaxIdenticalCharsInRow();
    };
}

template<typename ...T>
pswdsec::password::password(T... data): std::string(data...) {};