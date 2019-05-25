#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_IRRADIANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "power.hpp"

namespace mitama::systems::si {
template<class> struct irradiance_synonym{};
using irradiance_t = make_synonym_t<irradiance_synonym, decltype(watt * meter<-2>)>;

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
inline constexpr irradiance_t irradiance{};
using irradiance_r = make_refinement_symbol_t<irradiance_t>;
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_DENSITY_HPP
namespace mitama {
template <> struct abbreviation<systems::si::irradiance_t> { static constexpr char str[] = "W/m^2"; };
}
#endif

#endif
