#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLALITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLALITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct molality_synonym{};
using molality_t = make_synonym_t<molality_synonym, decltype(mol<> / kilogram<>)>;

inline constexpr molality_t molality{};
using molality_r = make_refinement_symbol_t<molality_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::molality_t> { static constexpr char str[] = "mol/kg"; };
}
#endif
