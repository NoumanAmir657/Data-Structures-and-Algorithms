const findMedianSortedArrays = (nums1, nums2) => {
    const size = nums1.length + nums2.length
    let median = 0;
    let p1 = 0;
    let p2 = 0;
    let count = 0;
    const medianIndex = Math.floor(size / 2);
    const merged  = []

    while(p1 < nums1.length && p2 < nums2.length && count <= medianIndex){
        if (nums1[p1] < nums2[p2]){
            merged.push(nums1[p1])
            p1++
        }
        else {
            merged.push(nums2[p2])
            p2++
        }
        ++count
    }

    while(p1 < nums1.length && count <= medianIndex){
        merged.push(nums1[p1])
        ++p1
        ++count
    }

    while(p2 < nums2.length && count <= medianIndex){
        merged.push(nums2[p2])
        ++p2
        ++count
    }

    if (size % 2 === 0) {
        median = (merged.pop() + merged.pop()) / 2
    }
    else {
        median = merged.pop()
    }

    return median
}

console.log(findMedianSortedArrays([], [2]))