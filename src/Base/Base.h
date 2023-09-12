#ifndef BASE_H
#define BASE_H

#include <iostream>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;

namespace Base
{

// VECTOR

template<class T> 
class Vec2
{
public:
    Vec2(T _x = 0, T _y = 0) : x(_x), y(_y) {}

    T x, y;

    Vec2<T> operator+(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x + obj.x, this->y + obj.y);
    }
    Vec2<T> operator+=(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x += obj.x, this->y += obj.y);
    }
    Vec2<T> operator-(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x - obj.x, this->y - obj.y);
    }
    Vec2<T> operator-=(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x -= obj.x, this->y -= obj.y);
    }
    Vec2<T> operator*(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x * obj.x, this->y * obj.y);
    }
    Vec2<T> operator*=(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x *= obj.x, this->y *= obj.y);
    }
    Vec2<T> operator/(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x / obj.x, this->y / obj.y);
    }
    Vec2<T> operator/=(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x /= obj.x, this->y /= obj.y);
    }
    Vec2<T> operator=(Vec2<T> const& obj)
    {
        return Vec2<T>(this->x = obj.x, this->y = obj.y);
    }
};

template<typename T>
T vector_dot_product(const Vec2<T>& a, const Vec2<T>& b)
{
    return a.x * b.x + a.y * b.y;
}

template<typename T>
T vector_distance(const Vec2<T>& a, const Vec2<T>& b)
{
    T d_x = a.x - b.x;
    T d_y = a.y - b.y;
    return sqrt(d_x * d_x + d_y * d_y);
}

template<typename T>
T vector_len(const Vec2<T>& a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}


// ARENA

typedef struct Arena
{
    void* start_ptr;
    void* current_ptr;
    u32 size;
} Arena;

Arena* make_arena();
void arena_alloc(Arena* arena, u32 size);
// remember to also free the pointer after this
void arena_free(Arena* arena);
// user has to check for nullptr
void* arena_push(Arena* arena, void* ptr, u32 size);


// MEMORY UTILITY

template<typename T> 
void safe_free(T* ptr)
{
    if (ptr != nullptr)
    {
        free(ptr);
        ptr = nullptr;
    }   
}

template<typename T> 
void safe_delete(T* ptr)
{
if (ptr != nullptr)
    {
        delete(ptr);
        ptr = nullptr;
    }  
}

} // namespace Base

#endif