package com.scau;

public class RBTree<T extends Comparable<T>> {

    private RBNode<T> root; // 根节点
    final private static boolean RED = true; // 定义红色为true
    final private static boolean BLACK = false; // 定义黑色为false

    //内部类：树的节点
    private class RBNode<T extends Comparable<T>> {
        private boolean color; // true为红， false为黑
        private T data; // 数据域
        private RBNode<T> lchild; // 左孩子
        private RBNode<T> rchild; // 右孩子
        private RBNode<T> father; // 父节点

        public RBNode(T data) {
            this.color = RED; // 默认新节点为红色
            this.data = data;
            this.lchild = null;
            this.rchild = null;
            this.father = null;
        }
    }

    public RBTree() {
        this.root = null;
    }

    public RBNode<T> getRoot() {
        return this.root;
    }

    public boolean isRed(RBNode<T> node) {
        return node != null && node.color != BLACK;
    }

    public boolean isBlack(RBNode<T> node) {
        return node == null || node.color == BLACK;
    }

    public void setRed(RBNode<T> node) {
        if (node != null) node.color = RED;
    }

    public void setBlack(RBNode<T> node) {
        if (node != null) node.color = BLACK;
    }

    private RBNode<T> getFather(RBNode<T> node) {
        return node == null || node.father == null ? null : node.father;
    }

    public RBNode<T> getUncle(RBNode<T> node) {
        RBNode<T> father = getFather(node);
        RBNode<T> grandfather = getFather(father);
        if (father == null || grandfather == null) return null;
        return grandfather.lchild == father ? grandfather.rchild : grandfather.lchild;
    }

    public void liftRotate(RBNode<T> node) {
        /*
        1 设newPivot保存node的右子节点
        2 node的右子节点指向newPivot的左子节点，newPivot的左子节点（若不为空）的父节点指向node
        3 newPivot的左子节点指向node
        4 newPivot的父节点指向node的父节点，node的父节点的左/右子节点指向newPivot
        5 node的父节点指向newPivot
        6 判断newPivot的父节点是否为null，是 设newPivot为根节点
         */
        RBNode<T> newPivot = node.rchild;
        node.rchild = newPivot.lchild;
        if (node.rchild != null) newPivot.lchild.father = node;
        newPivot.rchild = node;
        newPivot.father = node.father;
        if ((node.father.lchild == node)) {
            node.father.lchild = newPivot;
        } else {
            node.father.rchild = newPivot;
        }
        node.father = newPivot;
        if (newPivot.father == null) this.root = newPivot;
    }

    public void rightRotate(RBNode<T> node) {
        /*
        1 设newPivot保存node的左子节点
        2 node的左子节点指向newPivot的右子节点，newPivot的右子节点（若不为空）的父节点指向node
        3 newPivot的右子节点指向node
        4 newPivot的父节点指向node的父节点，node的父节点的左/右子节点指向newPivot
        5 node的父节点指向newPivot
        6 判断newPivot的父节点是否为null，是 设newPivot为根节点
         */
        RBNode<T> newPivot = node.lchild;
        node.lchild = newPivot.rchild;
        if (newPivot.rchild != null) newPivot.rchild.father = node;
        newPivot.rchild = node;
        newPivot.father = node.father;
        if ((node.father.lchild == node)) {
            node.father.lchild = newPivot;
        } else {
            node.father.rchild = newPivot;
        }
        node.father = newPivot;
        if (newPivot.father == null) this.root = newPivot;
    }

    public void addNode(T data) {
        RBNode<T> newNode = new RBNode<>(data);
        RBNode<T> compareNode = this.root;
        RBNode<T> compareNodePre = compareNode;
        while (compareNode != null) {
            compareNodePre = compareNode;
            compareNode = compareNode.data.compareTo(newNode.data) > 0 ? compareNode.lchild : compareNode.rchild;
        }
        if (compareNodePre == null) this.root = newNode;
        else {
            if (compareNodePre.data.compareTo(newNode.data) > 0) { // newNode 小，插在compareNodePro的左子节点
                compareNodePre.lchild = newNode;
            } else {
                compareNodePre.rchild = newNode;
            }
            newNode.father = compareNodePre;
        }
        //插入完毕，下面插入修正
        addFixUp(newNode);
    }

    public void addFixUp(RBNode<T> node) {
        RBNode<T> father = getFather(node);
        RBNode<T> uncle = getUncle(node);
        if (isRed(father) && isRed(uncle)) {
            setBlack(father);
            setBlack(uncle);
            setRed(getFather(father));
            node = getFather(father);
        }
        father = getFather(node);
        uncle = getUncle(node);
    }

    public void todo() {

    }
}


