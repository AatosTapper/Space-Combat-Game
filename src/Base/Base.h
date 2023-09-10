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

template<class T> class Vec2
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
T dot_product(Vec2<T> a, Vec2<T> b)
{
    return a.x * b.x + a.y * b.y;
}

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

void safe_free(void* ptr);
void safe_delete(void* ptr);

} // namespace Base

#endif // BASE_H