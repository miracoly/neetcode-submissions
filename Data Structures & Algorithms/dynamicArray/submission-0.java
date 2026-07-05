class DynamicArray {
    private int capacity;
    private int size;
    private int[] array;

    public DynamicArray(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.array = new int[capacity];
    }

    public int get(int i) {
        return i < size ? array[i] : -1;
    }

    public void set(int i, int n) {
        if (i < capacity) {
            array[i] = n;
        }
    }

    public void pushback(int n) {
        if (size >= capacity) resize();
        
        array[size++] = n;
    }

    public int popback() {
        return size > 0 ? array[--size] : -1;
    }

    private void resize() {
        this.capacity *= 2;
        final int[] tmp = new int[capacity];
        if (size >= 0) {
            System.arraycopy(this.array, 0, tmp, 0, size);
        }
        this.array = tmp;
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }
}

