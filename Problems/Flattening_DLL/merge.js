// Flattening double linked lists
// Space Complexity: O(1)
// Time Complexity: O(2n)
const merge = (head) => {
    let current = head;
    while (current != 0) {
        if (current.child){
            let temp = current.next
            current.next = current.child
            
            let childItr = current.child
            while(childItr){
                if (childItr.next == 0){
                    childItr.next = temp.child
                    temp.pre = childItr
                }
                else {
                    childItr = childItr.next
                }
            }
        }
        else {
            current = current.next
        }
    }
    return head;
}