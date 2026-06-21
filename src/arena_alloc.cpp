#include "../bits/stdc++.h"
#include "../include/arena_alloc.h"

using namespace std;

//Special Member functions

explicit ArenaAlloc::ArenaAlloc(size_t chunk_size): default_chunk_size(chunk_size){}


ArenaAlloc::ArenaAlloc(const ArenaAlloc&) = delete;
ArenaAlloc& ArenaAlloc::operator=(const ArenaAlloc&) = delete;


ArenaAlloc::ArenaAlloc(ArenaAlloc&&) noexcept = default;
ArenaAlloc& ArenaAlloc::operator=(ArenaAlloc&&) noexcept = default;



//Helper Functions

void* ArenaAlloc::allocate(std::size_t bytes, 
        std::size_t alignment = alignof(std::max_align_t)){

            size_t currBytes = bytes;
            size_t begin = -1;
            for (size_t start{}; start < chunks.size(); ++start){
                if (currBytes <= 0)break;
                if (chunks[start].data != nullptr){
                    chunks[start] = add_chunk(default_chunk_size);
                    currBytes -= default_chunk_size;
                    if (begin == -1) begin = start;
                }
            }

            if (bytes > 0) return nullptr;

            return &(chunks[begin]);

}

void ArenaAlloc::reset(){
    chunks.clear();
}

size_t ArenaAlloc::used() const{
    size_t usedChunks{};

    for (const auto& chunk : chunks){
        if (!chunk.data) ++usedChunks;
    }

    size_t chunkSize = sizeof(Chunk);

    return usedChunks * chunkSize;
}

size_t ArenaAlloc::capacity() const{
    return chunks.size() * default_chunk_size;
}

size_t ArenaAlloc::chunk_count() const {
    return chunks.size();
}







