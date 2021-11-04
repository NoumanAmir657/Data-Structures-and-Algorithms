const dfs = (vertex, graph, values, seen) => {
    values.push(vertex)
    seen[vertex] = true

    const neighbours = graph[vertex]
    for (let i = 0; i < neighbours.length; ++i) {
        const neightbour = neighbours[i]

        if (!seen[neightbour]) {
            dfs(neightbour, graph, values, seen)
        }
    }
}

const dfsHelper = (graph) => {
    const seen = {}
    const values = []
    dfs(0, graph, values, seen)
    console.log(values)
}

const graph = [
    [1, 3],
    [0],
    [3,8],
    [0,2,4,5],
    [3,6],
    [3],
    [4,7],
    [6],
    [2]
]

dfsHelper(graph)