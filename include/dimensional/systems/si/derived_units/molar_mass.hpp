#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_MASS_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct molar_mass_synonym{};
using molar_mass_t = make_synonym_t<molar_mass_synonym, decltype(kilogram<> / mol<>)>;

inline constexpr molar_mass_t molar_mass{};
using molar_mass_r = make_refinement_symbol_t<molar_mass_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::molar_mass_t> { static constexpr char str[] = "kg/mol"; };
}
#endif
