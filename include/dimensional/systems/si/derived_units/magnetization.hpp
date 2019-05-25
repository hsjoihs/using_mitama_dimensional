#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIZATION_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct magnetization_synonym{};
using magnetization_t = make_synonym_t<magnetization_synonym, decltype(ampere<> / meter<>)>;

inline constexpr magnetization_t magnetization{};
using magnetization_r = make_refinement_symbol_t<magnetization_t>;
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_FIELD_STRENGTH_HPP
namespace mitama {
template <> struct abbreviation<systems::si::magnetization_t> { static constexpr char str[] = "A/m"; };
}
#endif

#endif
