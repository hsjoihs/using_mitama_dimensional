#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_WEIGHT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>

namespace mitama::systems::si {
template<class> struct weight_synonym{};
using weight_t = make_synonym_t<weight_synonym, decltype(kilogram<> * meter<> * second<-2>)>;
#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
inline constexpr weight_t newton{};
using weight_r = make_refinement_symbol_t<weight_t>;
#endif
}

#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_FORCE_HPP
namespace mitama {
template <> struct abbreviation<systems::si::weight_t> { static constexpr char str[] = "N"; };
}
#endif

#endif