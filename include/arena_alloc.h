#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include <cstddef>

class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size);

    ArenaAlloc(const ArenaAlloc&) = delete;
    ArenaAlloc& operator=(const ArenaAlloc&) = delete;

    ArenaAlloc(ArenaAlloc&&) noexcept = default;
    ArenaAlloc& operator=(ArenaAlloc&&) noexcept = default;

private:
};

#endif