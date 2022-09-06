# PasswordSecurity
 
System for determining the security of a password.

## usage
```
#include <pswdsec/pswdsec.hpp>

// some code
pswdsec::password p("Your password");
p.getEntropy() //retuns the entropy of the password
```

## functions
| Function        | Usage                                                            |
|-----------------|------------------------------------------------------------------|
| getEntropy      | returns the entropy of the password                              |
| meetsOWASP      | check whether or not the password meets the OWASP criterias      |
| meetsOWASP_ASVS | check whether or not the password meets the OWASP-ASVS criterias |
| meetsNIST       | check whether or not the password meets the NIST criterias       |
| meetsPCI_DSS    | check whether or not the password meets the PCI-DSS criterias    |
## installation
```
$ git clone https://github.com/JulianWww/PasswordSecurity
$ mkdir PasswordSecurity/build && cd PasswordSecurity/build
$ cmake .. && make && sudo make install
```
## update
navigate to the libraries build directory
```
$ git pull https://github.com/JulianWww/PasswordSecurity
$ cmake .. && make && sudo make install
```