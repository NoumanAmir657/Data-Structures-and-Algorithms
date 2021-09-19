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

// Floyd's Hare and Tortorise Algorithm for Cycle Detection
// Time Complexity O(n)
// Space Complexity O(1)

const optimizedDetectCycle = (head) => {
    let hare = head, tort = head;

    while (true) {
        hare = hare.next;
        tort = tort.next;

        if (hare.next === null || hare === null) {
            return false;
        }
        else {
            hare = hare.next;
        }

        if (tort === hare) {
            break
        }
    }

    let p1 = head, p2 = tort;
    while (p1 !== p2){
        p1 = p1.next
        p2 = p2.next
    }

    return p1
}