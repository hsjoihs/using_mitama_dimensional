// begin example
#include <dimensional/quantity.hpp>
#include <dimensional/systems/si/all.hpp>

int main() {
    namespace si = mitama::systems::si;
    using mitama::quantity_t;

    // Template argument deduction for class templates
    quantity_t mass = 3 | si::kilograms; // 3 [kg]

    quantity_t time = 1.66 | si::seconds; // 1.66 [s]

    quantity_t volume = 4 | si::meter<3>; // 4 [m^3]
}
// end example