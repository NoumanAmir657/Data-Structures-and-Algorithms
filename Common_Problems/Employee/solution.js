const createAdjList = (n, managers, headId) => {
    const adjList = []
    for (let i = 0; i < n; ++i) {
        const tempList = []
        for (let j = 0; j < n; ++j){
            if (managers[j] == i){
                tempList.push(j)
            }
        }
        adjList.push(tempList)
    }
    return adjList
}

const timeTaken = (infoTime, headId, adjList) => {
    let time = infoTime[headId]
    const q = []
    let max = 0
    
    for (let i = 0; i < adjList[headId].length; ++i){
        q.push((adjList[headId])[i])
    }

    while(q.length) {
        const neightboursSize = q.length
        for (let i = 0; i < neightboursSize; ++i){
            const currentVertex = q.shift()
            if (time + infoTime[currentVertex] > max){
                max = time + infoTime[currentVertex]
            }
            for (let j = 0; j < adjList[currentVertex].length; ++j){
                q.push((adjList[currentVertex])[j])
            }
        }
        time = max
        max = 0
    }
    return time
}

const n = 8
const headId = 4
const managers = [2,2,4,6,-1,4,4,5]
const infoTime = [0,0,4,0,7,3,6,0]
const adjList = createAdjList(n, managers, headId)
console.log(timeTaken(infoTime, headId, adjList))

/*
const n = 8
const headId = 4
const managers = [2,2,4,6,-1,4,4,5]
const infoTime = [0,0,4,0,7,3,6,0]

const n = 7
const headId = 6
const managers = [1,2,3,4,5,6,-1]
const infoTime = [0,6,5,4,3,2,1]
*/