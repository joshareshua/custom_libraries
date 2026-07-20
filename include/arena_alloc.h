#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include <cstddef>
#include <memory>
#include <vector>

template <typename T>
class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size);

    ArenaAlloc(const ArenaAlloc&) = delete;
    ArenaAlloc& operator=(const ArenaAlloc&) = delete;

    ArenaAlloc(ArenaAlloc&&) = default;
    ArenaAlloc& operator=(ArenaAlloc&&) = default;

    void* allocate(std::size_t bytes, 
        std::size_t alignment = alignof(std::max_align_t));

    void reset();

    size_t used() const;
    size_t capacity() const;
    size_t chunk_count() const;
    size_t get_available() const;

private:
    struct Chunk{
        std::unique_ptr<std::byte[]> data;
        size_t size;
        size_t offset;
    };

    std::vector<Chunk> chunks;
    size_t default_chunk_size;
    Chunk& add_chunk(std::size_t minimum_size);
};

#endif