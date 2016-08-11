//segment tree
//not written by myself, just copied
#define LEFT(u) u << 1
#define RIGHT(u) u << 1 | 1
#define MID(l,r) (l+r) >> 1
#define MAXN 20010

struct SegNode {
    int left, right, height, maxheight;
    bool lazy;
}nodes[MAXN << 2];

struct SegTree {
    void build(int left, int right, int u) {
        nodes[u].left = left;
        nodes[u].right = right;
        nodes[u].height = 0;
        nodes[u].maxheight = 0;
        nodes[u].lazy = false;
        if (left + 1 == right) return;
        build(left, MID(left, right), LEFT(u));
        build(MID(left, right), right, RIGHT(u));
    }

void pushDown(int u) {
    if (nodes[u].left + 1 == nodes[u].right) return;
    
    nodes[u].lazy = false;
    
    if (nodes[LEFT(u)].height < nodes[u].height) {
        nodes[LEFT(u)].height = nodes[u].height;
        nodes[LEFT(u)].lazy = true;
    }
    
    if (nodes[RIGHT(u)].height < nodes[u].height) {
        nodes[RIGHT(u)].height = nodes[u].height;
        nodes[RIGHT(u)].lazy = true;
    }
    
    nodes[LEFT(u)].maxheight = max(nodes[LEFT(u)].maxheight, nodes[LEFT(u)].height);
    nodes[RIGHT(u)].maxheight = max(nodes[RIGHT(u)].maxheight, nodes[RIGHT(u)].height);
}

void insert(int left, int right, int height, int u) {
    if (nodes[u].left == left && nodes[u].right == right) {
        if (nodes[u].height < height) {
            nodes[u].height = height;
            nodes[u].maxheight = max(nodes[u].maxheight, height);
            nodes[u].lazy = true;
        }
        return;
    }
    
    if (nodes[u].lazy)
        pushDown(u);
    int mid = MID(nodes[u].left, nodes[u].right);
    if (mid >= right) {
        insert(left, right, height, LEFT(u));
    }
    else if (mid <= left) {
        insert(left, right, height, RIGHT(u));
    }
    else {
        insert(left, mid, height, LEFT(u));
        insert(mid, right, height, RIGHT(u));
    }
    
    nodes[u].maxheight = max(nodes[u].maxheight, height);
}

int query(int left, int& right, int u) {
    if (nodes[u].lazy) {
        pushDown(u);
    }
    
    if (nodes[u].left == left && nodes[u].maxheight == nodes[u].height) {
        right = nodes[u].right;
        return nodes[u].height;
    }
    
    int mid = MID(nodes[u].left, nodes[u].right);
    
    if (mid > left) {
        return query(left, right, LEFT(u));
    }
    else {
        return query(left, right, RIGHT(u));
    }
}
};

class Solution {
public:
map<int, int> m;
vector<int> aux;
vector<vector<int>> discrete(vector<vector<int>>& buildings){
    vector<vector<int>> ret;
    set<int> vec;
    for(auto itm : buildings){
        vec.insert(itm[0]);
        vec.insert(itm[1]);
    }
    aux.assign(vec.begin(), vec.end());
    for(int i = 0; i < aux.size(); i ++){
        m[aux[i]] = i;
    }
    
    for(auto itm : buildings){
        vector<int> v;
        v.push_back(m[itm[0]]);
        v.push_back(m[itm[1]]);
        v.push_back(itm[2]);
        ret.push_back(v);
    }
    return ret;
}

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> ret;
    if (buildings.empty()) return ret;
    
    SegTree st;
    st.build(0, 20010, 1);
    
    int left = 20010, right = -1;
    
    vector<vector<int>> build = discrete(buildings);
    
    for (auto v : build) {
        st.insert(v[0], v[1], v[2], 1);
        left = min(left, v[0]);
        right = max(right, v[1]);
    }
    
    int x;
    int height = st.query(left, x, 1);
    ret.push_back(make_pair(aux[left], height));
    
    while (x <= right) {
        int tmp;
        left = x;
        while (x <= right && (tmp = st.query(left, x, 1)) == height) {
            left = x;
        }
        height = tmp;
        ret.push_back(make_pair(aux[left], height));
    }
    
    return ret;
}
};