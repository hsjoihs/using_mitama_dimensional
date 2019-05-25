#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_ACTIVITY_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_CATALYTIC_ACTIVITY_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct catalytic_activity_synonym{};
using catalytic_activity_t = make_synonym_t<catalytic_activity_synonym, decltype(second<-1> * mol<>)>;

inline constexpr catalytic_activity_t katal{};
using catalytic_activity_r = make_refinement_symbol_t<catalytic_activity_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::catalytic_activity_t> { static constexpr char str[] = "kat"; };
}
#endif
