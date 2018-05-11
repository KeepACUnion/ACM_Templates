/*******左偏树模板,pop,push等功能自行实现**********/
struct Heap{
    int l, r, v, d;
} heap[maxn];

int Merge(int x, int y){
    if(!x || !y) return x+y;
    ///大根堆
    ///if(heap[x].v < heap[y].v) swap(x,y);

    ///小根堆
    ///if(headp[x].v > heap[y].v) swap(x,y);

    heap[x].r = Merge(heap[x].r, y);

    ///保持左端深度更大
    if(heap[heap[x].l].d < heap[heap[x].r].d)
        swap(heap[x].l, heap[x].r);
    heap[x].d = heap[heap[x].r].d + 1;

    return x;
}
