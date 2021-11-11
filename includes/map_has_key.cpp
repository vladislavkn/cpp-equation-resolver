template <typename K, typename V>
bool map_has_key(map<K, V> map_holder, K key) {
	return map_holder.find(key) != map_holder.end();
}
