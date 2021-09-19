// Cycle Detection in a linked list
// Time Complexity O(n)
// Space Complexity O(n)
const detectCycle = (head) => {
    let currentNode = head;
    const seenNodes = new Set();    // can use hashmap instead of Set

    while (!seenNodes.has(currentNode.value)){
        if (currentNode.next === null) {
            return false
        }
        seenNodes.add(currentNode.value)
        currentNode = currentNode.next
    }
    return currentNode
}