
#include "Base.h"

namespace Base
{

// -1 = null, 0 = good
i8 m_check_null_arena(Arena* arena)
{
    if (arena->size == 0)
        return -1;
    if (arena->start_ptr == nullptr)
        return -1;
    if (arena->current_ptr == nullptr)
        return -1;
}

Arena* make_arena()
{
    return (Arena*)malloc(sizeof(Arena));
}

void arena_alloc(Arena* arena, u32 size)
{
    arena->start_ptr = malloc(size);
    arena->current_ptr = arena->start_ptr;
    arena->size = size;
}

void arena_free(Arena* arena)
{
    if (m_check_null_arena(arena) == -1)
        return;

    free(arena->start_ptr);
    arena->start_ptr = nullptr;
    arena->current_ptr = nullptr;
    arena->size = 0;
}

void* arena_push(Arena* arena, void* ptr, u32 size)
{
    if (m_check_null_arena(arena) == -1)
        return nullptr;

    char* start_char_pointer = static_cast<char*>(arena->start_ptr);
    char* current_char_pointer = static_cast<char*>(arena->current_ptr);

    u32 used_data_size = current_char_pointer - start_char_pointer;
    u32 remaining_data_size = arena->size - used_data_size;

    if (size >= remaining_data_size)
        return nullptr;

    memcpy(arena->current_ptr, ptr, size);
    arena->current_ptr = start_char_pointer + size;
    return current_char_pointer;
}

void safe_free(void* ptr)
{
    if (ptr != nullptr)
    {
        free(ptr);
        ptr = nullptr;
    }   
}

void safe_delete(void* ptr)
{
    if (ptr != nullptr)
    {
        delete(ptr);
        ptr = nullptr;
    }   
}

} // namespace Base