const topologicalSort = (adjList) => {
    const stack = []
    const seen = new Set()

    for (let i = 0; i < adjList.length; ++i) {
        if (!seen.has(i)) {
            const startIndex = i
            topologicalUtil(adjList, i, seen, stack)
        }
    }

    while (stack.length) {
        console.log(stack.pop())
    }
}

const topologicalUtil = (adjList, node, seen, stack) => {
    seen.add(node)
    const neighbours = adjList[node]

    for (let i = 0; i < neighbours.length; ++i) {
        if (!seen.has(neighbours[i])){
            topologicalUtil(adjList, neighbours[i], seen, stack)
        }
    }
    stack.push(node)
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