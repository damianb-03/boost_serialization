#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

struct c_doc{
    unsigned m_id;
    long long m_num;
    std::string m_username;

    template <typename Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & m_id;
        ar & m_num;
        ar & m_username;
    }
};

int main()
{
    std::stringstream ss;
    {
        boost::archive::text_oarchive sa(ss);

        c_doc andz{5,242342342,"andrzyj"};
        sa << andz;
    }

    std::cout << ss.str();

    {
        boost::archive::text_iarchive sa(ss);
        c_doc andz2;
        sa >> andz2;

        std::cout << andz2.m_id << " : " << andz2.m_num << " : " << andz2.m_username << std::endl;
    }

    return 0;
}

