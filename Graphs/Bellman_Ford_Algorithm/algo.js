const bellmanFordAlgo = (graph, k) => {
    const distanceArray = new Array(6).fill(0).map(x => x = Infinity)
    distanceArray[k] = 0
    //iterate over edges n-1 times
    for (let i = 0; i < graph.length - 1; ++i){
        for (let j = 0; j < graph.length; ++j){
            if (distanceArray[graph[j][0]] + graph[j][2] < distanceArray[graph[j][1]]){
                distanceArray[graph[j][1]] = distanceArray[graph[j][0]] + graph[j][2]
            }
        }
    }
    return distanceArray
}

const graph = [
    [1,2,9],[1,4,2],[2,5,1],[4,2,4],[4,5,6],[3,2,3],[5,3,7],[3,1,5]
]

console.log(bellmanFordAlgo(graph, 1))