//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_BINDINGS_DETAIL_REQUIRES_HPP
#define BOOST_DI_BINDINGS_DETAIL_REQUIRES_HPP

#include "boost/di/aux_/config.hpp"
#include "boost/di/aux_/mpl.hpp"

namespace boost {
namespace di {
namespace bindings {
namespace detail {

template<typename T, typename TBind>
using apply_bind = typename TBind::template apply<T>::type;

template<typename T, typename TBind>
using eval_bind = typename TBind::template eval<T>::type;

template<typename... Ts>
struct requires_ {
    using type = requires_;

    template<typename T, typename TMultiplicationFactor = int_<10>>
    using apply = times<TMultiplicationFactor, typename apply_bind<T, Ts>::type...>;

    template<typename T>
    using eval = times<int_<1>, typename eval_bind<T, Ts>::type...>;
};

} // namespace detail
} // namespace bindings
} // namespace di
} // namespace boost

#endif

