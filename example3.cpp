#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main()
{
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t width = 2 | si::meters;
    // height = 3 m
    mitama::quantity_t height = 3 | si::meters;
    // area = 6 m^2
    mitama::quantity_t<si::area_t, int> area = width * height;
}