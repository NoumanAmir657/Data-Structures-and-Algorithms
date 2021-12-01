const topologicalSort = (adjList) => {
    const inDegree = getInDegree(adjList)
    const stack = []
    const sorted = []

    for (let i = 0; i < inDegree.length; ++i){
        if (inDegree[i] === 0){
            stack.push(i)
        }
    }
    
    while (stack.length) {
        const current = stack.pop()
        console.log(current)
        const neighbours = adjList[current]

        for (let j = 0; j < neighbours.length; ++j) {
            inDegree[neighbours[j]]--
            if (inDegree[neighbours[j]] === 0){
                stack.push(neighbours[j])
            }
        }
    }
}

const getInDegree = (adjList) => {
    const inDegree = new Array(adjList.length).fill(0)
    // make inDegree array
    for (let i = 0; i < adjList.length; ++i) {
        const nodes = adjList[i]
        for (let j = 0; j < nodes.length; ++j) {
            inDegree[nodes[j]]++
        }
    }
    return inDegree
}

const adjList = [
    [1],
    [2],
    [],
    [0,4],
    [],
    [2,3,4]
]

topologicalSort(adjList)