#pragma once
const double PI = 3.141592653589793;
const double HALF_PI = 1.570796326794897;
const double DOUBLE_PI = 6.283185307179586;
const double SIN_CURVE_A = 0.0415896;
const double SIN_CURVE_B = 0.00129810625032;
#define DEG2RAD(x) ((float)(x) * (float)((float)(PI) / 180.f))
#define ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR) / sizeof(*(_ARR))))
template<typename T>
class MyVector {
private:
    T arr[3000];
    int vsize;

public:
    MyVector() : vsize(0) {}
    template<typename... Args>
    MyVector(Args... args) : vsize(0) {
        push_back(args...);
    }

    void push_back(const T& element) {
        if (vsize < 3000) {
            arr[vsize] = element;
            vsize++;
        }
    }
    void clear() {
        vsize = 0;
    }
    T& at(size_t index) {
        if (index < vsize) {
            return arr[index];
        }
    }
    const T& at(size_t index) const {
        if (index < vsize) {
            return arr[index];
        }
    }
    T& operator[](size_t index) {
        return arr[index];
    }
    const T& operator[](size_t index) const {
        return arr[index];
    }
    int size() const {
        return vsize;
    }
    const T* data() const {
        return arr;
    }
    T* begin() {
        return arr;
    }
    const T* begin() const {
        return arr;
    }
    bool empty() const {
        return vsize == 0;
    }
    T* end() {
        return arr + vsize;
    }
    const T* end() const {
        return arr + vsize;
    }
    void erase(const T* index) {
        if (index < arr || index >= arr + vsize) {
            return;
        }
        size_t eraseIndex = index - arr;
        erase(eraseIndex);
    }
    void erase(size_t index) {
        if (index >= vsize) {
            return;
        }
        for (size_t i = index; i < vsize - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --vsize;
    }
    void pop_back() {
        if (vsize > 0) {
            T lastElement = arr[vsize - 1];
            --vsize;
            return lastElement;
        }
    }
    template<typename Arg>
    void insert(size_t index, const Arg& arg) {
        if (index >= vsize || vsize >= 3000) {
            return;
        }
        for (size_t i = vsize; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = arg;
        ++vsize;
    }
    template<typename Arg>

    void insert(Arg _Where, const int _Count, const T& _Val) {
        // Check if there is enough space to insert
        if (vsize + _Count > 3000) {
        }

        // Calculate the position to insert at
        size_t insertIndex = _Where - begin();

        // Shift elements to make room for new elements
        for (size_t i = vsize - 1; i >= insertIndex; --i) {
            arr[i + _Count] = arr[i];
        }

        // Insert new elements
        for (size_t i = 0; i < _Count; ++i) {
            arr[insertIndex + i] = _Val;
        }

        vsize += _Count;

        return begin() + insertIndex;
    }
private:
    template<typename Arg>
    void push_back(const Arg& arg) {
        push_back(T(arg));
    }
    template<typename Arg, typename... Args>
    void push_back(const Arg& arg, Args... args) {
        push_back(T(arg));
        push_back(args...);
    }
};
template <typename T>
class initializer_listr {
public:
    using value_type = T;
    using reference = const T&;
    using const_reference = const T&;
    using size_type = size_t;
public:
    const T* m_array;
    size_t m_size;
    constexpr initializer_listr(const T* array, size_t size)
        : m_array(array), m_size(size) {}
    constexpr initializer_listr() noexcept
        : m_array(nullptr), m_size(0) {}
    constexpr const T* begin() const noexcept { return m_array; }
    constexpr const T* end() const noexcept { return m_array + m_size; }
    constexpr size_t size() const noexcept { return m_size; }
};
template<typename T>
constexpr initializer_listr<T> make_initializer_list(const T* array, size_t size) {
    return initializer_listr<T>(array, size);
}
namespace detail {
    template<typename T, typename U>
    struct is_same {
        inline static bool value = true;
    };
    template<typename T>
    struct is_same<T, T> {
        inline static bool value = true;
    };
}
template<typename T, typename U>
bool is_same_v = detail::is_same<T, U>::value;
namespace dxmm::math {
    template <typename T>
    inline T m_abs(T t) {
        return t > 0 ? t : -t;
    }
    double asin(double d);
    double tan(double d);
    double fabsf(double num);
    float roundf(float x);
    static inline int    clamp(int v, int mn, int mx) { return (v < mn) ? mn : (v > mx) ? mx : v; }
    static inline float  clamp(float v, float mn, float mx) { return (v < mn) ? mn : (v > mx) ? mx : v; }
    float lerp(float a, float b, float t);
    int abs(int x);
    double floor(double x);
    int xfloor(float value);
    double ceil(double x);
    float cos(float x);
    float sin(float x);
    float pow(float a, float b);
    float sqrt(float a);
    double tan2(double x);
    float atan(float v);
    float atan2(float y, float x);
    float fmod(float a, float b);
    float atof(const char* string);
    int rand(void);
    int customRand(int min, int max);
    template<class InputIterator, class T>
    InputIterator find(InputIterator first, InputIterator last, const T& val)
    {
        while (first != last) {
            if (*first == val) return first;
            ++first;
        }
        return last;
    }
}