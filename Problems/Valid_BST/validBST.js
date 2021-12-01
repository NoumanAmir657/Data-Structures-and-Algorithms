// Time Complexity O(n)
// Space Complexity O(n)
const validBST = (root) => {
    if (!root){
        return false
    }
    return dfs(root, -Infinity, Infinity)
}

const dfs = (node, min, max) => {
    if (node.value <= min || node.value >= max){
        return false
    }

    if (node.left) {
        if (!dfs(node.left, min, node.value)){
            return false
        }
    }

    if (node.right){
        if (!dfs(node.right, node.value, max)){
            return false
        }
    }

    return true
}