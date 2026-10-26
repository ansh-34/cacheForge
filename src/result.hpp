#pragma once

#include "error.hpp"

#include <expected>

namespace cacheforge
{

template <typename T> using Result = std::expected<T, Error>;

} // namespace cacheforge
