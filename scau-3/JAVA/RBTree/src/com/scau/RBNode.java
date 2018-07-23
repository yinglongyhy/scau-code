package com.scau;

public class RBNode<T /*extends Comparable<T> */> {
    private boolean color;//true为红节点，false为黑节点
    private T data;//数据
    private RBNode<T> lchild;//左孩子
    private RBNode<T> rchild;//右孩子
    private RBNode<T> father;//父节点


    public RBNode(T data) {
        this.color = true;
        this.data = data;
        this.lchild = null;
        this.rchild = null;
        this.father = null;
    }

    public boolean isColor() {
        return color;
    }

    public void setColor(boolean color) {
        this.color = color;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public RBNode<T> getLchild() {
        return lchild;
    }

    public void setLchild(RBNode<T> lchild) {
        this.lchild = lchild;
    }

    public RBNode<T> getRchild() {
        return rchild;
    }

    public void setRchild(RBNode<T> rchild) {
        this.rchild = rchild;
    }

    public RBNode<T> getFather() {
        return father;
    }

    public void setFather(RBNode<T> father) {
        this.father = father;
    }
}
