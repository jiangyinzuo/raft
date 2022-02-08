/*
 * Copyright (c) 2022, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "detail/init.hpp"

namespace raft {
namespace linalg {

/**
 * @brief Like Python range.
 *
 * Fills the output as out[i] = i.
 *
 * \param [out] out device array, size [end-start]
 * \param [in] start of the range
 * \param [in] end of range (exclusive)
 * \param [in] stream cuda stream
 */
template <typename T>
void range(T* out, int start, int end, cudaStream_t stream)
{
  detail::range(out, start, end, stream);
}

/**
 * @brief Like Python range.
 *
 * Fills the output as out[i] = i.
 *
 * \param [out] out device array, size [n]
 * \param [in] n length of the array
 * \param [in] stream cuda stream
 */
template <typename T, int TPB = 256>
void range(T* out, int n, cudaStream_t stream)
{
  detail::range(out, n, stream);
}

}  // namespace linalg
}  // namespace raft