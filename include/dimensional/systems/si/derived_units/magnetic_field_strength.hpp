#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct magnetic_field_strength_synonym{};
using magnetic_field_strength_t = make_synonym_t<magnetic_field_strength_synonym, decltype(ampere<> / meter<>)>;

inline constexpr magnetic_field_strength_t magnetic_field_strength{};
using magnetic_field_strength_r = make_refinement_symbol_t<magnetic_field_strength_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
namespace mitama {
template <> struct abbreviation<systems::si::magnetic_field_strength_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
