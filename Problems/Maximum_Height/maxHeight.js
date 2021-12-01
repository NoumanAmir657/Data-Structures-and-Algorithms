// Time Complexity: O(n)
// Space Complexity: O(n)
const maxHeight = (node, count) => {
    if (node === null){
        return count;
    }

    ++count
    return Math.max(maxHeight(node.left, count), maxHeight(node.right, count))
}