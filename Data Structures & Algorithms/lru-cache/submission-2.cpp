struct Entry {
  int key;
  int value;
};

using List = std::list<Entry>;
using ListIt = List::iterator;

class LRUCache {
 public:
  explicit LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);

 private:
  int _capacity;
  List _ls;
  std::unordered_map<int, ListIt> _map;
};

LRUCache::LRUCache(int capacity) : _capacity(capacity) {}

int LRUCache::get(int key) {
  const auto finding = _map.find(key);
  if (finding == _map.end()) return -1;

  const auto entryIt = finding->second;
  _ls.splice(_ls.end(), _ls, entryIt);

  return finding->second->value;
}

void LRUCache::put(int key, int value) {
  const auto finding = _map.find(key);
  if (finding == _map.end()) {
    // not found, add new
    if (static_cast<int>(_ls.size()) == _capacity) {
      const auto head = _ls.front();
      _ls.pop_front();
      _map.erase(head.key);
    }
    _ls.push_back({.key = key, .value = value});
    auto end = _ls.end();
    --end;
    _map[key] = end;
  } else {
    // found
    const auto entryIt = finding->second;
    _ls.splice(_ls.end(), _ls, entryIt);
    entryIt->value = value;
  }
}

