#ifndef GEO
#define GEO

template<typename T>
struct pt {
	T x,y;
	pt operator+(pt p) { return { x + p.x, y + p.y }; }
	pt operator-(pt p) { return { x - p.x, y - p.y }; }
	pt operator*(T d) { return { x * d, y * d}; }
	pt operator/(T d) { return { x / d, y / d }; } // only for floating point
};

bool operator==(pt a, pt b) { return a.x == b.x && a.y == b.y; }
bool operator!=(pt a, pt b) { return !(a == b); }

/******************** Basic Point Operations ********************/
template<typename T>
T sq(pt p) { return p.x * p.x + p.y * p.y; }

double abs(pt p) { return sqrt(sq(p)); }

/******************** Transformations ********************/
pt translate(pt v, pt p) { return p+v; }

pt scale(pt c, double factor, pt p) {
	return c + (p-c)*factor;
}

pt rot(pt p, double a) {
	return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

/******************** Products and Angles ********************/
template<typename T>
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

bool isPerp(pt v, pt w) { return dot(v,w) == 0; }

double angle(pt v, pt w) {
	double cosTheta = dot(v,w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

template<typename T>
T cross(pt v, pt w) {return v.x * w.y - v.y * w.x;}

template<typename T>
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }


#endif