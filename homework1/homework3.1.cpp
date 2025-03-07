#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
public:
    Address(){}
    Address(std::string city, std::string street, int houseNumber, int apartamentNumber) :
        city(city),
        street(street),
        houseNumber(houseNumber),
        apartmentNumber(apartamentNumber)
    {}
    std::string get_output_address()
    {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main()
{
    int numberOfAddresses{};
    Address* addresses{};
    std::fstream in("in.txt");
    if (in.is_open())
    {
        in >> numberOfAddresses;
        addresses = new Address[numberOfAddresses];
        std::string city{}, street{};
        int houseNumber{}, apartamentNumber{};
        for (int count{}; count < numberOfAddresses; ++count)
        {
            std::getline(in >> std::ws, city);
            std::getline(in >> std::ws, street);
            in >> houseNumber;
            in >> apartamentNumber;

            Address address(city, street, houseNumber, apartamentNumber);
            addresses[count] = address;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
    in.close();

    std::ofstream out("out.txt");
    if (out.is_open())
    {
        out << numberOfAddresses << '\n';
        for (int count{}; count < numberOfAddresses; ++count)
        {
            out << addresses[count].get_output_address() << '\n';
        }
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}