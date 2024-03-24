#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int         N = 400005;
typedef long long LL;
int               rt[N], tot, fa[N], ch[N][2], cnt[N], sz[N]; // cnt[i]表示此节点val值的个数，记录重复  sz[i]表示以i为根的子树的大小
LL                val[N];
int               n, q;
struct Splay {
    void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; } // 更新子树大小

    bool get(int x) { return x == ch[fa[x]][1]; } // 判断x是左还是右儿子

    void clear(int x) { // 销毁节点x
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }

    void rotate(int x) { // 左旋or右旋
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if (ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y]          = x;
        fa[x]          = z;
        if (z) ch[z][y == ch[z][1]] = x;
        maintain(y);
        maintain(x);
    }

    void splay(int x, int i) { // splay操作
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f]) rotate(get(x) == get(f) ? f : x);
        rt[i] = x;
    }

    void ins(int k, int i) { // 在rt[i]为根的子树中插入value为k的节点
        if (!rt[i]) {
            val[++tot] = k;
            cnt[tot]++;
            rt[i] = tot;
            maintain(rt[i]);
            return;
        }
        int cur = rt[i], f = 0;
        while (1) {
            if (val[cur] == k) {
                cnt[cur]++;
                maintain(cur);
                maintain(f);
                splay(cur, i);
                break;
            }
            f   = cur;
            cur = ch[cur][val[cur] < k];
            if (!cur) {
                val[++tot] = k;
                cnt[tot]++;
                fa[tot]           = f;
                ch[f][val[f] < k] = tot;
                maintain(tot);
                maintain(f);
                splay(tot, i);
                break;
            }
        }
    }

    void train(int k, int i) // 递归训练
    {
        if (!i) return;
        val[i] += k;
        train(k, ch[i][0]);
        train(k, ch[i][1]);
    }

    void merge(int c1, int c2) // 合并，把以rt[c1]为根的子树合并到rt[c2]上，通过递归插入的方式
    {
        if (!c1) return;
        merge(ch[c1][0], c2);
        while (cnt[c1]--)
            ins(val[c1], c2);
        merge(ch[c1][1], c2);
    }
    int rk(int k, int i) { // 查找第i棵子树中value值为k的排名
        int res = 0, cur = rt[i];
        while (1) {
            if (k < val[cur]) {
                cur = ch[cur][0];
            } else {
                res += sz[ch[cur][0]];
                if (k == val[cur]) {
                    splay(cur, i);
                    return res + 1;
                }
                res += cnt[cur];
                cur = ch[cur][1];
            }
        }
    }

    int kth(int k, int i) { // 查找第i棵子树中排名为k的value
        int cur = rt[i];
        while (1) {
            if (ch[cur][0] && k <= sz[ch[cur][0]]) {
                cur = ch[cur][0];
            } else {
                k -= cnt[cur] + sz[ch[cur][0]];
                if (k <= 0) {
                    splay(cur, i);
                    return val[cur];
                }
                cur = ch[cur][1];
            }
        }
    }

    int pre(int i) { // 找前驱节点
        int cur = ch[rt[i]][0];
        if (!cur) return cur;
        while (ch[cur][1]) cur = ch[cur][1];
        splay(cur, i);
        return cur;
    }

    int nxt(int i) { // 找后继节点
        int cur = ch[rt[i]][1];
        if (!cur) return cur;
        while (ch[cur][0]) cur = ch[cur][0];
        splay(cur, i);
        return cur;
    }

    void del(int k, int i) { // 删除第i棵子树中value为k的节点
        rk(k, i);
        if (cnt[rt[i]] > 1) {
            cnt[rt[i]]--;
            maintain(rt[i]);
            return;
        }
        if (!ch[rt[i]][0] && !ch[rt[i]][1]) {
            clear(rt[i]);
            rt[i] = 0;
            return;
        }
        if (!ch[rt[i]][0]) {
            int cur   = rt[i];
            rt[i]     = ch[rt[i]][1];
            fa[rt[i]] = 0;
            clear(cur);
            return;
        }
        if (!ch[rt[i]][1]) {
            int cur   = rt[i];
            rt[i]     = ch[rt[i]][0];
            fa[rt[i]] = 0;
            clear(cur);
            return;
        }
        int cur        = rt[i];
        int x          = pre(i);
        fa[ch[cur][1]] = x;
        ch[x][1]       = ch[cur][1];
        clear(cur);
        maintain(rt[i]);
    }

} tree;

int main() {
    scanf("%d%d", &n, &q);
    while (q--) {
        int opt, c1, c2;
        cin >> opt;
        if (opt == 1) // 造船
        {
            cin >> c1 >> c2;
            tree.ins(c2, c1);
        } else if (opt == 2) // 训练
        {
            cin >> c1 >> c2;
            tree.train(c2, rt[c1]);
        } else if (opt == 3) // 移动
        {
            cin >> c1 >> c2;
            if (!rt[c1])
                continue;
            else {
                int rank;
                if (sz[rt[c1]] % 2 == 0)
                    rank = sz[rt[c1]] >> 1;
                else
                    rank = (sz[rt[c1]] >> 1) + 1;
                int a = tree.kth(rank, c1);
                tree.ins(a, c2);
                tree.del(a, c1);
            }
        } else if (opt == 4) // 查询
        {
            cin >> c1;
            if (!rt[c1])
                puts("0");
            else {
                int rank;
                if (sz[rt[c1]] % 2 == 0)
                    rank = sz[rt[c1]] >> 1;
                else
                    rank = (sz[rt[c1]] >> 1) + 1;
                int a = tree.kth(rank, c1);
                printf("%d\n", a);
            }
        }

        else if (opt == 5) // 合并  如果c1的节点数比c2少，中序遍历c1插入到c2里面，否则将c1的左右孩子分别与c2的左右孩子交换，然后中序遍历c1插入到c2里面
        {
            cin >> c1 >> c2;
            // if(sz[rt[c2]]>=sz[rt[c1]])   //不考虑启发式合并，使用if中的语句只会有两个点超时，但是考虑启发式之后，几乎都超时了,
            //{
            tree.merge(rt[c1], c2);
            tree.clear(rt[c1]);
            rt[c1] = 0;
            //}
            /*else
            {//如果c1舰队的数量多，则将遍历C2的splay树，插入到C1中，然后拷贝C1树给C2，包括两棵树的孩子节点的互换，以及C2根节点的val、cnt、sz均由C1树根节点的三者更新
                tree.merge(rt[c2],c1);
                int tmp1=ch[rt[c2]][0],tmp2=ch[rt[c2]][1];
                ch[rt[c2]][0]=ch[rt[c1]][0];
                ch[rt[c2]][1]=ch[rt[c1]][1];
                fa[ch[rt[c2]][0]]=rt[c2];
                fa[ch[rt[c2]][1]]=rt[c2];
                ch[rt[c1]][0]=tmp1;
                ch[rt[c1]][1]=tmp2;
                fa[tmp1]=rt[c1];
                fa[tmp2]=rt[c1];
                val[rt[c2]]=val[rt[c1]];
                cnt[rt[c2]]=cnt[rt[c1]];
                sz[rt[c2]]=sz[rt[c1]];
                tree.clear(rt[c1]);
                rt[c1]=0;
            }*/
        }
        /* else     //删除value值不超过c2的节点：方法 先插入value为c2的节点（插入节点会splay到根），然后判断右子树是否存在，如果存在就让右子树作为根，r
         {
             cin >> c1 >> c2;
             tree.ins(c2,c1);
             int cur=rt[c1];
             if(ch[rt[c1]][0]) fa[ch[rt[c1]][0]]=0;
             if(ch[rt[c1]][1])
             {
             rt[c1]=ch[rt[c1]][1];
             fa[rt[c1]]=0;
             }
             tree.clear(cur);
         }
         */
        else {
            cin >> c1 >> c2;
            tree.ins(c2, c1);
            if (ch[rt[c1]][0]) {
                sz[rt[c1]] -= sz[ch[rt[c1]][0]];
                ch[rt[c1]][0] = 0;
            }
            tree.del(c2, c1);
        }
    }
    return 0;
}