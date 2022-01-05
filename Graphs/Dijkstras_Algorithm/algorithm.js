const constructadjMatrix = (graph) => {
    const adjMatrix = new Array(5).fill(0).map(x => x = [])
    for (let i = 0; i < adjMatrix.length; ++i){
        adjMatrix[i] = new Array(5).fill(0)
    }
    for (let i = 0; i < graph.length; ++i) {
        adjMatrix[graph[i][0] - 1][graph[i][1] - 1] = graph[i][2]
    }
    return adjMatrix
}

const minTime = (timeArray, seen) => {
    let minIndex = 0
    let minVal = Infinity

    for (let i = 0; i < timeArray.length; ++i){
        if (timeArray[i] < minVal && !seen[i]){
            minIndex = i
            minVal = timeArray[i]
        }
    }
    return minIndex    
}

const totalTime = (graph, adjMatrix, k) => {
    const timeArray = new Array(5).fill(0).map(x => x = Infinity)
    timeArray[k] = 0
    const seen = {}

    while(k >= 0){
        const neighbours = adjMatrix[k]
        for (let i = 0; i < neighbours.length; ++i){
            if (neighbours[i] > 0){
                if ((timeArray[k] + neighbours[i]) < timeArray[i]){
                    timeArray[i] = timeArray[k] + neighbours[i]
                }
            }
        }
        seen[k] = true

        //find minimum time in timeArray and use its index
        k = minTime(timeArray, seen)
        if (seen[k]){k = -1}
    }
    return timeArray
}

const graph = [
    [1,2,9],[1,4,2],[2,5,1],[4,2,4],[4,5,6],[3,2,3],[5,3,7],[3,1,5]
]

const adjMatrix = constructadjMatrix(graph)
console.log(adjMatrix)
const k = 0
console.log(totalTime(graph, adjMatrix, k))
