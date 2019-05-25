#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include <dimensional/systems/si/constants/constants.hpp>
#include <dimensional/systems/nonsi/minute.hpp>
#include <dimensional/systems/nonsi/hour.hpp>
#include <dimensional/systems/nonsi/day.hpp>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    namespace si = mitama::systems::si;
    namespace nonsi = mitama::systems::nonsi;

    mitama::quantity_t<si::velocity_t, std::int64_t>
        speed_of_light = mitama::systems::si::constants::c<std::int64_t>;

    mitama::quantity_t<si::meter_t, std::int64_t> light_second = speed_of_light * (1 | si::seconds);
    std::cout << "light second:   " << light_second << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_minute = speed_of_light * (1 | nonsi::minutes);
    std::cout << "light minute: " << light_minute << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_hour = speed_of_light * (1 | nonsi::hours);
    std::cout << "light hour: " << light_hour << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_day = speed_of_light * (1 | nonsi::days);
    std::cout << "light day: " << light_day << std::endl;

    static_assert(std::numeric_limits<double>::is_iec559);
    static_assert(std::numeric_limits<double>::digits == 53);

    mitama::quantity_t<si::second_t, double> julian_year = (1.0 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;

    mitama::quantity_t<si::second_t, std::int64_t> julian_year_int = static_cast< mitama::quantity_t<si::second_t, std::int64_t>>(julian_year);
    std::cout << "julian year: " << julian_year_int << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_year = speed_of_light * julian_year_int;
    std::cout << "light year: " << light_year << std::endl;
}
