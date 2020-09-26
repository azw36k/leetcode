struct pair_hash {
	template <typename t1, typename t2>
	size_t operator () (pair<t1, t2> const& p) const {
		size_t h1 = hash<t1>()(p.first);
		size_t h2 = hash<t2>()(p.second);
    return h1 ^ h2;
	}
};
