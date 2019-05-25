#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_MOMENT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>
#include "magnetic_flux.hpp"

namespace mitama::systems::si {
template<class> struct magnetic_moment_synonym{};
using magnetic_moment_t = make_synonym_t<magnetic_moment_synonym, decltype(weber * meter<>)>;

inline constexpr magnetic_moment_t magnetic_moment{};
using magnetic_moment_r = make_refinement_symbol_t<magnetic_moment_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::magnetic_moment_t> { static constexpr char str[] = "Wb·m"; };
}
#endif
