class MinStack {
 public:
  MinStack() {
    data = make_unique<int[]>(INITIAL_CAPACITY);
    min_stack = make_unique<int[]>(INITIAL_CAPACITY);
  }

  void push(int value) {
    if (empty()) {
      min_stack.get()[min_size++] = value;
    } else if (value <= getMin()) {
      if (min_size == min_capacity) {
        grow(min_stack, min_size, min_capacity);
      }
      min_stack.get()[min_size++] = value;
    }

    if (size == capacity) {
      grow(data, size, capacity);
    }
    data.get()[size++] = value;
  }

  void pop() {
    throw_if_empty();
    if (top() == getMin()) {
      --min_size;
    }
    --size;
  }

  int top() {
    throw_if_empty();
    return data.get()[size - 1];
  }

  int getMin() {
    throw_if_empty();
    return min_stack.get()[min_size - 1];
  }

 private:
  static constexpr size_t INITIAL_CAPACITY{10};

  size_t size{0};
  size_t capacity{INITIAL_CAPACITY};
  std::unique_ptr<int[]> data;

  size_t min_size{0};
  size_t min_capacity{INITIAL_CAPACITY};
  std::unique_ptr<int[]> min_stack;

  bool empty() { return size == 0; }

  void grow(unique_ptr<int[]>& ptr, size_t size, size_t& capacity) {
    capacity *= 2;
    unique_ptr<int[]> new_ptr = make_unique<int[]>(capacity);
    std::copy_n(ptr.get(), size, new_ptr.get());
    ptr = std::move(new_ptr);
  }

  void throw_if_empty() {
    if (size == 0) throw std::logic_error("stack is empty");
  }

};
