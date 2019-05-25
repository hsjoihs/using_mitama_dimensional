#ifndef MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP
#define MITAMA_DIMENSIONAL_DERIVED_UNITS_DIFFUSION_COEFFICIENT_HPP
#include <dimensional/systems/si/all.hpp>
#include <dimensional/quantity.hpp>
#include <dimensional/io.hpp>
#include <dimensional/refinement.hpp>


namespace mitama::systems::si {
template<class> struct diffusion_coefficient_synonym{};
using diffusion_coefficient_t = make_synonym_t<diffusion_coefficient_synonym, decltype(meter<2> / second<1>)>;

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP)
inline constexpr diffusion_coefficient_t diffusion_coefficient{};
using diffusion_coefficient_r = make_refinement_symbol_t<diffusion_coefficient_t>;
#endif
}

#if !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_THERMAL_DIFFUSIVITY_HPP) && !defined(MITAMA_DIMENSIONAL_DERIVED_UNITS_KINEMATIC_VISCOSITY_HPP)
namespace mitama {
template <> struct abbreviation<systems::si::diffusion_coefficient_t> { static constexpr char str[] = "m^2/s"; };
}
#endif

#endif
