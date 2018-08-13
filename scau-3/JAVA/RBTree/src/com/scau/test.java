package com.scau;

public class test {
    public static void main(String[] args) {
        RBTree<Integer> root = new RBTree<>();
        int[] nums = {10, 40, 30, 60, 90, 70, 20, 50, 80, 0, 100, 45};
        for (int i = 0; i < nums.length; i++) {
            root.addNode(nums[i]);

            System.out.println();
            root.preTraversal(root.getRoot());
            System.out.println();
            root.inTraversal(root.getRoot());
            System.out.println();
            root.postTraversal(root.getRoot());
            System.out.println();
            root.showLChild(root.getRoot());
            root.showRChild(root.getRoot());
            System.out.println();
            root.getMax(root.getRoot());
            root.getMin(root.getRoot());
            root.find(100);
        }
        root.removeNode(50);
        root.removeNode(60);
        root.removeNode(80);
        System.out.println();
        root.preTraversal(root.getRoot());
        System.out.println();
        root.inTraversal(root.getRoot());
        System.out.println();
        root.postTraversal(root.getRoot());
        System.out.println();
        root.showRoot();
        root.showLChild(root.getRoot());
        root.showRChild(root.getRoot());
        System.out.println();
        root.getMax(root.getRoot());
        root.getMin(root.getRoot());
        root.find(100);
    }
    /**
     * 问题：左孩子缺失
     * 推断：1、左右旋出问题
     *      2、插入出问题
     */
}
