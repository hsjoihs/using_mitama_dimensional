#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RELUCTANCE_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_MAGNETIC_RELUCTANCE_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
using magnetic_reluctance_t = reciprocal_t<decltype(kilogram<> * meter<2> * second<-2> * ampere<-2>)>;

inline constexpr magnetic_reluctance_t magnetic_reluctance{};
using magnetic_reluctance_r = make_refinement_symbol_t<magnetic_reluctance_t>;
}

namespace mitama {
template <> struct abbreviation<systems::si::magnetic_reluctance_t> { static constexpr char str[] = "H^-1"; };
}
#endif
