#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_RESISTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_RESISTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"


namespace mitama::systems::si {
template<class> struct thermal_resistance_synonym{};
using thermal_resistance_t = make_synonym_t<thermal_resistance_synonym, decltype(kelvin<> / watt)>;

inline constexpr thermal_resistance_t thermal_resistance{};
using thermal_resistance_r = make_refinement_symbol_t<thermal_resistance_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::thermal_resistance_t> { static constexpr char str[] = "K/W"; };
}
#endif
