#include "sms.hpp"

int main()
{
    Reseau r1;

    std::cout << r1.lister();

    r1.ajouter("0635927810");

    std::cout << r1.lister();

    r1.ajouter("0635927810");
    r1.ajouter("0635927810");

    std::cout << r1.lister();

    std::cout << (nullptr == 0);

}