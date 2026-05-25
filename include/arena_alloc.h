#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include <cstddef>
#include <memory>
#include <vector>

class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size);

    ArenaAlloc(const ArenaAlloc&) = delete;
    ArenaAlloc& operator=(const ArenaAlloc&) = delete;

    ArenaAlloc(ArenaAlloc&&) noexcept = default;
    ArenaAlloc& operator=(ArenaAlloc&&) noexcept = default;

private:
    struct Chunk{
        std::unique_ptr<std::byte[]> data;
        size_t size;
        size_t offset;
    };

    std::vector<Chunk> chunks;
    size_t default_chunk_size;
};

#endif