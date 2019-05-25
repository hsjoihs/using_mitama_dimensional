#ifndef MITAMA_DIMENSIONAL_SI_UNITS_KELVIN_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_KELVIN_HPP
#include <dimensional/quantity.hpp>

namespace mitama::systems::si {
// base dimension
struct thermodynamic_temperature {
    using is_base_dimension = void;
};

using kelvin_t = make_unit_t<thermodynamic_temperature>;
using millikelvin_t = scaled_unit_t<kelvin_t, std::milli>;
using microkelvin_t = scaled_unit_t<kelvin_t, std::milli>;
using kilokelvin_t = scaled_unit_t<kelvin_t, std::kilo>;
using megakelvin_t = scaled_unit_t<kelvin_t, std::mega>;

template < std::intmax_t N = 1 >
using kelvin_ = powered_t<kelvin_t, N>;
template < std::intmax_t N = 1 >
using millikelvin_ = powered_t<millikelvin_t, N>;
template < std::intmax_t N = 1 >
using microkelvin_ = powered_t<microkelvin_t, N>;
template < std::intmax_t N = 1 >
using kilokelvin_ = powered_t<kilokelvin_t, N>;
template < std::intmax_t N = 1 >
using megakelvin_ = powered_t<megakelvin_t, N>;

inline constexpr kelvin_t kelvins{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kelvin_t, N> kelvin{};

}

#endif