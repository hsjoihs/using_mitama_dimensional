#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_ENERGY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct energy_synonym{};
using energy_t = make_synonym_t<energy_synonym, decltype(kilogram<> * meter<2> * second<-2>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
inline constexpr energy_t joule{};
using energy_r = make_refinement_symbol_t<energy_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_HEAT_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_WORK_HPP)
namespace mitama {
template <> struct abbreviation<systems::si::energy_t> { static constexpr char str[] = "J"; };
}
#endif

#endif