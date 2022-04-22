const findMST = (graph) => {
    let noOfEdges = 0;
    const sizeOfV = graph.length 
    const selectedVertices = new Array(sizeOfV).fill(false)

    // start from any vertex, we choose 0 here
    selectedVertices[0] = true

    let row;
    let col;

    // number of edges in minimum spanning tree will be always less than V-1

    while(noOfEdges < sizeOfV - 1){
        let min = Infinity
        row = 0
        col = 0

        for (let i = 0; i < sizeOfV; i++){
            if (selectedVertices[i]){
                for (let j = 0; j < sizeOfV; ++j){
                    if (!selectedVertices[j] && graph[i][j]) {
                        if (min > graph[i][j]){
                            min = graph[i][j]
                            row = i
                            col = j
                        }
                    }
                }
            }
        }
        console.log(row, "-", col, ":", graph[row][col])
        selectedVertices[col] = true
        noOfEdges++
    }
}

const graph = [
    [0,4,4,0,0,0],
    [4,0,2,0,0,0],
    [4,2,0,0,2,0],
    [0,0,3,0,0,3],
    [0,0,2,0,0,3],
    [0,0,0,3,3,0]
]

findMST(graph)

