/*
 * Copyright 2020 Justas Masiulis
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
#include "../result.hpp"
#include "../vm/protection.hpp"

namespace ntw::memory {

    struct basic_info {
        std::uintptr_t base;
        std::uintptr_t allocation_base;
        vm::protection allocation_protect;
        std::size_t    size;
        std::uint32_t  state;
        vm::protection protect;
        std::uint32_t  type;

        constexpr static MEMORY_INFORMATION_CLASS info_class = MemoryBasicInformation;
        using native_type                                    = MEMORY_BASIC_INFORMATION;

        /// \brief Returns end of the region
        NTW_INLINE std::uintptr_t end() const noexcept;

        /// \brief Checks whether state is equal to MEM_COMMIT flag.
        NTW_INLINE bool is_commited() const noexcept;

        /// \brief Checks whether state is equal to MEM_RESERVE flag.
        NTW_INLINE bool is_reserved() const noexcept;

        /// \brief Checks whether state is equal to MEM_FREE flag.
        NTW_INLINE bool is_free() const noexcept;

        /// \brief Checks whether type is equal to MEM_MAPPED flag.
        NTW_INLINE bool is_mapped() const noexcept;

        /// \brief Checks whether type is equal to MEM_PRIVATE flag.
        NTW_INLINE bool is_private() const noexcept;

        /// \brief Checks whether type is equal to MEM_IMAGE flag.
        NTW_INLINE bool is_image() const noexcept;
    };

} // namespace ntw::memory

#include "impl/memory.inl"