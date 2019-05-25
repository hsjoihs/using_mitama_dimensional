#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_VOLUME_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MOLAR_VOLUME_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct molar_volume_synonym{};
using molar_volume_t = make_synonym_t<molar_volume_synonym, decltype(meter<3> / mol<>)>;

inline constexpr molar_volume_t molar_volume{};
using molar_volume_r = make_refinement_symbol_t<molar_volume_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::molar_volume_t> { static constexpr char str[] = "m^3/mol"; };
}
#endif
