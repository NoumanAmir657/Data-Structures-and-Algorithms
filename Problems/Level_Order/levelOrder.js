class TreeNode {
    constructor(value) {
      this.value = value;
      this.left = null;
      this.right = null;
    }
  
    insert(values) {
      const queue = [this];
      let i = 0;
      while (queue.length > 0) {
        let current = queue.shift();
        for (let side of ["left", "right"]) {
          if (!current[side]) {
            if (values[i] !== null) {
              current[side] = new TreeNode(values[i]);
            }
            i++;
            if (i >= values.length) return this;
          }
          if (current[side]) queue.push(current[side]);
        }
      }
      return this;
    }
  }
  
const tree = new TreeNode(3);
tree.insert([6,1,9,2,null,4,null,5,null,null,null,null,8,null,null,null]);

const levelOrder = (root) => {
    if (!root){
        return []
    }

    const result = []
    const q = [root]

    while (q.length){
      let length = q.length, count = 0;
      const currentValues = []

      while (count < length){
        const currenNode = q.shift()
        currentValues.push(currenNode.value)
        if (currenNode.left){
          q.push(currenNode.left)
        }
        if (currenNode.right){
          q.push(currenNode.right)
        }
        ++count
      }
      result.push(currentValues)
    }
    return result
}

console.log(levelOrder(tree))