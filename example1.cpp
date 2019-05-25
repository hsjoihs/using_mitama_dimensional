#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>

int main()
{
    namespace si = mitama::systems::si;
    // width = 2 m
    mitama::quantity_t<si::meter_t, int> width = 2;
    // height = 3 m
    mitama::quantity_t<si::meter_t, int> height = 3;
    // area = 6 m^2
    mitama::quantity_t<si::area_t, int> area = width * height;
}