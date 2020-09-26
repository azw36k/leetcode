struct pair_hash {
	template <type t1, type t2>
	size_t operator () (pair<t1, t2> const& p) const {
		size_t h1 = hash<t1>()(p.first);
		size_t h2 = hash<t2>()(p.second);
    return h1 ^ h2;
	}
};
