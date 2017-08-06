/**
 * 堆排序：
 * 构建最小二叉堆：一个完全二叉树，子节点小于父节点。
    - 从下向上进行递归构建。
    - 首先找到最后一个非叶子节点：(len - 1) / 2
    - 然后慢慢向上递归构建
    - 对于每一个节点，构建的过程都要从上到下直到叶子节点。
*/


// 调整二叉堆，使root为根节点所在的树为最大堆
void AdjustHeap(int* data, int len, int root) {
    
    // 对于完全二叉树，最后一个非叶子节点的左节点一定存在
    int left, maxChild;
    left = root * 2 + 1;

    // 对于每一个节点的调整，由上至下
    while(left < len) {

        // 寻找较大子节点(需要判断右节点是否存在)
        if((left+1) <= (len-1) && data[left+1] > data[left]) {
            maxChild = left + 1;
        } 
        else {
            maxChild = left;
        }

        // 交换父节点和较大的子节点，使得父节点大于左右子节点  
        if( data[root] < data[maxChild]) {
            std::swap(data[root], data[maxChild]);

            // 继续向下调整
            root = maxChild;
            left = root * 2 + 1;
        } 
        else {
            // 如果root节点不需要调整，root节点下面都是调整好了的，也就不需要再调整了
            break;
        }
    }
}


// 利用数组建立二叉堆
void BuildHeap(int* data, int len) {

    // 从最后一个非叶子节点开始调整
    for(int root = (len - 1) / 2; root >= 0; root--) {
        AdjustHeap(data, len, root);
    }
}

void HeapSort(int* data, int len) {

    // 建立一个最大堆
    BuildHeap(data, len);

    for(int i = len; i >= 1; i--) {
        swap(a[0], a[i-1]);
        // 重新调整堆
        AdjustHeap(data, len, 0);
    }
}