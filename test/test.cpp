#include <iostream>
#include <pswdsec/wordlist.hpp>
#include <pswdsec/pswdsec.hpp>

int main(int argc, char **argv) {
  //pswdsec::Wordlist list;
  //for (auto const& pswd: list.pswds) {
  //  pswdsec::password p(pswd);
  //  if (p.meetsOWASP()) {
  //    std::cout << pswd << std::endl;
  //  }
  //}
  pswdsec::password word("!599@govnoedi13");
  //std::cout << word.meetsOWASP() << std::endl;
  return 1;
}