#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_FLUX_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_LUMINOUS_FLUX_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "solid_angle.hpp"

namespace mitama::systems::si {
template<class> struct luminous_flux_synonym{};
using luminous_flux_t = make_synonym_t<luminous_flux_synonym, decltype(candela<> * steradian)>;

inline constexpr luminous_flux_t lumen{};
using luminous_flux_r = make_refinement_symbol_t<luminous_flux_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::luminous_flux_t> { static constexpr char str[] = "lm"; };
}
#endif
