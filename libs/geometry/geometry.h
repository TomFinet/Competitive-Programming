#ifndef GEO
#define GEO

template<typename T>
struct pt {
	T x,y;
	pt operator+(pt p) { return {x + p.x, y + p.y}; }
	pt operator-(pt p) { return {x - p.x, y - p.y}; }
	pt operator*(T d) { return { x * d, y * d}; }
	pt operator/(T d) {return { x / d, y / d };} // only for floating point
};

#endif