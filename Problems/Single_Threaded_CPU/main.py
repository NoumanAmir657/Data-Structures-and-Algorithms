class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        tasks = list(enumerate(tasks))
        tasks = sorted(tasks, key=lambda x: x[1][0])
        time = tasks[0][1][0]
        minHeap = []
        heapq.heappush(minHeap, (tasks[0][1][1], tasks[0][0], tasks[0][1][0]))

        res = []
        i = 1

        while i < len(tasks):
            if tasks[i][1][0] == time:
                heapq.heappush(minHeap, (tasks[i][1][1], tasks[i][0], tasks[i][1][0]))
                i += 1
            else:
                break


        while i < len(tasks):
            processTime, index, startTime = heapq.heappop(minHeap)
            res.append(index)
            time += processTime

            while i < len(tasks):
                if tasks[i][1][0] > time:
                    break
                heapq.heappush(minHeap, (tasks[i][1][1], tasks[i][0], tasks[i][1][0]))
                i += 1
            
            if i < len(tasks) and len(minHeap) == 0:
                time = tasks[i][1][0]
                while i < len(tasks):
                    if tasks[i][1][0] > time:
                        break
                    heapq.heappush(minHeap, (tasks[i][1][1], tasks[i][0], tasks[i][1][0]))
                    i += 1
        
        while minHeap:
            processTime, index, startTime = heapq.heappop(minHeap)
            res.append(index)
        return res
