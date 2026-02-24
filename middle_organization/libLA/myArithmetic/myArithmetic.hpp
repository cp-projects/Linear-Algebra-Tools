#pragma once

template< typename T>
inline constexpr T absolute(T x){
    return x < 0 ? -x : x;
}
