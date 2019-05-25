#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ELECTRIC_CURRENT_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct electric_current_density_synonym{};
using electric_current_density_t = make_synonym_t<electric_current_density_synonym, decltype(ampere<> / meter<2>)>;

inline constexpr electric_current_density_t electric_current_density{};
using electric_current_density_r = make_refinement_symbol_t<electric_current_density_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::electric_current_density_t> { static constexpr char str[] = "A/m^2"; };
}
#endif
