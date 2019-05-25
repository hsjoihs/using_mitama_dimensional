#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_CONDUCTIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"


namespace mitama::systems::si {
template<class> struct thermal_conductivity_synonym{};
using thermal_conductivity_t = make_synonym_t<thermal_conductivity_synonym, decltype( watt * meter<-1> * kelvin<-1> )>;

inline constexpr thermal_conductivity_t thermal_conductivity{};
using thermal_conductivity_r = make_refinement_symbol_t<thermal_conductivity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::thermal_conductivity_t> { static constexpr char str[] = "W/(m·K)"; };
}
#endif
