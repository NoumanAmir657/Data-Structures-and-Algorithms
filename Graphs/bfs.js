const bfs = (graph) => {
    const q = []
    q.push(0)
    const result = []

    while (q.length) {
        const currentVertex = q.shift()
        result.push(currentVertex)
        
        const neighbours = graph[currentVertex]
        for (let i = 0; i < neighbours.length; ++i) {
            if (!(result.find(x => x === neighbours[i])) && neighbours[i] != 0){
                q.push(neighbours[i])
            }
        }
    }

    return result
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
console.log(bfs(graph))