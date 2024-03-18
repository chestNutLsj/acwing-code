void merge_sort(int q[], int l, int r) {
    if (l >= r) return; // 递归基

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r); // 递归

    int k = 0, i = l, j = mid + 1; // k用于计数已经完成了多少个合并，i和j分别表示左右边界
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];

    while (i <= mid) tmp[k++] = q[i++]; // 有剩余元素的话直接接到末尾
    while (j <= r) tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}