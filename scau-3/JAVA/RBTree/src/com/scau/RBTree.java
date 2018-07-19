package com.scau;

public class RBTree<T> {
    private RBNode<T> root;//树的根节点

    public RBNode<T> getRoot() {
        return root;
    }

    public void setRoot(RBNode<T> root) {
        this.root = root;
    }

}
