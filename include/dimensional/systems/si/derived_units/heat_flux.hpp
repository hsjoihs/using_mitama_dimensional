#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_FLUX_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "./power.hpp"

namespace mitama::systems::si {
template<class> struct heat_flux_synonym{};
using heat_flux_t = make_synonym_t<heat_flux_synonym, decltype(watt * meter<-2>)>;

inline constexpr heat_flux_t heat_flux{};
using heat_flux_r = make_refinement_symbol_t<heat_flux_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::heat_flux_t> { static constexpr char str[] = "W/m^2"; };
}
#endif
