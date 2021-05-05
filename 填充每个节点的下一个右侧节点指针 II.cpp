q.push(root);
while(!q.empty()) {
    int n = q.size();
    for (int i = 1; i <= n; ++i) {
        auto f = q.front();
        q.pop();
        // 拓展新节点
        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
        // ... 遍历当前取出的 f
    }
}
