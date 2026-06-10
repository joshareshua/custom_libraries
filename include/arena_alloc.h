#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H

#include <cstddef>
#include <memory>
#include <vector>

class ArenaAlloc{
public:

    explicit ArenaAlloc(size_t chunk_size);

    ArenaAlloc(const ArenaAlloc&);
    ArenaAlloc& operator=(const ArenaAlloc&);

    ArenaAlloc(ArenaAlloc&&);
    ArenaAlloc& operator=(ArenaAlloc&&) noexcept = default;

    void* allocate(std::size_t bytes, 
        std::size_t alignment = alignof(std::max_align_t));

    void reset();

    size_t used() const;
    size_t capacity() const;
    size_t chunk_count() const{};

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