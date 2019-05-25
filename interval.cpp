#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <iostream>
#include <kv/interval.hpp>
#include <kv/rdouble.hpp>

int main()
{
    using namespace mitama;
    namespace si = mitama::systems::si;
    using kv::interval;

    interval<double> a(1, 2);
    auto b = a | si::meters;
    std::cout << b + b << std::endl;
    std::cout << b - b << std::endl;
    std::cout << b * b << std::endl;
    std::cout << b / b << std::endl;
}
