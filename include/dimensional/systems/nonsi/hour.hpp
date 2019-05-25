#ifndef MITAMA_DIMENSIONAL_NONSI_UNITS_HOUR_HPP
#define MITAMA_DIMENSIONAL_NONSI_UNITS_HOUR_HPP
#include <dimensional/systems/si/second.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>

namespace mitama::systems::nonsi {
using hour_t = scaled_unit_t<systems::si::second_t, std::ratio<60*60>>;
inline constexpr hour_t hours{};
}

namespace mitama {
template <> struct abbreviation<systems::nonsi::hour_t> { static constexpr char str[] = "h"; };
}

#endif