#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DENSITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DENSITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct density_synonym{};
using density_t = make_synonym_t<density_synonym, decltype(meter<-3> * kilogram<>)>;

inline constexpr density_t density{};
using density_r = make_refinement_symbol_t<density_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::density_t> { static constexpr char str[] = "kg/m^3"; };
}


#endif
