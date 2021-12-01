class PriorityQueue {
    constructor(comparator = (a,b) => a > b){
        this._heap = []
        this._comparator = comparator
    }

    size() {
        return this._heap.length
    }

    isEmpty() {
        return this.size() == 0
    }

    peek() {
        return this._heap[0]
    }

    _parent(index) {
        return Math.floor((index-1)/2)
    }

    _left(index) {
        return (index*2) + 1
    }

    _right(index) {
        return (index*2) + 2
    }

    _swap(i, j) {
        const temp = this._heap[i]
        this._heap[i] = this._heap[j]
        this._heap[j] = temp
    }

    _compare(i, j) {
        return this._comparator(this._heap[i], this._heap[j])
    }

    push(value) {
        this._heap.push(value)
        this._siftUp();
        return this.size()
    }

    // Time Complexity O(log(n))
    _siftUp() {
        let nodeIndex = this.size() - 1
        while(nodeIndex > 0 && this._compare(nodeIndex, this._parent(nodeIndex))){
            this._swap(nodeIndex, this._parent(nodeIndex))
            nodeIndex = this._parent(nodeIndex)
        }
    }

    pop() {
        if (this.size() > 1){
            this._swap(0, this.size() - 1)
        }
        const poppedValue = this._heap.pop()
        this._siftDown()
        return poppedValue
    }

    // Time Complexity O(log(n))
    _siftDown() {
        let nodeIndex = 0;
        while((this._left(nodeIndex) < this.size() && 
        this._compare(this._left(nodeIndex), nodeIndex)) || (this._right(nodeIndex) < this.size() && this._compare(this._right(nodeIndex), nodeIndex))){
            const greaterNodeIndex = this._right(nodeIndex) < this.size() && this._compare(this._right(nodeIndex), this._left(nodeIndex)) ? this._right(nodeIndex) : this._left(nodeIndex)
            this._swap(greaterNodeIndex, nodeIndex)
            nodeIndex = greaterNodeIndex
        }
    }
}