#ifndef MAPPER_H
#define MAPPER_H

template<class K, class V>
class Mapper {
	std::map<K, V> map_;

public:
	Mapper(const K& k, const V& v) {
		map_.insert(std::make_pair(k, v));
	}

	operator std::map<K, V>() const {
		return map_;
	}

	template<class anotherK, class anotherV>
	Mapper<K, V>& operator () (const anotherK& k, const anotherV& v) {
		map_.insert(std::make_pair((K)k, (V)v));
		return *this;
	}
};

template<class K, class V>
Mapper<K, V> mapper(const K& k, const V& v) {
	return Mapper<K, V>(k, v);
}

template<class K, class V>
Mapper<std::shared_ptr<K>, V> mapper(K* k, const V& v) {
	return Mapper<std::shared_ptr<K>, V>(std::shared_ptr<K>(k), v);
}

template<class K, class V>
Mapper<K, std::shared_ptr<V>> mapper(const K& k, V* v) {
	return Mapper<K, std::shared_ptr<V>>(k, std::shared_ptr<V>(v));
}

template<class K, class V>
Mapper<std::shared_ptr<K>, std::shared_ptr<V>> mapper(K* k, V* v) {
	return Mapper<std::shared_ptr<K>, std::shared_ptr<V>>(std::shared_ptr<K>(k), std::shared_ptr<V>(v));
}

#endif