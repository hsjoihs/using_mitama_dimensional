#ifndef MITAMA_DIMENSIONAL_SI_UNITS_AMPERE_HPP
#define MITAMA_DIMENSIONAL_SI_UNITS_AMPERE_HPP
#include <dimensional/quantity.hpp>

namespace mitama::systems::si {
struct electric_current {
    using is_base_dimension = void;
};

using ampere_t = make_unit_t<electric_current>;

using milliampere_t = scaled_unit_t<ampere_t, std::milli>;
using microampere_t = scaled_unit_t<ampere_t, std::micro>;
using nanoampere_t = scaled_unit_t<ampere_t, std::nano>;

using kiloampere_t = scaled_unit_t<ampere_t, std::kilo>;
using megaampere_t = scaled_unit_t<ampere_t, std::mega>;
using teraampere_t = scaled_unit_t<ampere_t, std::tera>;

template < std::intmax_t N = 1 >
using ampere_ = powered_t<ampere_t, N>;

template < std::intmax_t N = 1 >
using milliampere_ = powered_t<milliampere_t, N>;
template < std::intmax_t N = 1 >
using microampere_ = powered_t<microampere_t, N>;
template < std::intmax_t N = 1 >
using nanoampere_ = powered_t<nanoampere_t, N>;

template < std::intmax_t N = 1 >
using kiloampere_ = powered_t<kiloampere_t, N>;
template < std::intmax_t N = 1 >
using megaampere_ = powered_t<megaampere_t, N>;
template < std::intmax_t N = 1 >
using teraampere_ = powered_t<teraampere_t, N>;


inline constexpr ampere_t amperes{};

inline constexpr milliampere_t milliamperes{};
inline constexpr microampere_t microamperes{};
inline constexpr nanoampere_t nanoamperes{};

inline constexpr kiloampere_t kiloamperes{};
inline constexpr megaampere_t megaamperes{};


template < std::intmax_t N = 1 > inline constexpr powered_t<ampere_t, N> ampere{};

template < std::intmax_t N = 1 > inline constexpr powered_t<milliampere_t, N> milliampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<microampere_t, N> microampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<nanoampere_t, N> nanoampere{};

template < std::intmax_t N = 1 > inline constexpr powered_t<kiloampere_t, N> kiloampere{};
template < std::intmax_t N = 1 > inline constexpr powered_t<megaampere_t, N> megaampere{};

}

#endif